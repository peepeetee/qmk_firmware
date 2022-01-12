/* Copyright 2021 Tybera
 * Copyright 2021 thewerther
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "id67.h"

#define __ NO_LED

// Indices are reveresed on the physical board, top left is bottom right.
led_config_t g_led_config = { {
    // Key Matrix to LED Index
    {66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52},
    {51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37},
    {36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, __, 24, 23},
    {22, __, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10,  9},
    { 8,  7, __,  6, __, __,  5, __, __, __,  4,  3,  2,  1,  0},
}, {
    // LED Index to Physical Position
    {239, 64}, {222, 64}, {207, 64}, {180, 64}, {160, 64},                                  {107, 64},                      {40, 64},           {20, 64}, {0, 64},
    {239, 48}, {222, 48}, {204, 48}, {184, 48}, {168, 48}, {152, 48}, {136, 48}, {120, 48}, {104, 48},  {88, 48}, {72, 48}, {56, 48}, {40, 48},           {13, 48},
    {239, 32}, {210, 32},            {189, 32}, {173, 32}, {157, 32}, {141, 32}, {125, 32}, {109, 32}, {93, 32}, {77, 32}, {61, 32}, {45, 32}, {29, 32}, {8, 32},
    {239, 16}, {220, 16}, {201, 16}, {185, 16}, {169, 16}, {153, 16}, {137, 16}, {121, 16}, {105, 16},  {89, 16}, {73, 16}, {57, 16}, {41, 16}, {25, 16}, {5, 16},
    {239,  0}, {217,  0}, {192,  0}, {176,  0}, {160,  0}, {144,  0}, {128,  0}, {112,  0}, {96,  0},  {80,  0}, {64,  0}, {48,  0}, {32,  0}, {16,  0}, {0,  0},
    // underglow LEDs
    {0, 0}, {56, 0}, {112, 0}, {168, 0}, {224, 0},
    {224, 64}, {168, 64}, {112, 64}, {56, 64}, {0, 64}
},  {
    // LED Index to Flag
    4, 4, 4, 1, 1, 4, 1, 1, 1,                   // first row
    1, 4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,    // second row
    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,    // third row
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, // fourth row
    4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, // fifth row
    // underglow leds
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2
} };
