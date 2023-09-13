// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
    TD_BOOT,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_BOOT] = ACTION_TAP_DANCE_DOUBLE(XXXXXXX, QK_BOOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │Bsp│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Tab│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ ; │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Ctl│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ' │Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ ↑ │Sft│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │App│GUI│Alt│ \ │ = │Spc│Spc│ - │ / │ ← │ ↓ │ → │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    // clang-format off
    [0] = LAYOUT_ortho_5x12(
        KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SCLN,
        KC_LCTL,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
        KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
        LT(1, KC_APP), KC_LGUI, KC_LALT, KC_BSLS, KC_EQL,  KC_SPC,  KC_SPC,  KC_MINS, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // clang-format on
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│Del│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Tab│F11│F12│F13│ R │ T │ Y │ U │ I │ [ │ ] │ ; │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │PgU│Sft│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │App│GUI│Alt│ \ │ = │Rst│Rst│ - │ / │Hom│PgD│End│
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    // clang-format off
    [1] = LAYOUT_ortho_5x12(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        KC_TAB,  KC_F11,  KC_F12,  KC_F13,  KC_R,    KC_T,        KC_Y,        KC_U,    KC_I,    KC_LBRC, KC_RBRC, KC_SCLN,
        _______, _______, _______, _______, _______, _______,     _______,     _______, _______, _______, _______, _______,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,        KC_M,    KC_COMM, KC_DOT,  KC_PGUP, KC_RSFT,
        KC_APP,  KC_RGUI, KC_RALT, KC_BSLS, KC_EQL,  TD(TD_BOOT), TD(TD_BOOT), KC_MINS, KC_SLSH, KC_HOME, KC_PGDN, KC_END
    )
    // clang-format on
};
