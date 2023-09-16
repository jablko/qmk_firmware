// Copyright 2023 Jack Bates (@jablko)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

// clang-format off
#define LAYOUT_ortho_5x12(...) LAYOUT_ortho_6x12(__VA_ARGS__, \
    XXXXXXX, XXXXXXX, XXXXXXX, DRAG_SCROLL, KC_BTN1, XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX \
)
// clang-format on
