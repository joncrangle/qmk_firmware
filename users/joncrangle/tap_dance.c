#include QMK_KEYBOARD_H
#include "tap_dance.h"
#include "joncrangle.h"
#ifdef OS_DETECTION_ENABLE
#    include "os_detection.h"
#endif

static td_state_t td_state_super_caps;
static td_state_t td_state_productivity;
static td_state_t td_state_encoder;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    }
    if (state->count == 2) return TD_DOUBLE_TAP;
    return TD_UNKNOWN;
}

void super_caps_finished(tap_dance_state_t *state, void *user_data) {
    td_state_super_caps = cur_dance(state);
    switch (td_state_super_caps) {
        case TD_SINGLE_TAP:
            register_code(KC_ESC);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_NUM_LOCK);
            layer_on(_NUMPADMOUSE);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_NUM_LOCK);
            if (layer_state_is(_NUMPADMOUSE)) {
                layer_off(_NUMPADMOUSE);
            } else {
                layer_on(_NUMPADMOUSE);
            }
            break;
        default:
            break;
    }
}

void super_caps_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state_super_caps) {
        case TD_SINGLE_TAP:
            unregister_code(KC_ESC);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_NUM_LOCK);
            layer_off(_NUMPADMOUSE);
            break;
        default:
            break;
    }
    td_state_super_caps = TD_NONE;
}

static inline uint16_t get_mod_key(uint16_t keycode) {
#ifdef OS_DETECTION_ENABLE
    os_variant_t os = detected_host_os();
    if (os == OS_MACOS || os == OS_IOS) {
        return LGUI(keycode);
    }
#endif
    return LCTL(keycode);
}

void productivity_finished(tap_dance_state_t *state, void *user_data) {
    td_state_productivity = cur_dance(state);
    switch (td_state_productivity) {
        case TD_SINGLE_TAP:
            tap_code16(get_mod_key(KC_C));
            break;
        case TD_SINGLE_HOLD:
            tap_code16(get_mod_key(KC_X));
            break;
        case TD_DOUBLE_TAP:
            tap_code16(get_mod_key(KC_V));
            break;
        default:
            break;
    }
}

void productivity_reset(tap_dance_state_t *state, void *user_data) {
    td_state_productivity = TD_NONE;
}

void encoder_td_finished(tap_dance_state_t *state, void *user_data) {
    td_state_encoder = cur_dance(state);
    switch (td_state_encoder) {
        case TD_SINGLE_TAP:
            tap_code(KC_MUTE);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_MPLY);
            break;
        default:
            break;
    }
}

void encoder_td_reset(tap_dance_state_t *state, void *user_data) {
    td_state_encoder = TD_NONE;
}
