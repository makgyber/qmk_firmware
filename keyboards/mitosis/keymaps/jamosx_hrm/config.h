#pragma once
#define AUTO_SHIFT_TIMEOUT 135

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Left-hand home row mods 
#define SFT_F LSFT_T(KC_F)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define GUI_V GUI_T(KC_V)

// Right-hand home row mods
#define GUI_M GUI_T(KC_M)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define SFT_J LSFT_T(KC_J)

#define COMBO_COUNT 12
