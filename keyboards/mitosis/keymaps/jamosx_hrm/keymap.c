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
	_NUM,
	_FN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWY] = LAYOUT( /* Standard; as compatible with dvorak and qwerty as possible */
    KC_Q,  KC_W,  KC_E,  KC_R,   KC_T,               KC_Y,  KC_U,  KC_I,  KC_O, KC_P,   
    KC_A,    ALT_S, CTL_D,  SFT_F,    KC_G,         KC_H,  SFT_J,  CTL_K,  ALT_L, KC_SCLN,
    LT(_FN, KC_Z) , KC_X,  KC_C,  GUI_V,  KC_B,       KC_N, GUI_M, KC_COMM, KC_DOT,  KC_ENT,
          _______,_______,_______,_______,           MO(_NUM), _______, _______, _______,
          _______, _______,LT(_NUM,KC_QUOT),   GUI_T(KC_ENT),         LSFT_T(KC_SPC), LT(_FN, KC_BSPC),_______,_______
  ), 
 

  [_NUM] = LAYOUT( /* Number layout along the home row for maximum speed*/
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                 KC_F1,   KC_F2,   KC_F3,  KC_F4, KC_SLSH,
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                 KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_SCLN,
    KC_LSFT, _______, _______,_______, _______,             KC_F9,   KC_F10, KC_F11,  KC_F12, KC_ENT,
            _______, _______,_______, _______,       _______, _______, _______, _______,
            _______, _______, _______, _______,       _______, _______, _______, _______
  ),

  [_FN] = LAYOUT( /* Function Layer, primary alternative layer featuring numpad on right hand,
                                     cursor keys on left hand, and all symbols*/
    KC_ESC,  _______, KC_UP, _______, KC_GRV,       KC_BSLS, KC_WH_L, KC_MS_UP, KC_DEL, KC_BSPC,
    KC_TAB,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_MINS,       KC_EQL, KC_MS_L, KC_MS_D, KC_MS_R, KC_QUOT,
    KC_LSFT, C(KC_LEFT), C(KC_UP), C(KC_RIGHT), KC_LBRC,       KC_RBRC, KC_BTN1, KC_BTN2, KC_9, KC_ENT,
             _______, _______, _______, _______,       _______, _______, _______, _______,
             _______, _______, _______, _______,       _______, _______, _______, _______
  ), 


  /* blank key layout template
   * .--------------------------------------------..--------------------------------------------.
   * |        |        |        |        |        ||        |        |        |        |        |
   * 
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
  VB_LBRC,
  GB_MIN,
  RT_GRV,
  UY_BSLS,
  HN_EQL,
  MN_RBRC,
  TG_LPAREN,
  YH_RPAREN,
  DOTCOM_TILD,
  QW_ESC,
  QE_TAB,
  DOTENT_SLSH
};
const uint16_t PROGMEM lbrc_combo[] = {KC_C, KC_B, COMBO_END};
const uint16_t PROGMEM min_combo[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM grv_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM bsls_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM rbrc_combo[] = {KC_N, KC_COMM, COMBO_END};
const uint16_t PROGMEM lparen_combo[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM tild_combo[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_E, KC_Q, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_ENT, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [VB_LBRC] = COMBO(lbrc_combo, KC_LBRC),
  [GB_MIN] = COMBO(min_combo, KC_MINS),
  [RT_GRV] = COMBO(grv_combo, KC_GRV),
  [UY_BSLS] = COMBO(bsls_combo, KC_BSLS),
  [HN_EQL] = COMBO(eql_combo, KC_EQL),
  [MN_RBRC] = COMBO(rbrc_combo, KC_RBRC),
  [TG_LPAREN] = COMBO(lparen_combo, KC_LPRN),
  [YH_RPAREN] = COMBO(rparen_combo, KC_RPRN),
  [DOTCOM_TILD] = COMBO(tild_combo, KC_TILD),
  [QW_ESC] = COMBO(esc_combo, KC_ESC),
  [QE_TAB] = COMBO(tab_combo, KC_TAB),
  [DOTENT_SLSH] = COMBO(slsh_combo, KC_SLSH),
};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
    	case _QWY:
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

