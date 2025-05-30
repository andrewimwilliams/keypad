// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#ifdef _WIN32
#include <windows.h>
#endif

enum custom_keycodes {
    BROWSER = SAFE_RANGE,
    CALC,
    MIC,
    MUTE,
};

void run(const char *command){
    register_code(KC_LGUI);
    tap_code(KC_R);
    unregister_code(KC_LGUI);
    wait_ms(100);

    send_string(command);
    tap_code(KC_ENTER);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed){
        switch (keycode) {
            case BROWSER:
                run("vivaldi");
                return false;
            case CALC:
                run("calc");
                return false;
            case MIC:
                run("C:\\Users\\Andrew Williams\\Downloads\\nircmd.exe mutesysvolume 2 microphone");
                return false;
            case MUTE:
                tap_code(KC_AUDIO_MUTE);
                return false;
        }
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_3x3(
        BROWSER,   CALC,   KC_3,
        KC_4,   KC_5,   KC_6,
        KC_7,   MIC,   MUTE
    )
};
