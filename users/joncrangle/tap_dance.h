#pragma once

#include QMK_KEYBOARD_H

typedef enum { TD_NONE, TD_UNKNOWN, TD_SINGLE_TAP, TD_SINGLE_HOLD, TD_DOUBLE_TAP } td_state_t;

enum tap_dance_keycodes { TD_SUPER_CAPS, TD_PRODUCTIVITY, TD_ENCODER };

td_state_t cur_dance(tap_dance_state_t *state);

void super_caps_finished(tap_dance_state_t *state, void *user_data);
void super_caps_reset(tap_dance_state_t *state, void *user_data);

void productivity_finished(tap_dance_state_t *state, void *user_data);
void productivity_reset(tap_dance_state_t *state, void *user_data);

void encoder_td_finished(tap_dance_state_t *state, void *user_data);
void encoder_td_reset(tap_dance_state_t *state, void *user_data);
