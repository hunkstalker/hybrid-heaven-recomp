#include <cstdlib>
#include <vector>

#ifdef _WIN32
#define SDL_MAIN_HANDLED
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#ifdef None
#undef None
#endif

#include "ultramodern/input.hpp"

#include "hh.h"

using n64_button = uint16_t;

enum N64Buttons : n64_button {
    A_BUTTON = 0x8000,
    B_BUTTON = 0x4000,
    Z_BUTTON = 0x2000,
    START_BUTTON = 0x1000,
    DUP_BUTTON = 0x800,
    DDOWN_BUTTON = 0x400,
    DLEFT_BUTTON = 0x200,
    DRIGHT_BUTTON = 0x100,
    L_BUTTON = 0x20,
    R_BUTTON = 0x10,
    CUP_BUTTON = 0x8,
    CDOWN_BUTTON = 0x4,
    CLEFT_BUTTON = 0x2,
    CRIGHT_BUTTON = 0x1,
};

static n64_button read_input_button() {
    n64_button input = 0;

    const Uint8* keyboard_state = SDL_GetKeyboardState(nullptr);
    const Uint32 mouse_state = SDL_GetMouseState(nullptr, nullptr);

    if (keyboard_state[SDL_SCANCODE_UP]) input |= DUP_BUTTON;
    if (keyboard_state[SDL_SCANCODE_DOWN]) input |= DDOWN_BUTTON;
    if (keyboard_state[SDL_SCANCODE_LEFT]) input |= DLEFT_BUTTON;
    if (keyboard_state[SDL_SCANCODE_RIGHT]) input |= DRIGHT_BUTTON;

    if (keyboard_state[SDL_SCANCODE_S]) input |= A_BUTTON;
    if (keyboard_state[SDL_SCANCODE_X]) input |= B_BUTTON;
    if (keyboard_state[SDL_SCANCODE_Z]) input |= Z_BUTTON;
    if (keyboard_state[SDL_SCANCODE_C]) input |= L_BUTTON;
    if (keyboard_state[SDL_SCANCODE_V]) input |= R_BUTTON;
    if (keyboard_state[SDL_SCANCODE_RETURN]) input |= START_BUTTON;

    if (keyboard_state[SDL_SCANCODE_I]) input |= CUP_BUTTON;
    if (keyboard_state[SDL_SCANCODE_K]) input |= CDOWN_BUTTON;
    if (keyboard_state[SDL_SCANCODE_J]) input |= CLEFT_BUTTON;
    if (keyboard_state[SDL_SCANCODE_L]) input |= CRIGHT_BUTTON;

    if (mouse_state & SDL_BUTTON_LMASK) input |= A_BUTTON;
    if (mouse_state & SDL_BUTTON_RMASK) input |= B_BUTTON;

    return input;
}

static float controller_axis_to_float(Sint16 value) {
    return static_cast<float>(value) / 32768.0f;
}

void hh::poll_input() {
    SDL_Event event{};
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                SDL_Quit();
                std::exit(EXIT_SUCCESS);
                break;
            case SDL_CONTROLLERDEVICEADDED:
                if (SDL_IsGameController(event.cdevice.which)) {
                    SDL_GameControllerOpen(event.cdevice.which);
                }
                break;
            case SDL_CONTROLLERDEVICEREMOVED: {
                SDL_GameController* controller = SDL_GameControllerFromInstanceID(event.cdevice.which);
                if (controller != nullptr) {
                    SDL_GameControllerClose(controller);
                }
            } break;
        }
    }
}

bool hh::get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
    n64_button input = 0;
    if (controller_num == 0) {
        input = read_input_button();
    }

    float axis_x = 0.0f;
    float axis_y = 0.0f;

    if (SDL_NumJoysticks() > 0) {
        SDL_GameController* controller = SDL_GameControllerOpen(0);
        if (controller != nullptr) {
            if (controller_num == 0) {
                input |= n64_button(
                      SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) * A_BUTTON
                    | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) * B_BUTTON
                    | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_BACK) * Z_BUTTON
                    | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START) * START_BUTTON
                    | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) * DUP_BUTTON
                    | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) * DDOWN_BUTTON
                    | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) * DLEFT_BUTTON
                    | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) * DRIGHT_BUTTON
                    | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_LEFTSHOULDER) * L_BUTTON
                    | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) * R_BUTTON
                    | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y) * CUP_BUTTON
                    | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_LEFTSTICK) * CDOWN_BUTTON
                    | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X) * CLEFT_BUTTON
                    | SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B) * CRIGHT_BUTTON);
            }

            if (controller_num == 0) {
                axis_x = controller_axis_to_float(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX));
                axis_y = controller_axis_to_float(SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY));
            }
        }
    }

    *buttons = input;
    *x = axis_x;
    *y = axis_y;

    return true;
}

void hh::set_rumble(int controller_num, bool rumble) {
    (void)controller_num;
    (void)rumble;
}

ultramodern::input::connected_device_info_t hh::get_connected_device_info(int controller_num) {
    bool connected = false;
    if (controller_num == 0) {
        connected = SDL_NumJoysticks() > 0;
    }

    ultramodern::input::connected_device_info_t result{};
    result.connected_device = ultramodern::input::Device::None;
    result.connected_pak = ultramodern::input::Pak::None;

    if (connected) {
        result.connected_device = ultramodern::input::Device::Controller;
        result.connected_pak = ultramodern::input::Pak::None;
    }

    return result;
}