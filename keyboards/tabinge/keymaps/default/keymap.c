/* Copyright 2021 Jon Mereria
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
#include QMK_KEYBOARD_H

//Mousekeys
#define MOUSEKEY_DELAY 300
#define MOUSEKEY_INTERNAL 50
#define MOUSEKEY_MAX_SPEED 20
#define MOUSEKEY_TIME_TO_MAX 30
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

enum combo_events {
  QW_ESC,
  QE_TAB,
  PSC_BSPC
};

const uint16_t PROGMEM esc_combo[] = {KC_C, KC_Q, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_H, KC_Q, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_SCLN, KC_J, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [QW_ESC] = COMBO(esc_combo, KC_ESC),
  [QE_TAB] = COMBO(tab_combo, KC_TAB),
  [PSC_BSPC] = COMBO(bspc_combo, KC_BSPC),
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE, 
    _HAND,
    _NUM,
    _NAV
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    LOGIN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_Q,        KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,
    LSFT_T(KC_A),        LCTL_T(KC_S),    LALT_T(KC_D),    KC_F,    KC_G,         KC_H,      LGUI_T(KC_J),    LALT_T(KC_K),    LCTL_T(KC_L),    LSFT_T(KC_SCLN),
    LT(_NAV, KC_Z), KC_X,  KC_C,    KC_V,    KC_B,    KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_ENT,
                                    LGUI_T(KC_ENT),         LT(_NUM, KC_SPC),    LT(_NAV, KC_BSPC),  KC_TAB
    )
    ,
    [_HAND] = LAYOUT(
        KC_Q,  KC_C,   KC_H,    KC_P,    KC_V ,         KC_K,   KC_Y,   KC_O , KC_J,    KC_SCLN,
        LSFT_T(KC_R),  LCTL_T(KC_S),   LALT_T(KC_N),    KC_T,    KC_G,          KC_W,   LGUI_T(KC_U),   LALT_T(KC_E),  LCTL_T(KC_I), LSFT_T(KC_A),
        LT(_NAV, KC_X) , KC_M,   KC_L,    KC_D, KC_B,    KC_Z,   KC_F,   KC_COMM, KC_DOT,  KC_ENT,
                                    LGUI_T(KC_ENT),         LT(_NUM, KC_SPC),    LT(_NAV, KC_BSPC),  KC_TAB
    )
    ,
    [_NUM] = LAYOUT(
        KC_ESC, _______, _______, _______, DF(_HAND),        KC_BSLS,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  DF(_BASE),        KC_MINS,    KC_4,    KC_5,    KC_6,    KC_QUOT,
        _______, _______, _______, _______, _______,        KC_EQL,     KC_1,    KC_2,    KC_3,   KC_SLSH,
                                            _______,        _______, _______, _______
    )
    ,
    [_NAV] = LAYOUT(
        LOGIN, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,        KC_TILD,    KC_HOME,    KC_UP,    KC_END,  KC_GRV,
        _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,         KC_LPRN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,    KC_RPRN,
        _______, KC_LCTL, KC_LALT, KC_BTN2, KC_BTN1,         KC_LBRC,  C(KC_LEFT), C(KC_DOWN), C(KC_RIGHT),   KC_RBRC,
                                            _______,        _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case LOGIN:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("jon99");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
