// Copyright 2023 Jack Bates (@jablko)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "pocket_reform.h"
#include "i2c_master.h"

#define PAT9125_ADDR 0x79
#define REG_DELTA_X_LO 0x03
#define REG_RES_X 0x0D
#define CPI_MAX 1275

#if defined(COMBO_ENABLE)
#    include "keymap_introspection.h"

const uint16_t PROGMEM combo_btn3[] = {KC_BTN1, KC_BTN2, COMBO_END};

combo_t key_combos_kb[] = {
    COMBO(combo_btn3, KC_BTN3),
};

uint16_t combo_count(void) {
    return combo_count_raw() + sizeof(key_combos_kb) / sizeof(combo_t);
}

combo_t* combo_get(uint16_t combo_idx) {
    return combo_idx < combo_count_raw() ? combo_get_raw(combo_idx) : &key_combos_kb[combo_idx - combo_count_raw()];
}
#endif

bool drag_scroll = false;
bool drag_volume = false;

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case DRAG_SCROLL:
            if (record->tap.count == 0) {
                drag_scroll = record->event.pressed;
            } else if (record->event.pressed) {
                drag_scroll = !drag_scroll;
            }
            break;
        case KC_VOLU:
        case KC_VOLD:
            if (record->tap.count == 0) {
                drag_volume = record->event.pressed;
                return false;
            }
            break;
    }
    return process_record_user(keycode, record);
}

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    if (drag_scroll) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    } else if (drag_volume) {
        tap_code(mouse_report.y > 0 ? KC_VOLU : KC_VOLD);
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return pointing_device_task_user(mouse_report);
}

// void pointing_device_driver_init(void) {}

report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report) {
    uint8_t data[] = {0, 0};
    i2c_readReg(PAT9125_ADDR << 1, REG_DELTA_X_LO, data, sizeof(data), I2C_TIMEOUT);
    mouse_report.x = data[0];
    mouse_report.y = data[1];
    return mouse_report;
}

uint16_t pointing_device_driver_get_cpi(void) {
    uint8_t data = 0;
    i2c_readReg(PAT9125_ADDR << 1, REG_RES_X, &data, sizeof(data), I2C_TIMEOUT);
    return data;
}

void pointing_device_driver_set_cpi(uint16_t cpi) {
    if (cpi > CPI_MAX) {
        cpi = CPI_MAX;
    }
    uint8_t data[] = {cpi, cpi};
    i2c_writeReg(PAT9125_ADDR << 1, REG_RES_X, data, sizeof(data), I2C_TIMEOUT);
}
