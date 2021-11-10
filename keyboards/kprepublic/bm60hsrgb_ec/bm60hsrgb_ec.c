#include "bm60hsrgb_ec.h"
led_config_t g_led_config = { {
  { 0,      1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,     12,     13 },
  { 14,     15,     16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27 },
  { 28,     NO_LED, 29,     30,     31,     32,     33,     34,     35,     36,     37,     38,     39,     40 },
  { NO_LED, 41,     42,     43,     44,     45,     46,     47,     48,     49,     50,     51,     52,     53 },
  { 54,     55,     56,     NO_LED, NO_LED, NO_LED, 57,     NO_LED, NO_LED, 58,     59,     60,     61,     62 }
}, {
    // Esc, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -, =, Backspace
    {   0,   0 }, {  15,   0 }, {  30,   0 }, {  45,   0 }, {  60,   0 }, {  75,   0 }, {  90,   0 }, { 105,   0 }, { 120,   0 }, { 135,   0 }, { 150,   0 }, { 165,   0 }, { 180,   0 }, { 195,   0 },
    // Tab, Q, W, E, R, T, Y, U, I, O, P, [, ],  ,
    {   7,  16 }, {  22,  16 }, {  37,  16 }, {  52,  16 }, {  67,  16 }, {  82,  16 }, {  97,  16 }, { 112,  16 }, { 127,  16 }, { 142,  16 }, { 157,  16 }, { 172,  16 }, { 187,  16 }, { 206,  16 },
    // Capslock, A, S, D, F, G, H, J, K, L, ;, ', Enter
    {  11,  32 }, {  26,  32 }, {  41,  32 }, {  56,  32 }, {  71,  32 }, {  86,  32 }, { 101,  32 }, { 116,  32 }, { 131,  32 }, { 146,  32 }, { 161,  32 }, { 176,  32 }, { 198,  32 },
    // LShift, Z, X, C, V, B, N, M, ,, ., /, Shift, Up,
    {  18,  48 }, {  30,  48 }, {  45,  48 }, {  60,  48 }, {  75,  48 }, {  90,  48 }, { 105,  48 }, { 120,  48 }, { 135,  48 }, { 150,  48 }, { 165,  48 }, { 191,  48 }, { 210,  48 },
    // Ctrl, GUI, Alt, Space, RAlt, FN, Left, Down, Right
    {   3,  64 }, {  22,  64 }, {  33,  64 }, { 101,  64 }, { 135,  64 }, { 153,  64 }, { 195,  64 }, { 210,  64 }, { 225,  64 },
    // UNDERGLOW
    {   216, 32 }, {  180,  32 }, {  144, 32 }, { 108,  32 }, { 72,  32 }, { 36,  32 }
}, {
    // Esc, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -, =, Backspace
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    // Tab, Q, W, E, R, T, Y, U, I, O, P, [, ],  ,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    // Capslock, A, S, D, F, G, H, J, K, L, ;, ', Enter
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    // LShift, Z, X, C, V, B, N, M, ,, ., /, Shift, Up,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    // Ctrl, GUI, Alt, Space, RAlt, FN, Left, Down, Right
    1, 1, 1, 4, 1, 1, 1, 1, 1,
    // UNDERGLOW
    2, 2, 2, 2, 2, 2
} };
void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

__attribute__ ((weak))
void rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(28, 0xFF, 0xFF, 0xFF);
    }
}