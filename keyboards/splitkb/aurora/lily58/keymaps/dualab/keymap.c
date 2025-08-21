#include "action_layer.h"
#include "keyboard.h"
#include "oled_driver.h"
#include "progmem.h"
#include "quantum.h"
#include QMK_KEYBOARD_H
#include "../lib/oled_common.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define RAISE_COLEMAK_DH MO(_RAISE_COLEMAK_DH)
#define ADJUST MO(_ADJUST)
#define QWERTY PDF(_QWERTY)
#define COLEMAK_DH PDF(_COLEMAK_DH)

enum layer_number {
    _QWERTY = 0,
    _COLEMAK_DH,
    _LOWER,
    _RAISE,
    _RAISE_COLEMAK_DH,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \       \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP \  |RAISE |ENTER | RGUI   |
     *                   |      |      |      |/       /         \       \ |      |      |        |
     *                   `----------------------------'           '------''-----------------------'
     */

    [_QWERTY] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,
                       KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
                       KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                       KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                       KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_BSPC, RAISE, KC_ENT, KC_RGUI
                       ),
    /* COLEMAK_DH
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LCTRL |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LShift|   X  |   C  |   D  |   V  |   Z  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \       \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP \  |RAISE |ENTER | RGUI   |
     *                   |      |      |      |/       /         \       \ |      |      |        |
     *                   `----------------------------'           '------''-----------------------'
     */

    [_COLEMAK_DH] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,
                           KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS,
                           KC_LCTL, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
                           KC_LSFT, KC_X, KC_C, KC_D, KC_V, KC_Z, KC_LBRC, KC_RBRC, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                           KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_BSPC, RAISE_COLEMAK_DH, KC_ENT, KC_RGUI
                           ),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      | llck |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  f1  |  f2  |  f3  |  f4  |  f5  |  f6  |                    |  f7  |  f8  |  f9  | f10  | f11  | f12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
     * `-----------------------------------------/       /     \       \----------------------------------------'
     *                   | lalt | lgui |lower | /space  /       \backsp \  |raise |enter | rgui   |
     *                   |      |      |      |/       /         \       \ |      |      |        |
     *                   `----------------------------'           '------''-----------------------'
     */
    [_LOWER] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_LLCK,
                      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
                      KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
                      _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                      _______, _______, _______, _______, _______, _______, _______, KC_RGUI
                      ),
    /* RAISE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      | LLCK |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------| Left | Down |  Up  | Right|      |      |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   <  |   >  |   \  |
     * `-----------------------------------------/       /     \       \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP \  |RAISE |ENTER | RGUI   |
     *                   |      |      |      |/       /         \       \ |      |      |        |
     *                   `----------------------------'           '------''-----------------------'
     */

    [_RAISE] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______,
                      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
                      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, KC_PLUS, KC_MINS, KC_EQL, KC_LT, KC_GT, KC_BSLS,
                      _______, _______, _______, _______, _______, _______, _______, KC_RGUI
                      ),
    /* RAISE COLEMAK_DH
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      | LLCK |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |                    | Down | LEFT |   6  |   7  |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|   +  |   -  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|  UP  | Right|   =  |   <  |   >  |   \  |
     * `-----------------------------------------/       /     \       \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP \  |RAISE |ENTER | RGUI   |
     *                   |      |      |      |/       /         \       \ |      |      |        |
     *                   `----------------------------'           '------''-----------------------'
     */

    [_RAISE_COLEMAK_DH] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_DOWN, KC_LEFT, KC_6, KC_7, _______, _______,
                                 KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_PLUS, KC_MINS, KC_8, KC_9, KC_0, XXXXXXX,
                                 KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, KC_UP, KC_RGHT, KC_EQL, KC_LT, KC_GT, KC_BSLS,
                                 _______, _______, _______, _______, _______, _______, _______, KC_RGUI
                                 ),

    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | REBOOT |      |      |      |      |      |                    |      |      |      |      |      | LLCK |
     * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | BOOT   |      |      |      |      |      |                    | VOL- | BRI- |      |      |      |      |
     * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |        |      |      |      |      |      |-------.    ,-------| MUTE |      |      |      |      |      |
     * |--------+------+------+------+------+------|  C-DH |    | QWT   |------+------+------+------+------+------|
     * |        |      |      |      |      |      |-------|    |-------| VOL+ | BRI+ |      |      |      |      |
     * `-----------------------------------------/       /     \       \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP \  |RAISE |ENTER | RGUI   |
     *                   |      |      |      |/       /         \       \ |      |      |        |
     *                   `----------------------------'           '------''-----------------------'
     */
    [_ADJUST] = LAYOUT(QK_REBOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                       QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KB_VOLUME_DOWN, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KB_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK_DH, QWERTY, KC_KB_VOLUME_UP, KC_BRIU, XXXXXXX, XXXXXXX,
                       XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    if (layer_state_cmp(state, _ADJUST)) {
        return state;
    }
    return update_tri_layer_state(state, _LOWER, _RAISE_COLEMAK_DH, _ADJUST);
}

#ifdef OLED_ENABLE

void oled_render_boot(bool bootloader) {
    oled_clear();
    oled_set_cursor(0, 1);
    if (bootloader) {
        oled_write_P(PSTR("Awaiting New Firmware "), false);
    } else {
        oled_write_P(PSTR("Rebooting "), false);
    }
    oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
    return false;
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _LOWER:
            oled_write_P(lower_layer, false);
            break;
        case _RAISE: case _RAISE_COLEMAK_DH:
            oled_write_P(raise_layer, false);
            break;
        case _ADJUST:
            oled_write_P(adjust_layer, false);
            break;
        default:
            oled_write_P(default_layer, false);
    }
}

static void render_layout(void) {
    if(IS_LAYER_ON_STATE(layer_state | default_layer_state ,_COLEMAK_DH)) {
        oled_write_P(PSTR("COLDH"), false);
    } else {
        oled_write_P(PSTR("QWRTY"), false);
    }
}

bool oled_task_user(void){
    if(!is_keyboard_master()){
        return true;
    }

    // Renders the current keyboard state (layers and mods)
    render_logo();
    render_logo_text();
    render_layout();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());

    return false;
}

#endif
