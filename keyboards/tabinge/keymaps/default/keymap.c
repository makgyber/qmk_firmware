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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE, 
    _NUM,
    _NAV
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                           KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,  KC_S,  KC_D,  KC_F,  KC_G,           KC_H,      KC_J,    KC_K,  KC_L,    KC_SCLN,
        KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,           KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_ENT,
                                    LT(_NAV, KC_SPC),         LT(_NUM, KC_SPC),    LT(_NAV, KC_BSPC),  KC_TAB
    )
    ,
    [_NUM] = LAYOUT(
        KC_ESC, _______, _______, _______, _______,        KC_BSLS,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  _______,        KC_MINS,    KC_4,    KC_5,    KC_6,    KC_QUOT,
        _______, _______, _______, _______, _______,        KC_EQL,     KC_1,    KC_2,    KC_3,   KC_SLSH,
                                            _______,        _______, _______, _______
    )
    ,
    [_NAV] = LAYOUT(
        _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,        KC_TILD,    KC_HOME,    KC_UP,    KC_END,  KC_GRV,
        KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  G(KC_S),        KC_LPRN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,    KC_RPRN,
        G(KC_Z), G(KC_X), G(KC_C), G(KC_V), KC_BTN1,         KC_LBRC,  C(KC_LEFT), C(KC_DOWN), C(KC_RIGHT),   KC_RBRC,
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
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
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
