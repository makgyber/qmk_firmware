// This is the Dvorak-friendly layout for the Mitosis by CarVac (/u/CarVac)
// It features space on the left thumb, shift on the right thumb, a
//  number layer with all the numbers on the home row, and a function layer
//  that provides mouse keys among other things.

#include QMK_KEYBOARD_H

//Mousekeys
#define MOUSEKEY_DELAY 300
#define MOUSEKEY_INTERNAL 50
#define MOUSEKEY_MAX_SPEED 20
#define MOUSEKEY_TIME_TO_MAX 30
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

enum mitosis_layers
{
  _QWY,
  _HANDS,
  _LEFT,
	_NUM,
	_FN
};

enum custom_keycodes {
    THIS = SAFE_RANGE,
    HOMER,
    ARROW, 
    DBLARROW, 
    LOGIN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWY] = LAYOUT( /* Standard; as compatible with dvorak and qwerty as possible */
    KC_Q,  KC_W,  KC_E,  KC_R,   KC_T,               KC_Y,  KC_U,  KC_I,  KC_O, KC_P,   
    KC_A,    KC_S, KC_D,  KC_F,    KC_G,             KC_H,  KC_J,  KC_K,  KC_L, KC_SCLN,
    KC_Z, KC_X,  KC_C,  KC_V,  KC_B,                 KC_N, KC_M, KC_COMM, KC_DOT,  KC_ENT,
          _______,KC_LCTL, LT(_FN, KC_SPC),GUI_T(KC_ENT),          LSFT_T(KC_SPC), LT(_NUM, KC_BSPC), KC_LALT,DF(_HANDS),
          
          _______, _______,_______, _______,           _______,_______,_______,_______
  ), 

  [_HANDS] = LAYOUT( /* hands on layout */
    _______, _______,_______, _______,_______,           KC_F, KC_R,  KC_U, KC_O,    KC_P,   
    KC_LALT, KC_LCTL,KC_LGUI, KC_LSFT,_______,           KC_G,  KC_N ,  KC_E,  KC_I,  KC_A, 
    _______, _______,_______, _______,_______,           KC_T,  KC_H,  KC_C, KC_S, KC_ENT,
          _______, _______,_______, _______,          _______, _______,_______,_______,
          DF(_QWY),_______, _______,_______,            LT(_LEFT, KC_SPC),_______,_______,_______
  ),

  [_LEFT] = LAYOUT( /* hands on layout */
    _______, _______,_______, _______,_______,           KC_Y,   KC_V,  KC_D , KC_W,  KC_Q, 
    KC_LALT, KC_LCTL,KC_LGUI, KC_LSFT,_______,           KC_X,  KC_J,  KC_K,  KC_L, KC_SCLN,
    _______, _______,_______, _______,_______,           KC_B, KC_M, KC_COMM, KC_DOT,  KC_Z,  
          _______, _______,_______, _______,          _______, _______,_______,_______,
          _______, _______,_______, _______,          _______, _______,_______,_______
  ),
 

  [_NUM] = LAYOUT( /* Number layout along the home row for maximum speed*/

KC_LSFT, G(KC_X), G(KC_C), G(KC_V), G(KC_Z),             KC_1,    KC_2,    KC_3,    KC_4,    KC_5, 
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_EXLM,    KC_AT,    KC_HASH,    KC_DLR,    KC_PERC,                 KC_MINS,   KC_EQL,   KC_LBRC,  KC_RBRC, KC_SLSH,
            _______, _______,_______, _______,       _______, _______, _______, _______,
            _______, _______, _______, _______,       _______, _______, _______, _______
  ),

  [_FN] = LAYOUT( /* Function Layer, primary alternative layer featuring numpad on right hand,
                                     cursor keys on left hand, and all symbols*/
    KC_ESC,  LOGIN, KC_UP, _______, KC_GRV,       KC_BSLS, KC_WH_L, KC_MS_UP, KC_DEL, KC_BSPC,
    KC_TAB,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_MINS,       KC_EQL, KC_MS_L, KC_MS_D, KC_MS_R, KC_QUOT,
    KC_LSFT, C(KC_LEFT), C(KC_UP), C(KC_RIGHT), KC_LBRC,       KC_RBRC, KC_BTN1, KC_BTN2, KC_9, KC_SLSH,
             _______, _______, _______, _______,       _______, _______, _______, _______,
             _______, _______, _______, _______,       _______, _______, _______, _______
  ), 


  /* blank key layout template
   * .--------------------------------------------..--------------------------------------------.
   * |        |        |        |        |        ||        |        |        |        |        |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * |        |        |        |        |        ||        |        |        |        |        |
   * |--------+--------+--------+--------+--------||--------+--------+--------+--------+--------|
   * |        |        |        |        |        ||        |        |        |        |        |
   * '--------+--------+--------+--------+--------||--------+--------+--------+--------+--------'
   *          |        |        |        |        ||        |        |        |        |
   *          |--------+--------+--------+--------||--------+--------+--------+--------|
   *          |        |        |        |        ||        |        |        |        |
   *          '-----------------------------------''-----------------------------------'
   */

};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
    	case _QWY:
    		set_led_off;
    		break;
      case _HANDS:
    		set_led_green;
    		break;
    case _LEFT:
          set_led_yellow;
          break;
      case _FN:
          set_led_blue;
          break;
      case _NUM:
          set_led_red;
          break;
      default:
          set_led_off;
          break;
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case THIS:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("$this->");
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
        case ARROW:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("->");
            } else {
                // when keycode QMKURL is released
            }
            break;
        case DBLARROW:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("=>");
            } else {
                // when keycode QMKURL is released
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
