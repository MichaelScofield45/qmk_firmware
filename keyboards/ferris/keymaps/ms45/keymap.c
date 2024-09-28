#include QMK_KEYBOARD_H
#include "keymap_us_international.h"
#include "sendstring_us_international.h"

enum layers {
    BASE,
    NUM,
    SYM,
    NAV,
    FUN,
    GAME
};

const uint16_t PROGMEM esc_combo[] = {LT(NAV, KC_BSPC), RALT_T(KC_TAB), COMBO_END};
const uint16_t PROGMEM del_combo[] = {LT(SYM, KC_ENT), LT(NUM, KC_SPACE), COMBO_END};
const uint16_t PROGMEM game_combo[] = {LT(NAV, KC_BSPC), RALT_T(KC_TAB), LT(SYM, KC_ENT), LT(NUM, KC_SPACE), COMBO_END};
const uint16_t PROGMEM ungame_combo[] = {KC_SPACE, LALT_T(KC_F), COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(del_combo, KC_DEL),
    COMBO(game_combo, TG(GAME)),
    COMBO(ungame_combo, TG(GAME)),
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
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_UNDS, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,   KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,   KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,
                                KC_RPRN,   KC_DQUO,    KC_TRNS, KC_TRNS
    ),
	[NAV] = LAYOUT_split_3x5_2(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_NO,   KC_NO, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
        QK_BOOT, KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                   TO(BASE), KC_NO,   OSM(MOD_LCTL), TO(NUM)
    ),
	[FUN] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W, KC_W, KC_R, KC_T,          KC_NO, KC_NO,   US_UACU, KC_NO,   KC_NO,
        KC_UNDS, KC_F4,  KC_F5, KC_F6, KC_PLUS,   KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_LCTL, KC_F1, KC_F2, KC_F3, KC_B,       KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                              KC_NO, KC_NO,       KC_TRNS, KC_NO
    ),
	[GAME] = LAYOUT_split_3x5_2(
        KC_G,    KC_Q, KC_W, KC_E, KC_R,   KC_NO, KC_NO,   US_UACU, KC_NO,   KC_NO,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F,   KC_NO, KC_J, US_EACU, US_IACU, US_OACU,
        KC_LCTL, KC_X, KC_NO, KC_C, KC_B,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_SPACE, LALT_T(KC_F),   KC_TRNS, KC_NO
    ),
	[6] = LAYOUT_split_3x5_2(TG(6), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_NO, LCTL(KC_LALT), KC_TRNS, KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[7] = LAYOUT_split_3x5_2(KC_PSLS, KC_7, KC_8, KC_9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_PAST, KC_4, KC_5, KC_6, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

