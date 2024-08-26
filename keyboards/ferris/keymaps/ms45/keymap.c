#include QMK_KEYBOARD_H
#include "keymap_us_international.h"
#include "sendstring_us_international.h"

enum layers {
    BASE,
    NUM,
    SYM,
    NAV,
    CREATIVE,
    GAME
};

const uint16_t PROGMEM esc_combo[] = {LT(NAV, KC_BSPC), RALT_T(KC_TAB), COMBO_END};
const uint16_t PROGMEM del_combo[] = {LT(SYM, KC_ENT), LT(NUM, KC_SPACE), COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(del_combo, KC_DEL),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_split_3x5_2(
          KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,   KC_J, KC_L,         KC_U,         KC_Y,          KC_SCLN,
          LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,   KC_M, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I),  LGUI_T(KC_O),
          KC_X,         KC_C,         KC_D,         KC_V,         KC_Z,   KC_K, KC_H,         KC_COMM,      KC_DOT,        KC_SLSH,
                               LT(NAV, KC_BSPC), RALT_T(KC_TAB),   LT(SYM, KC_ENT), LT(NUM, KC_SPACE)
    ),
	[NUM] = LAYOUT_split_3x5_2(

        KC_LBRC,  KC_7, KC_8, KC_9, KC_RBRC,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_MINUS, KC_4, KC_5, KC_6, KC_EQL,    KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_GRAVE, KC_1, KC_2, KC_3, KC_BSLS,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                              KC_0, KC_QUOT,   KC_TRNS, KC_TRNS
    ),
	[SYM] = LAYOUT_split_3x5_2(
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_UNDS, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,   KC_BSLS, KC_LBRC, KC_RBRC, KC_PIPE, KC_TRNS,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,   KC_PLUS, KC_LPRN, KC_RPRN, KC_NO,   TO(NAV),
                                KC_RPRN,   KC_DQUO,    KC_TRNS, KC_TRNS
    ),
	[NAV] = LAYOUT_split_3x5_2(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_NO,   KC_NO, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
        QK_BOOT, KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                   TO(BASE), KC_NO,   OSM(MOD_LCTL), TO(NUM)
    ),
	[CREATIVE] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W, KC_W, KC_R, KC_T,   KC_NO, KC_NO,   US_UACU, KC_NO,   KC_NO,
        KC_LSFT, KC_A, KC_Z, KC_LALT, KC_G,   KC_NO, US_NTIL, US_EACU, US_IACU, US_OACU,
        KC_LCTL, KC_X, KC_C, KC_LSFT, KC_B,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                     TO(BASE), KC_LCTL,   KC_TRNS, KC_NO
    ),
	[GAME] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W, KC_W, KC_R, KC_T,   KC_NO, KC_NO,   US_UACU, KC_NO,   KC_NO,
        KC_LSFT, KC_A, KC_S, KC_D, KC_G,   KC_NO, US_NTIL, US_EACU, US_IACU, US_OACU,
        KC_LCTL, KC_X, KC_C, KC_V, KC_B,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                     TO(BASE), KC_SPACE,   KC_TRNS, KC_NO
    ),
	[5] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_NO, LCTL(KC_LALT), KC_TRNS, KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[6] = LAYOUT_split_3x5_2(KC_PSLS, KC_7, KC_8, KC_9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_PAST, KC_4, KC_5, KC_6, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[7] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_COLN, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_PERC, KC_SLSH, KC_ENT, KC_TRNS, TO(1), KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EXLM, KC_TRNS, TO(0), KC_TRNS, RALT_T(KC_COMM), RCTL_T(KC_DOT), QK_BOOT, KC_TRNS, KC_TAB, KC_NO, KC_TRNS)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

