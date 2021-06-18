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
  _HANDS,
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
 
  [_STD] = LAYOUT( /* Standard; as compatible with dvorak and qwerty as possible */
    KC_Q,        KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,        KC_S,    KC_D,    KC_F,    KC_G,         KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN,
    LSFT_T(KC_Z), KC_X,  KC_C,    KC_V,    KC_B,    KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_ENT,
              THIS, ARROW,DBLARROW, MO(_NUM),         MO(_NUM), HOMER, LOGIN, DF(_HANDS),
              KC_LSFT, KC_DEL,LT(_FN, KC_SPC),GUI_T(KC_ENT),    LSFT_T(KC_SPC),LT(_FN, KC_BSPC),  KC_RALT, KC_RCTL
  ),
 
   [_HANDS] = LAYOUT( /* hands on layout */
    KC_Q,  KC_C,   KC_H,    KC_P,    KC_V ,         KC_K,   KC_Y,   KC_O , KC_J,    KC_SCLN,
    KC_R,  KC_S,   KC_N,    KC_T,    KC_G,          KC_W,   KC_U,   KC_E,  KC_I, KC_A,
    KC_X , KC_M,   KC_L,    KC_D, KC_B,    KC_Z,   KC_F,   KC_COMM, KC_DOT,  KC_ENT,
           _______, _______,_______, _______,       _______, _______, _______, DF(_STD),
           _______, _______, _______, _______,       _______, _______, _______, _______
  ),

  [_NUM] = LAYOUT( /* Number layout along the home row for maximum speed*/
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                 KC_BSLS,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                 KC_MINS,    KC_4,    KC_5,    KC_6,    KC_QUOT,
    KC_LSFT, C(KC_LEFT), C(KC_DOWN), C(KC_RIGHT), KC_UP,      KC_EQL,     KC_1,    KC_2,    KC_3,   KC_SLSH,
            _______, _______,_______, _______,       _______, _______, _______, _______,
            _______, _______, _______, _______,       _______, _______, _______, _______
  ),

  [_FN] = LAYOUT( /* Function Layer, primary alternative layer featuring numpad on right hand,
                                     cursor keys on left hand, and all symbols*/
    KC_MS_L, KC_MS_D, KC_MS_UP, KC_MS_R, KC_ESC,        KC_ESC,  KC_HOME, KC_UP, KC_END, KC_GRV,       
    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TAB,          KC_TAB,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOT,       
    KC_BTN2, C(KC_LEFT), C(KC_UP), C(KC_RIGHT), KC_BTN1,    KC_BTN1, C(KC_LEFT), C(KC_UP), C(KC_RIGHT), KC_BTN2,       
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



enum combo_events {
  QW_ESC,
  QE_TAB,
  PSC_BSPC
};

const uint16_t PROGMEM esc_combo[] = {KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_E, KC_Q, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_SCLN, KC_P, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [QW_ESC] = COMBO(esc_combo, KC_ESC),
  [QE_TAB] = COMBO(tab_combo, KC_TAB),
  [PSC_BSPC] = COMBO(bspc_combo, KC_BSPC),
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