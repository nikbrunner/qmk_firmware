/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    //
    LY_BAS,
    LY_EXT,
    LY_SYM,
    LY_NUM,
    LY_FUN,
    LY_MED
};

enum custom_keycodes { SS_TILD_SLSH = SAFE_RANGE, SS_WA, SS_WQ };

enum tap_dance_codes {
    //
    TD_EXT_GUI_A,
    TD_EXT_GUI_S,
    TD_EXT_GUI_D,
    TD_EXT_GUI_F
};

// KEYMAP ===============================================================================
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_split_3x5_3(
//    ┌───────────┬───────────┬───────────┬────────────┬────────────┐   ┌─────────────┬────────────┬───────────┬───────────┬───────────┐
//    │     q     │     w     │     e     │     r      │     t      │   │      y      │     u      │     i     │     o     │     p     │
//    ├───────────┼───────────┼───────────┼────────────┼────────────┤   ├─────────────┼────────────┼───────────┼───────────┼───────────┤
//    │ LGUI_T(a) │ LALT_T(s) │ LCTL_T(d) │ LSFT_T(f)  │     g      │   │      h      │ RSFT_T(j)  │ RCTL_T(k) │ LALT_T(l) │ RGUI_T(;) │
//    ├───────────┼───────────┼───────────┼────────────┼────────────┤   ├─────────────┼────────────┼───────────┼───────────┼───────────┤
//    │     z     │     x     │     c     │     v      │     b      │   │      n      │     m      │     ,     │     .     │     /     │
//    └───────────┴───────────┼───────────┼────────────┼────────────┤   ├─────────────┼────────────┼───────────┼───────────┴───────────┘
//                            │ LT(3, no) │ LT(2, esc) │ LT(1, spc) │   │ LT(5, bspc) │ LT(2, ent) │ LT(4, no) │
//                            └───────────┴────────────┴────────────┘   └─────────────┴────────────┴───────────┘
  KC_Q         , KC_W         , KC_E         , KC_R          , KC_T          ,     KC_Y           , KC_U          , KC_I         , KC_O         , KC_P           ,
  LGUI_T(KC_A) , LALT_T(KC_S) , LCTL_T(KC_D) , LSFT_T(KC_F)  , KC_G          ,     KC_H           , RSFT_T(KC_J)  , RCTL_T(KC_K) , LALT_T(KC_L) , RGUI_T(KC_SCLN),
  KC_Z         , KC_X         , KC_C         , KC_V          , KC_B          ,     KC_N           , KC_M          , KC_COMM      , KC_DOT       , KC_SLSH        ,
                                LT(3, KC_NO) , LT(2, KC_ESC) , LT(1, KC_SPC) ,     LT(5, KC_BSPC) , LT(2, KC_ENT) , LT(4, KC_NO)
),

[LY_EXT] = LAYOUT_split_3x5_3(
//    ┌──────────────────┬──────────────────┬──────────────────┬──────────────────┬────────────┐   ┌──────┬────────┬───────────┬───────────┬────┐
//    │     LGUI(q)      │     LGUI(w)      │     LGUI(e)      │     LGUI(r)      │  LGUI(t)   │   │  no  │ LAG(i) │  LGUI(`)  │ LGUI(tab) │ no │
//    ├──────────────────┼──────────────────┼──────────────────┼──────────────────┼────────────┤   ├──────┼────────┼───────────┼───────────┼────┤
//    │ TD(TD_EXT_GUI_A) │ TD(TD_EXT_GUI_S) │ TD(TD_EXT_GUI_D) │ TD(TD_EXT_GUI_F) │  LGUI(g)   │   │ left │  down  │    up     │   rght    │ no │
//    ├──────────────────┼──────────────────┼──────────────────┼──────────────────┼────────────┤   ├──────┼────────┼───────────┼───────────┼────┤
//    │     LGUI(z)      │     LGUI(x)      │     LGUI(c)      │     LGUI(v)      │  LGUI(b)   │   │  no  │   no   │ LSFT(tab) │    tab    │ no │
//    └──────────────────┴──────────────────┼──────────────────┼──────────────────┼────────────┤   ├──────┼────────┼───────────┼───────────┴────┘
//                                          │        no        │        no        │ TO(LY_BAS) │   │ del  │   no   │    no     │
//                                          └──────────────────┴──────────────────┴────────────┘   └──────┴────────┴───────────┘
  LGUI(KC_Q)       , LGUI(KC_W)       , LGUI(KC_E)       , LGUI(KC_R)       , LGUI(KC_T) ,     KC_NO   , LAG(KC_I) , LGUI(KC_GRV) , LGUI(KC_TAB) , KC_NO,
  TD(TD_EXT_GUI_A) , TD(TD_EXT_GUI_S) , TD(TD_EXT_GUI_D) , TD(TD_EXT_GUI_F) , LGUI(KC_G) ,     KC_LEFT , KC_DOWN   , KC_UP        , KC_RGHT      , KC_NO,
  LGUI(KC_Z)       , LGUI(KC_X)       , LGUI(KC_C)       , LGUI(KC_V)       , LGUI(KC_B) ,     KC_NO   , KC_NO     , LSFT(KC_TAB) , KC_TAB       , KC_NO,
                                        KC_NO            , KC_NO            , TO(LY_BAS) ,     KC_DEL  , KC_NO     , KC_NO
),

