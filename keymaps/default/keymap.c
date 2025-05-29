// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    BROWSER = SAFE_RANGE,
    CALC,
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
        KC_7,   KC_8,   MUTE
    )
};