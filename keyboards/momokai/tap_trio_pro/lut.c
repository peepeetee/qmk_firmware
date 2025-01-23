/* Copyright 202 RephlexZero (@RephlexZero) 2024 peepeetee (@peepeetee) 2024 Jenna Fligor (@Ex-32)
SPDX-License-Identifier: GPL-2.0-or-later */
#include <math.h>
#include <stdint.h>
// #include "scanfunctions.h"
// #include "util.h"

#if !defined(MIN)
#    define MIN(x, y) (((x) < (y)) ? (x) : (y))
#endif

#if !defined(MAX)
#    define MAX(x, y) (((x) > (y)) ? (x) : (y))
#endif

// /* Equation parameters for the sensor-magnet linearity mapping */
// const double lut_a = 0.200347177016;
// const double lut_b = 0.00955994866154;
// const double lut_c = 6.01110636956;
// const double lut_d = 1966.74076381;

/* Equation parameters for the sensor-magnet linearity mapping */
const double lut_a = -366.805673399;
const double lut_b = 0.00617870508512;
const double lut_c = -1.49468890703;
const double lut_d = 2094.38794157;

uint16_t distance_to_adc(uint16_t distance) {
    double intermediate = lut_a * exp(lut_b * distance + lut_c) + lut_d;
    return (uint16_t) fmax(0, fmin(intermediate, 4095));
}

uint16_t adc_to_distance(uint16_t adc) {
    double check = (adc - lut_d) / lut_a;
    if (check <= 0) {
        return 0;
    }
    double intermediate = (log(check) - lut_c) / lut_b;
    return (uint16_t) fmax(0, fmin(intermediate, 255));
}

uint16_t lut[ADC_RESOLUTION_MAX] = {0};

void generate_lut(void) {
    for (uint16_t i = 0; i < ADC_RESOLUTION_MAX; i++) {
        lut[i] = adc_to_distance(i);
    }
}