[LY_SYM] = LAYOUT_split_3x5_3(
//    ┌───┬───┬─────┬────────────┬─────┐   ┌─────┬────────────┬─────┬───┬───┐
//    │ ^ │ + │  #  │     %      │  $  │   │  <  │     {      │  "  │ } │ > │
//    ├───┼───┼─────┼────────────┼─────┤   ├─────┼────────────┼─────┼───┼───┤
//    │ ! │ - │  &  │     ?      │  |  │   │  =  │     [      │  '  │ ] │ : │
//    ├───┼───┼─────┼────────────┼─────┤   ├─────┼────────────┼─────┼───┼───┤
//    │ ~ │ _ │  *  │     @      │ ~/  │   │  \  │     (      │  `  │ ) │ / │
//    └───┴───┼─────┼────────────┼─────┤   ├─────┼────────────┼─────┼───┴───┘
//            │     │ TO(LY_BAS) │     │   │     │ TO(LY_BAS) │     │
//            └─────┴────────────┴─────┘   └─────┴────────────┴─────┘
  KC_CIRC , KC_PLUS , KC_HASH , KC_PERC    , KC_DLR       ,     KC_LT   , KC_LCBR    , KC_DQUO , KC_RCBR , KC_GT  ,
  KC_EXLM , KC_MINS , KC_AMPR , KC_QUES    , KC_PIPE      ,     KC_EQL  , KC_LBRC    , KC_QUOT , KC_RBRC , KC_COLN,
  KC_TILD , KC_UNDS , KC_ASTR , KC_AT      , SS_TILD_SLSH ,     KC_BSLS , KC_LPRN    , KC_GRV  , KC_RPRN , KC_SLSH,
                      KC_TRNS , TO(LY_BAS) , KC_TRNS      ,     KC_TRNS , TO(LY_BAS) , KC_TRNS
),

[LY_NUM] = LAYOUT_split_3x5_3(
//    ┌──────────┬─────────┬──────┬──────┬─────┐   ┌──────┬──────┬──────┬──────┬──────┐
//    │ HYPR(no) │ MEH(no) │  no  │  no  │ no  │   │ kp_+ │ kp_7 │ kp_8 │ kp_9 │ kp_* │
//    ├──────────┼─────────┼──────┼──────┼─────┤   ├──────┼──────┼──────┼──────┼──────┤
//    │   lgui   │  lalt   │ lctl │ lsft │ no  │   │ kp_= │ kp_4 │ kp_5 │ kp_6 │  :   │
//    ├──────────┼─────────┼──────┼──────┼─────┤   ├──────┼──────┼──────┼──────┼──────┤
//    │    no    │   no    │  no  │  no  │ no  │   │ kp_- │ kp_1 │ kp_2 │ kp_3 │ kp_/ │
//    └──────────┴─────────┼──────┼──────┼─────┤   ├──────┼──────┼──────┼──────┴──────┘
//                         │      │      │     │   │  ,   │  .   │      │
//                         └──────┴──────┴─────┘   └──────┴──────┴──────┘
  HYPR(KC_NO) , MEH(KC_NO) , KC_NO   , KC_NO   , KC_NO   ,     KC_PPLS , KC_P7  , KC_P8   , KC_P9 , KC_PAST,
  KC_LGUI     , KC_LALT    , KC_LCTL , KC_LSFT , KC_NO   ,     KC_PEQL , KC_P4  , KC_P5   , KC_P6 , KC_COLN,
  KC_NO       , KC_NO      , KC_NO   , KC_NO   , KC_NO   ,     KC_PMNS , KC_P1  , KC_P2   , KC_P3 , KC_PSLS,
                             KC_TRNS , KC_TRNS , KC_TRNS ,     KC_COMM , KC_DOT , KC_TRNS
),

