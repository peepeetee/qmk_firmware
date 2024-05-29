// Copyright 2024 peepeetee (@peepeetee)
// SPDX-License-Identifier: GPL-2.0-or-later

void debounce_init(uint8_t num_rows) {}

bool debounce(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows, bool changed) {

    sym_defer_g
    sym_defer_pr
    sym_defer_pk
    sym_eager_pr
    sym_eager_pk
    asym_eager_defer_pk

}

void debounce_free(void) {}
