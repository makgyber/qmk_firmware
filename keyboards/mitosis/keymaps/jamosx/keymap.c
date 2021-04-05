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
	_STD,
	_NUM,
	_FN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  
  [_STD] = LAYOUT( /* Standard; as compatible with dvorak and qwerty as possible */
    KC_Q,        KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,        KC_S,    KC_D,    KC_F,    KC_G,         KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,        KC_X,    KC_C,    KC_V,    KC_B,         KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_ENT,
              _______, _______,_______, _______,          _______, _______, _______, _______,
              _______, KC_LALT,LT(_NUM, KC_SPC),GUI_T(KC_ENT),    SFT_T(KC_SPC),LT(_FN, KC_SPC),  KC_RCTL, _______
  ),

  [_NUM] = LAYOUT( /* Number layout along the home row for maximum speed*/
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                 KC_F1,   KC_F2,   KC_F3,  KC_F4, KC_BSPC,
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                 KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_QUOT,
    KC_LSFT, C(KC_LEFT), C(KC_DOWN), C(KC_RIGHT), KC_UP,     KC_F9,   KC_F10, KC_F11,  KC_F12,   KC_ENT,
            _______, _______,_______, _______,       _______, _______, _______, _______,
            _______, _______, _______, _______,       _______, _______, _______, _______
  ),

  [_FN] = LAYOUT( /* Function Layer, primary alternative layer featuring numpad on right hand,
                                     cursor keys on left hand, and all symbols*/
    KC_ESC,  _______, KC_MS_UP, _______, KC_GRV,       KC_BSLS, KC_WH_L, KC_UP, KC_BSPC, KC_DEL,
    KC_TAB,  KC_MS_L, KC_MS_D, KC_MS_R, KC_MINS,       KC_EQL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOT,
    KC_LSFT, KC_BTN1, KC_BTN2, KC_BTN3, KC_LBRC,       KC_RBRC, C(KC_LEFT), C(KC_DOWN), C(KC_RIGHT),  KC_SLSH,
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
    	case _STD:
    		set_led_off;
    		break;
        case _FN:
            set_led_blue;
            break;
        case _NUM:
            set_led_red;
            break;
        default:
            break;
    }
};