[LY_FUN] = LAYOUT_split_3x5_3(
//    ┌────┬────┬────┬────┬─────┐   ┌────┬──────┬──────┬─────────┬──────────┐
//    │ no │ f7 │ f8 │ f9 │ f12 │   │ no │  no  │  no  │ MEH(no) │ HYPR(no) │
//    ├────┼────┼────┼────┼─────┤   ├────┼──────┼──────┼─────────┼──────────┤
//    │ no │ f4 │ f5 │ f6 │ f11 │   │ no │ rsft │ rctl │  lalt   │   rgui   │
//    ├────┼────┼────┼────┼─────┤   ├────┼──────┼──────┼─────────┼──────────┤
//    │ no │ f1 │ f2 │ f3 │ f10 │   │ no │  no  │  no  │   no    │    no    │
//    └────┴────┼────┼────┼─────┤   ├────┼──────┼──────┼─────────┴──────────┘
//              │ no │ no │ no  │   │ no │  no  │  no  │
//              └────┴────┴─────┘   └────┴──────┴──────┘
  KC_NO , KC_F7 , KC_F8 , KC_F9 , KC_F12 ,     KC_NO , KC_NO   , KC_NO   , MEH(KC_NO) , HYPR(KC_NO),
  KC_NO , KC_F4 , KC_F5 , KC_F6 , KC_F11 ,     KC_NO , KC_RSFT , KC_RCTL , KC_LALT    , KC_RGUI    ,
  KC_NO , KC_F1 , KC_F2 , KC_F3 , KC_F10 ,     KC_NO , KC_NO   , KC_NO   , KC_NO      , KC_NO      ,
                  KC_NO , KC_NO , KC_NO  ,     KC_NO , KC_NO   , KC_NO
),

[LY_MED] = LAYOUT_split_3x5_3(
//    ┌────┬──────┬──────┬──────┬────────┐   ┌────┬─────────┬─────────┬─────────┬────┐
//    │ no │ vold │ mute │ volu │   no   │   │ no │ RGB_HUD │ RGB_TOG │ RGB_HUI │ no │
//    ├────┼──────┼──────┼──────┼────────┤   ├────┼─────────┼─────────┼─────────┼────┤
//    │ no │ mprv │ mply │ mnxt │ MEH(k) │   │ no │ LGUI(-) │ LGUI(0) │ LGUI(=) │ no │
//    ├────┼──────┼──────┼──────┼────────┤   ├────┼─────────┼─────────┼─────────┼────┤
//    │ no │  no  │  no  │  no  │   no   │   │ no │ DT_DOWN │ DT_PRNT │  DT_UP  │ no │
//    └────┴──────┼──────┼──────┼────────┤   ├────┼─────────┼─────────┼─────────┴────┘
//                │  no  │  no  │   no   │   │ no │   no    │   no    │
//                └──────┴──────┴────────┘   └────┴─────────┴─────────┘
  KC_NO , KC_VOLD , KC_MUTE , KC_VOLU , KC_NO     ,     KC_NO , RGB_HUD       , RGB_TOG    , RGB_HUI      , KC_NO,
  KC_NO , KC_MPRV , KC_MPLY , KC_MNXT , MEH(KC_K) ,     KC_NO , LGUI(KC_MINS) , LGUI(KC_0) , LGUI(KC_EQL) , KC_NO,
  KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO     ,     KC_NO , DT_DOWN       , DT_PRNT    , DT_UP        , KC_NO,
                    KC_NO   , KC_NO   , KC_NO     ,     KC_NO , KC_NO         , KC_NO
)
};
// clang-format on

