/*
 *  Copyright (C) 2021  Vino Rodrigues (@vinorodrigues)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "v2.h"

#define __ NO_LED

#ifdef RGB_MATRIX_ENABLE

/*
 * Note: For the "ID67 Bestype" keyboard, define `ID67_IS_BESTYPE`
 * in your keymap `config.h` file to disable the underglow LED's.
 * ```
 * #define ID67_IS_BESTYPE
 * ```
 */
led_config_t g_led_config = { {
    // Key Matrix to LED Index
    {66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52},
    {51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37},
    {36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, __, 24, 23},
    {22, __, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10,  9},
    { 8,  7, __,  6, __, __,  5, __, __, __,  4,  3,  2,  1,  0}
}, {
    // LED Index to Physical Position
    // switch LEDs
    {218, 64}, {204, 64}, {190, 64}, {167, 64}, {149, 64},                                  {97, 64},                      {44, 64},           {26, 64}, {9, 64},
    {218, 50}, {204, 50}, {184, 50}, {165, 50}, {151, 50}, {138, 50}, {123, 50}, {109, 50}, {94, 50},  {80, 50}, {67, 50}, {53, 50}, {37, 50},           {16, 50},
    {218, 36}, {195, 36},            {172, 36}, {158, 36}, {144, 36}, {130, 36}, {116, 36}, {102, 36}, {88, 36}, {74, 36}, {60, 36}, {46, 36}, {32, 36}, {12, 36},
    {218, 22}, {200, 22}, {183, 22}, {169, 22}, {155, 22}, {141, 22}, {127, 22}, {113, 22}, {99, 22},  {85, 22}, {71, 22}, {57, 22}, {43, 22}, {28, 22}, {11, 22},
    {218, 8},  {198, 8},  {176, 8},  {163, 8},  {148, 8},  {134, 8},  {120, 8},  {106, 8},  {92, 8},   {78, 8},  {64, 8},  {50, 8},  {35, 8},  {21, 8},  {7, 8}
    #ifndef ID67_IS_BESTYPE
    ,
    // underglow LEDs
    {6, 11},   {60, 11},  {118, 11}, {164, 11}, {219, 11},
    {219, 53}, {165, 53}, {112, 53}, {64, 53},  {12, 53},
    #endif
}, {
    // LED Index to Flag
    // switch LEDs
    1, 1, 1, 1, 1,          4,       1,    1, 1,
    1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,
    1, 1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 9,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1
    #ifndef ID67_IS_BESTYPE
    ,
    // underglow LEDs
    2, 2, 2, 2, 2,
    2, 2, 2, 2, 2
    #endif
} };

__attribute__ ((weak))
void rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(36, 0xFF, 0xFF, 0xFF);
    }
}

#endif
