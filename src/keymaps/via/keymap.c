// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ A │ B │ C │
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * ├───┼───┼───┤
     * │ G │ H │ I │
     * └───┴───┴───┘
     */
    [0] = LAYOUT_ortho_3x3(
        KC_A,    KC_B,    KC_C,
        KC_D,    KC_E,    KC_F,
        KC_G,    KC_H,    KC_I
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
        // Capa 1: Azul
        rgblight_sethsv_at(170, 255, 200, 0);
        break;
    case 2:
        // Capa 2: Rojo
        rgblight_sethsv_at(0, 255, 200, 0);
        break;
    case 3:
        // Capa 3: Verde
        rgblight_sethsv_at(85, 255, 200, 0);
        break;
    default: // Capa 0
        // Capa 0: cyan
        rgblight_sethsv_at(128, 255, 200, 0);
        break;
    }
    return state;
}
