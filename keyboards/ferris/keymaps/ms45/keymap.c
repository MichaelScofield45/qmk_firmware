#include QMK_KEYBOARD_H

#define LG(arg) LGUI_T(arg)
#define LS(arg) LSFT_T(arg)
#define LA(arg) LALT_T(arg)
#define LC(arg) LCTL_T(arg)

enum layers {
    BASE,
    NUM,
    SYM,
    NAV,
    FUN,
    GAME,
    MEDIA,
    NOTE
};

const uint16_t PROGMEM esc_combo[] = {LT(NAV, KC_BSPC), RALT_T(KC_TAB), COMBO_END};
const uint16_t PROGMEM del_combo[] = {LT(SYM, KC_ENT), LT(NUM, KC_SPACE), COMBO_END};
const uint16_t PROGMEM fun_combo[] = {LT(NAV, KC_BSPC), LT(NUM, KC_SPACE), COMBO_END};
const uint16_t PROGMEM media_combo[] = {RALT_T(KC_TAB), LT(SYM, KC_ENT), COMBO_END};
const uint16_t PROGMEM game_combo[] = {LT(NAV, KC_BSPC), RALT_T(KC_TAB), LT(SYM, KC_ENT), LT(NUM, KC_SPACE), COMBO_END};
const uint16_t PROGMEM ungame_combo[] = {KC_COMM, KC_P, COMBO_END};
const uint16_t PROGMEM note_combo[] = {LT(NAV, KC_BSPC), LT(SYM, KC_ENT), COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(del_combo, KC_DEL),
    COMBO(fun_combo, MO(FUN)),
    COMBO(media_combo, MO(MEDIA)),
    COMBO(game_combo, TG(GAME)),
    COMBO(ungame_combo, TG(GAME)),
    COMBO(note_combo, TG(NOTE)),
};

enum custom_keycodes {
    XOUR_PEN = SAFE_RANGE,
    XOUR_REC,
    XOUR_FRE,
    XOUR_SAV
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case XOUR_PEN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT("p")));
            }
            break;
        case XOUR_REC:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT("r")));
            }
            break;
        case XOUR_FRE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT("g")));
            }
            break;
        case XOUR_SAV:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("s"));
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_split_3x5_2(
        KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,      KC_J,    KC_L,     KC_U,     KC_Y,      KC_SCLN,
        LG(KC_A), LA(KC_R), LC(KC_S), LS(KC_T), KC_G,      KC_M,    LS(KC_N), LC(KC_E), LA(KC_I),  LG(KC_O),
        KC_X,     KC_C,     KC_D,     KC_V,     KC_Z,      KC_K,    KC_H,     KC_COMM,  KC_DOT,    KC_SLSH,
                    LT(NAV, KC_BSPC), RALT_T(KC_TAB),      LT(SYM, KC_ENT), LT(NUM, KC_SPACE)
    ),
	[NUM] = LAYOUT_split_3x5_2(

        KC_LBRC,  KC_7,     KC_8,     KC_9,     KC_RBRC,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_MINUS, KC_4,     KC_5,     KC_6,     KC_EQL,            XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_GRAVE, KC_1,     KC_2,     KC_3,     KC_BSLS,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      KC_0,     RALT_T(KC_QUOT),   XXXXXXX, XXXXXXX
    ),
	[SYM] = LAYOUT_split_3x5_2(
        KC_LCBR,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RCBR,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_UNDS,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_PLUS,           XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_PIPE,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      KC_RPRN,  KC_DQUO,           XXXXXXX, XXXXXXX
    ),
	[NAV] = LAYOUT_split_3x5_2(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,           KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
        QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                      XXXXXXX,  XXXXXXX,           XXXXXXX, XXXXXXX
    ),
	[FUN] = LAYOUT_split_3x5_2(
        XXXXXXX,  KC_F7,    KC_F8,    KC_F9,    KC_F10,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,  KC_F4,    KC_F5,    KC_F6,    KC_F11,            XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F12,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      XXXXXXX,  XXXXXXX,           XXXXXXX, XXXXXXX
    ),
	[GAME] = LAYOUT_split_3x5_2(
        KC_G,     KC_Q,     KC_W,     KC_E,     KC_R,              XXXXXXX, KC_I,    KC_O,    KC_P,    KC_COMM,
        KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,              XXXXXXX, KC_J,    XXXXXXX, XXXXXXX, KC_TAB,
        KC_LCTL,  KC_X,     XXXXXXX,  KC_C,     KC_Z,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      KC_SPACE, KC_V,              XXXXXXX, XXXXXXX
    ),
	[MEDIA] = LAYOUT_split_3x5_2(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,  XXXXXXX,  KC_MPRV,  KC_VOLD,  XXXXXXX,           XXXXXXX, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                       XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX
    ),
	[NOTE] = LAYOUT_split_3x5_2(
        TG(NOTE), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_DEL,   XOUR_FRE, XOUR_REC, XOUR_PEN, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      XOUR_SAV, XXXXXXX,           XXXXXXX, XXXXXXX
    ),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
