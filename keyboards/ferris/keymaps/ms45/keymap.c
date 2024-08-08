#include QMK_KEYBOARD_H
#include "keymap_us_international.h"
#include "sendstring_us_international.h"

enum layers {
    BASE,
    NUM,
    SYM,
    NAV,
    GAME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_split_3x5_2(
          KC_Q, KC_W, KC_F, KC_P, KC_B,   KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN,
          KC_A, KC_R, KC_S, KC_T, KC_G,   KC_M, KC_N, KC_E,    KC_I,   KC_O,
          KC_X, KC_C, KC_D, KC_V, KC_Z,   KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,
       RALT_T(KC_SPACE), OSM(MOD_LSFT),   KC_LCTL, TO(NUM)
    ),
	[NUM] = LAYOUT_split_3x5_2(

        KC_ESC,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC,       KC_AMPR, KC_ASTR, KC_NO,   KC_BSPC,
        KC_TAB,  KC_2,    KC_3,    KC_4,    KC_5,       KC_6,          KC_7,    KC_8,    KC_9,    KC_ENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PDOT,    OSM(MOD_LALT), KC_NO,   KC_TRNS, KC_TRNS, TO(SYM),
                             TO(BASE), LSFT_T(KC_1),    LCTL_T(KC_0), TO(NAV)
    ),
	[SYM] = LAYOUT_split_3x5_2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_EQL,  KC_QUOT, KC_DQUO, KC_MINUS,   KC_BSLS, KC_LBRC, KC_RBRC, KC_PIPE, KC_TRNS,
        KC_TILD, KC_GRV,  KC_NO,   KC_NO,   KC_EXLM,    KC_PLUS, KC_LPRN, KC_RPRN, KC_NO,   TO(NAV),
                                TO(BASE),   KC_LSFT,    KC_TRNS, TO(GAME)
    ),
	[NAV] = LAYOUT_split_3x5_2(
        KC_NO,   KC_NO,   KC_UP,   KC_NO,    KC_VOLU,   KC_NO,   KC_BTN1, KC_WH_U, KC_BTN2, KC_NO,
        KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_VOLD,   OSM(MOD_LGUI),   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        QK_BOOT, KC_NO,   KC_NO,   KC_NO,    KC_NO,     OSM(MOD_LSFT),   KC_WH_L, KC_WH_D, KC_WH_R, TO(GAME),
                                   TO(BASE), KC_NO,     OSM(MOD_LCTL), TO(NUM)
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





