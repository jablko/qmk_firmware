// Copyright 2023 Jack Bates (@jablko)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "pocket_reform.h"
#include "i2c_master.h"

#define PAT9125_ADDR 0x79
#define REG_DELTA_X_LO 0x03
#define REG_RES_X 0x0D
#define CPI_MAX 1275

bool set_scrolling = false;

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (keycode == DRAG_SCROLL) {
        set_scrolling = record->event.pressed;
    }
    return process_record_user(keycode, record);
}

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
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
