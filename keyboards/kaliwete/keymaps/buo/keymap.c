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
    _ALFA,
    _NUM,
    _NAV
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    HOMER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */

    // [_BLANK] = LAYOUT(
    //         _______,  _______, _______, _______, _______, _______, 
    //         _______,  _______, _______, _______, _______, _______,
    //         _______,  _______, _______, _______, _______, _______,
    //              _______,      _______, _______, _______, _______
    //     ),

    [_BASE] = LAYOUT(
        _______,KC_F,  KC_D, KC_I, KC_N, KC_G, 
        OSL(_ALFA),KC_A,  KC_T, KC_H, KC_E, KC_S,
        OSL(_NUM),KC_C,  KC_W, KC_R, KC_O,  KC_U, 
               LT(_NAV, KC_ENT),      KC_LCTL,   KC_LGUI,   GUI_T(KC_BSPC), LSFT_T(KC_SPC)
    ),
    [_ALFA] = LAYOUT(
        _______,KC_J, KC_K, KC_M,  KC_QUOT, KC_MINUS,  
        _______,KC_Y, KC_P, KC_L,  KC_DOT, KC_Q,   
        _______,KC_X, KC_B, KC_V,  KC_COMMA, KC_Z,  
          _______,  _______, _______, _______, _______
    ),
    [_NUM] = LAYOUT(
        _______,KC_6, KC_7, KC_8, KC_9, KC_0, 
        _______,KC_1, KC_2, KC_3, KC_4, KC_5 , 
        _______,G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_S), 
          _______,  _______, _______, _______, _______



    ),
    [_NAV] = LAYOUT(
        _______,KC_GRV,   KC_M,       KC_UP,      KC_QUOT,    KC_BSLS, 
        _______,KC_MINS,  KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_EQL,
        _______,KC_LBRC,  C(KC_LEFT), C(KC_UP), C(KC_RIGHT), KC_RBRC, 
          _______,  _______, _______, _______, KC_LSFT
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
        case HOMER:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("~/");
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

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
    	case _BASE:
    		set_led_yellow;
    		break;
        case _ALFA:
            set_led_blue;
            break;
        case _NUM:
            set_led_red;
            break;
        case _NAV:
        	set_led_green;
        	break;
        default:
        set_led_yellow;
            break;
    }
};
