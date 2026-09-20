// Yield del busy-wait del frame limiter (FUN_80001454, 0x80001A88-0x80001B18). Sondea osGetTime
// sin ceder; bajo el scheduler cooperativo de ultramodern deja a los demas hilos del juego
// aparcados. Se cede el hilo 1 ms por iteracion via [[patches.hook]] en la config.
// Mismo arreglo que el port de referencia (phase-04, tomado de Rayman 2/Pilotwings 64).
// Ver notes/2026-09-20-pipeline-per-file-estado.md §14.
#include <chrono>
#include <thread>

extern "C" void hh_yield_in_spin() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
