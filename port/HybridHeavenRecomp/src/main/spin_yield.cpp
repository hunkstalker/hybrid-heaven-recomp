// Cede el turno de un hilo del juego que hace busy-wait (frame limiter FUN_80001454, 0x80001A88).
//
// El scheduler de libultra es preemptivo; el de ultramodern NO: solo reprograma y entrega los
// eventos externos (VI/SP/DP/PI/SI) dentro de osSendMesg/osRecvMesg/osJamMesg. Un hilo que hace
// busy-wait sin llamar a ninguna de esas funciones deja parados a los demas hilos y a los eventos
// externos (el contador de tareas RSP `0x8005CD4C` nunca drena y el bucle principal se salta el
// dispatcher). El frame limiter sondea osGetTime, que no cede.
//
// Este hook se inyecta en la cabecera de ese bucle y hace lo que haria la interrupcion de
// contador: entrega un mensaje externo pendiente (con espera acotada) y deja correr al hilo
// ejecutable de mayor prioridad. Mismo arreglo que el port de referencia (phase-04, tomado de
// Rayman 2: Recompiled, con espera de 1 ms en vez de poll caliente).
#include <cstdint>
#include <cstdlib>

#include "ultramodern/ultramodern.hpp"

namespace {
uint32_t hh_yield_ms() {
    static const uint32_t ms = [] {
        const char* v = std::getenv("HH_YIELD_MS");
        long p = v ? std::strtol(v, nullptr, 10) : 1;
        return static_cast<uint32_t>(p < 0 ? 0 : (p > 100 ? 100 : p));
    }();
    return ms;
}
}  // namespace

extern "C" void hh_yield_in_spin(uint8_t* rdram) {
    ultramodern::wait_for_external_message_timed(rdram, hh_yield_ms());
    ultramodern::check_running_queue(rdram);
}
