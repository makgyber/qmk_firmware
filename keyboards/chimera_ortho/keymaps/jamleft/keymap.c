// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum chimera_ortho_layers {
  _QWERTY,
  _CAPS,
  _NUMPAD,
  _SYMBOLS,
  _MACROS,
  _NAV
};

#define KC_NMPD TG(_NUMPAD)
#define KC_SYMB TG(_SYMBOLS)
#define KC_NAVZ LT(_NAV,KC_Z)
#define KC_NAVSL LT(_NAV,KC_SLSH)
#define KC_SBRC LT(_SYMBOLS, KC_RBRC)
#define KC_NPLBR LT(_NUMPAD, KC_LBRC)
#define KC_MINLH LT(_CAPS, KC_MINS)
#define KC_SFSP MT(MOD_RSFT, KC_SPC)
#define KC_SPFN LT(_NUMPAD, KC_BSPC)
#define KC_SPCTL MT(MOD_LCTL, KC_SPC)
#define KC_GENT MT(MOD_LGUI, KC_ENT)
#define KC_GUIF MT(MOD_LGUI, KC_F)
#define KC_TBALT MT(MOD_LALT, KC_TAB)
#define KC_MESC LT(_MACROS, KC_ESC)
#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_OLCK LSFT(LCTL(KC_PWR))

enum custom_keycodes {
  KC_INCL = SAFE_RANGE,
  KC_PULL,
  KC_PUSH,
  KC_GCOUT,
  KC_GCNEW,
  KC_GCMT,
  KC_SCAP,
  KC_SCOF
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     KC_MESC, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,KC_GRV,      KC_BSLS, KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSPC,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_TBALT,  KC_A,   KC_S,   KC_D, KC_F  , KC_G  ,KC_MINLH,      KC_EQL, KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_LSFT,KC_NAVZ, KC_X  , KC_C  , KC_V  , KC_B  ,KC_NPLBR,      KC_SBRC, KC_N  , KC_M  ,KC_COMM,KC_DOT,KC_NAVSL,KC_ENT,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     KC_SPCTL,KC_GENT,                      KC_SFSP ,KC_SPFN
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),
  [_CAPS] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     KC_MESC, KC_Q,  KC_C,   KC_H,    KC_P,    KC_V ,KC_GRV,      KC_BSLS, KC_K,   KC_Y,   KC_O , KC_J,    KC_QUOT,KC_BSPC,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_TBALT, KC_R,  KC_S,   KC_N,    KC_T,    KC_G,KC_MINLH,      KC_EQL, KC_W,   KC_U,   KC_E,    KC_I, KC_A,  KC_SCLN,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_LSFT,LT(_NAV, KC_X) , KC_M,   KC_L,    KC_D,    KC_B,KC_NPLBR,      KC_SBRC, KC_Z,   KC_F,KC_COMM,KC_DOT,KC_NAVSL,KC_ENT,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     KC_SPCTL,KC_GENT,                      KC_SFSP ,KC_SPFN
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_NUMPAD] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     _______,KC_1   ,  KC_2 ,  KC_3 ,  KC_4 ,  KC_5 ,_______,      _______,KC_1   ,  KC_2 ,  KC_3 ,  KC_4 ,  KC_5 ,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______, KC_6  , KC_7  , KC_8  , KC_9  ,  KC_0 ,_______,      _______, KC_6  , KC_7  , KC_8  , KC_9  ,  KC_0 ,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,_______,      _______,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,                      _______,_______
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_SYMBOLS] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     KC_ESC, KC_J, KC_K, KC_M, KC_QUOT, KC_MINUS,DF(_CAPS),      _______,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSLS,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_SCLN, KC_Y, KC_P, KC_L,  KC_DOT, KC_Q, KC_F6 ,      _______,KC_TILD,KC_COLN,KC_UNDS,KC_LCBR,KC_RCBR,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_LSFT, KC_X, KC_B, KC_V, KC_COMMA, KC_Z ,KC_F12,      _______,KC_GRV ,KC_SCLN,KC_MINS,KC_LBRC,KC_RBRC,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,                      _______,_______
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_NAV] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     _______,_______,_______, KC_UP ,_______,KC_PSCR,_______,      _______,_______,_______,KC_MS_UP,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,      _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,_______,KC_PGUP,KC_PGDN,_______,KC_DEL ,_______,      _______,_______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     KC_LCTL,_______,                      KC_BTN1,KC_BTN2
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_MACROS] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     _______,_______,_______,_______,_______,_______,KC_OLCK,      _______,_______,_______,KC_INCL,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     _______,_______,_______,KC_CAD ,_______,_______,DF(_QWERTY),      _______,_______,KC_GCOUT,KC_GCMT,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_SCAP,_______,_______,_______,_______,_______,DF(_CAPS),      _______,KC_GCNEW,_______,KC_PULL,KC_PUSH,_______,KC_SCAP,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                     _______,_______,                      _______,_______
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    /* include some kind of library or header */
    case KC_INCL:
      if (record->event.pressed) {
        SEND_STRING("#include <>" SS_TAP(X_LEFT));
      }
      return false;
    case KC_PULL:
      if (record->event.pressed) {
        SEND_STRING("git fetch && git pull" SS_TAP(X_ENTER));
      }
      return false;
    case KC_PUSH:
      if (record->event.pressed){
        SEND_STRING("git push" SS_TAP(X_ENTER));
      }
      return false;
   case KC_GCMT:
      if (record->event.pressed) {
        SEND_STRING("git commit -m " SS_TAP(X_RIGHT));
      }
      return false;
   case KC_GCOUT:
      if (record->event.pressed) {
        SEND_STRING("git checkout " SS_TAP(X_RIGHT));
      }
      return false;
   case KC_GCNEW:
      if (record->event.pressed) {
        SEND_STRING("git checkout -b " SS_TAP(X_RIGHT));
      }
      return false;
    case KC_SCAP:
      if (record->event.pressed){
        layer_on(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }
      return false;
    case KC_SCOF:
      if (record->event.pressed){
        layer_off(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }
      return false;
  }
  return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
	//
};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _QWERTY:
          set_led_off;
          break;
        case _CAPS:
            set_led_green;
            break;
        case _NUMPAD:
            set_led_blue;
            break;
        case _SYMBOLS:
            set_led_red;
            break;
        case _NAV:
            set_led_magenta;
            break;
        case _MACROS:
            set_led_cyan;
            break;
        default:
            set_led_off;
            break;
    }
};