// COMBO ================================================================================
const uint16_t PROGMEM togg_layer_ext_combo[] = {LT(LY_EXT, KC_SPC), LT(LY_MED, KC_BSPC), COMBO_END};
const uint16_t PROGMEM togg_layer_sym_combo[] = {LT(LY_SYM, KC_ESC), LT(LY_SYM, KC_ENT), COMBO_END};
const uint16_t PROGMEM togg_caps_word_combo[] = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM backspace[]            = {KC_H, RSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM save[]                 = {KC_W, LGUI_T(KC_A), COMBO_END};
const uint16_t PROGMEM save_quit[]            = {KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM num_zero[]             = {KC_P4, KC_P5, COMBO_END};
const uint16_t PROGMEM osm_hypr[]             = {LCTL_T(KC_D), RCTL_T(KC_K), COMBO_END};

// clang-format off
combo_t key_combos[] = {
    COMBO(togg_layer_ext_combo, TO(LY_EXT)),
    COMBO(togg_layer_sym_combo, TO(LY_SYM)),
    COMBO(togg_caps_word_combo, CW_TOGG),
    COMBO(backspace, KC_BSPC),
    COMBO(save, SS_WA),
    COMBO(save_quit, SS_WQ),
    COMBO(osm_hypr, OSM(MOD_HYPR)),
    COMBO(num_zero, KC_P0),
};
// clang-format on

// SEND STRING ==========================================================================
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SS_TILD_SLSH:
            if (record->event.pressed) {
                SEND_STRING("~/");
            }
            break;
        case SS_WA:
            if (record->event.pressed) {
                tap_code(KC_ESC);
                SEND_STRING(":wa");
                tap_code(KC_ENT);
            }
            break;
        case SS_WQ:
            if (record->event.pressed) {
                tap_code(KC_ESC);
                SEND_STRING(":wq");
                tap_code(KC_ENT);
            }
            break;
    }

    return true;
}

// TAP DANCE ============================================================================
enum tab_dance_events {
    //
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    MORE_TAPS
};

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        if (!state->pressed) {
            return DOUBLE_TAP;
        } else {
            return DOUBLE_HOLD;
        }
    }
    return MORE_TAPS;
}

void on_td_ext_gui_a(tap_dance_state_t *state, void *user_data) {
    uint8_t dance = dance_step(state);

    switch (dance) {
        case SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_A);
            unregister_code(KC_A);
            unregister_code(KC_LGUI);
            break;
        case SINGLE_HOLD:
            register_code(KC_LGUI);
            break;
    }
}

void reset_td_ext_gui_a(tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LGUI);
}

void on_td_ext_gui_s(tap_dance_state_t *state, void *user_data) {
    uint8_t dance = dance_step(state);

    switch (dance) {
        case SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_S);
            unregister_code(KC_S);
            unregister_code(KC_LGUI);
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
    }
}

void reset_td_ext_gui_s(tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LALT);
}

void on_td_ext_gui_d(tap_dance_state_t *state, void *user_data) {
    uint8_t dance = dance_step(state);

    switch (dance) {
        case SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_D);
            unregister_code(KC_D);
            unregister_code(KC_LGUI);
            break;
        case SINGLE_HOLD:
            register_code(KC_LCTL);
            break;
    }
}

void reset_td_ext_gui_d(tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LCTL);
}

void on_td_ext_gui_f(tap_dance_state_t *state, void *user_data) {
    uint8_t dance = dance_step(state);

    switch (dance) {
        case SINGLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_F);
            unregister_code(KC_F);
            unregister_code(KC_LGUI);
            break;
        case SINGLE_HOLD:
            register_code(KC_LSFT);
            break;
    }
}

void reset_td_ext_gui_f(tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LSFT);
}

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    [TD_EXT_GUI_A] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, on_td_ext_gui_a, reset_td_ext_gui_a),
    [TD_EXT_GUI_S] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, on_td_ext_gui_s, reset_td_ext_gui_s),
    [TD_EXT_GUI_D] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, on_td_ext_gui_d, reset_td_ext_gui_d),
    [TD_EXT_GUI_F] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, on_td_ext_gui_f, reset_td_ext_gui_f),
};
