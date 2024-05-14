// Copyright 2023 Cipulot 2024 peepeetee (@peepeetee)
// SPDX-License-Identifier: GPL-2.0-or-later


#include "via.h"

enum via_debounce_type_enums {
    sym_defer_g = 1;
    sym_defer_pr = 2;
    sym_defer_pk = 3;
    sym_eager_pr = 4;
    sym_eager_pk = 5;
    asym_eager_defer_pk = 6;
}

typedef struct _debounce_config_t {
    uint8_t debounce_type;
} debounce_config;

// Check if the size of the reserved persistent memory is the same as the size of struct apc_config
_Static_assert(sizeof(debounce_config) == EECONFIG_USER_DATA_SIZE, "Mismatch in keyboard EECONFIG stored data");

// Declaring a global variable: this variable is read from and written to EEPROM
debounce_config g_debounce_config;

// debounce_config g_debounce_config = {
//     .debounce_type = 1
// };

// Initializing persistent memory configuration: default values are declared and stored in PMEM
void eeconfig_init_user(void) {
    // Default values
    g_debounce_config.debounce_type = sym_defer_g;
    // Write default value to EEPROM now
    eeconfig_update_user_datablock(&g_debounce_config);
}

// On Keyboard startup
void keyboard_post_init_user(void) {
    // Read custom menu variables from memory
    eeconfig_read_user_datablock(&g_debounce_config);
    INITIALIZE -- SELECT -- DEBOUNCE METHOD HERE
}

//communicates with via, and calls the corresponding handler
void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    uint8_t *value_id_and_data = &(data[2]);

    if ( *channel_id == id_custom_channel ) {
        switch ( *command_id )
        {
            case id_custom_set_value:
            {
                debounce_config_set_value(value_id_and_data);
                break;
            }
            case id_custom_get_value:
            {
                debounce_config_get_value(value_id_and_data);
                break;
            }
            case id_custom_save:
            {
                debounce_config_save();
                break;
            }
            default:
            {
                // Unhandled message.
                *command_id = id_unhandled;
                break;
            }
        }
        return;
    }

    // Return the unhandled state
    *command_id = id_unhandled;

    // DO NOT call raw_hid_send(data,length) here, let caller do this
}



void debounce_config_set_value( uint8_t *data )
{
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch ( *value_id )
    {
        case id_buttglow_brightness:
        {
            g_debounce_config.debounce_type = *value_data;
            break;
        }
        ...
    }
}

void debounce_config_get_value( uint8_t *data )
{
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch ( *value_id )
    {
        case id_buttglow_brightness:
        {
            *value_data = g_debounce_config.debounce_type;
            break;
        }
        ...
    }
}

void buttglow_config_save(void)
{
    eeconfig_update_user_datablock(&g_debounce_config);
}

