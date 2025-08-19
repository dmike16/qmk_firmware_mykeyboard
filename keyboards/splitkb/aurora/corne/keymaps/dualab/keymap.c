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

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+--------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  |  ESC   |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+--------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |                                  |   H  |   J  |   K  |   L  |   ;  |  '     |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+--------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |                                  |   N  |   M  |   ,  |   .  |   /  | ENTER  |
 * `----------------------------------------------------------/     \-------\-----------------------------------------------'
 *                                   | LGUI |LOWER |  Space  /       \BackSP   |RAISE | RALT |
 *                                   |      |      |        /         \        |      |      |
 *                                   `----------------------'          '------''-------------'
 */

    [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_ESC ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, LOWER ,  KC_SPC,     KC_BSPC, RAISE , KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

/* LOWER
 * |------+------+------+------+------+------|                                  |------+------+------+-------+------+--------|
 * | Tab  |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9   |   0  | QLLOCK |
 * |------+------+------+------+------+------|                                  |------+------+------+-------+------+--------|
 * |LCTRL |      |      |      |      |      |                                  | LEFT | DOWN |  UP  | RIGHT | F11  |  F12   |
 * |------+------+------+------+------+------|                                  |------+------+------+-------+------+--------|
 * |LShift| F1   | F2   | F3   | F4   | F5   |                                  |  F6  |  F7  |  F8  |   F9  | F10  |  ENTER |
 * `-------------------------------------------------------------/    \-------\----------------------------------------------'
 *                                      | LGUI |LOWER |  Space  /      \BackSP   | ADJUST | RALT |
 *                                      |      |      |        /        \        |        |      |
 *                                      `----------------------'         '------''---------------'
 */

    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, QK_LLCK,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,  KC_UP ,KC_RIGHT, KC_F11 , KC_F12 ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,                       KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_BSPC,   ADJUST, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

/* RAISE
 * |------+------+------+------+------+------|                                  |------+------+------+-------+------+--------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |                                  |   ^  |   &  |   *  |   (   |   )  | QLLOCK |
 * |------+------+------+------+------+------|                                  |------+------+------+-------+------+--------|
 * |LCTRL |      |      |      |      |      |                                  |   -  |   =  |  [   |   ]   |   \  |   `    |
 * |------+------+------+------+------+------|                                  |------+------+------+-------+------+--------|
 * |LShift|      |      |      |      |      |                                  |   _  |   +  |  {   |   }   |   |  |   ~    |
 * `-------------------------------------------------------------/    \-------\----------------------------------------------'
 *                                      | LGUI |ADJUST|  Space  /      \BackSP   | ADJUST | RALT |
 *                                      |      |      |        /        \        |        |      |
 *                                      `----------------------'         '------''---------------'
 */
    [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   ADJUST,  KC_SPC,     KC_BSPC, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

/* ADJUST
 * |------+------+------+------+------+------|                                  |------+------+------+-------+------+--------|
 * |      |      |      |      |      |      |                                  |      |      |      |       |      | QLLOCK |
 * |------+------+------+------+------+------|                                  |------+------+------+-------+------+--------|
 * |      |      |      |      |      |      |                                  |  BU  |  BD  |  VDN |  VUP  | MUTE |        |
 * |------+------+------+------+------+------|                                  |------+------+------+-------+------+--------|
 * |      |      |      |      |      |      |                                  |      |      |      |       |      |        |
 * `---------------------------------------------------------/         \-------\---------------------------------------------'
 *                                  | LGUI |LOWER |  Space  /           \BackSP   | ADJUST | RALT |
 *                                  |      |      |        /             \        |        |      |
 *                                  `----------------------'              '------''---------------'
 */
    [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,--------------------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX          , XXXXXXX        , XXXXXXX  , _______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_BRID, KC_BRIU, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_KB_MUTE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+-----------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX          , XXXXXXX        , XXXXXXX   , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+-----------------------------|
                                          KC_LGUI, _______,  KC_SPC,     KC_BSPC, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
