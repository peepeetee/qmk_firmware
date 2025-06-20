// Copyright 2023 peepeetee
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_1,   KC_2,   KC_3,
        KC_4,   KC_5,   KC_6
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0]   =  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) }

};
#endif
