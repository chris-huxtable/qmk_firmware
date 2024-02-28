/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  SLP_DSP,
  LCK_DSP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 *
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   :  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   <  |   >  |   ?  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  _______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |Sleep |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  | Home |      |  \   |  |   |  -   |   _  |   |  |   /  |      | End  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  | Pg Up|  [   |  (   |  {   |  <   |   >  |   }  |   )  |   ]  | Pg Dn|  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |  +   |  -   |   _  |   =  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol+ | Vol- | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  SLP_DSP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC,
  KC_TAB,  KC_HOME, XXXXXXX, KC_BSLS, KC_PIPE, KC_PMNS, KC_UNDS, KC_PIPE, KC_PSLS, XXXXXXX, KC_END,  KC_DEL,
  KC_TILD, KC_PGUP, KC_LABK, KC_LPRN, KC_LCBR, KC_LBRC, KC_RPRN, KC_RBRC, KC_RCBR, KC_RABK, KC_PGDN, KC_PIPE,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PPLS, KC_PMNS, KC_UNDS, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLU, KC_VOLD, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | LkDp |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  | Home |      |  \   |  |   |  -   |   _  |   |  |   /  |      | End  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  | Pg Up|  [   |  (   |  {   |  <   |   >  |   }  |   )  |   ]  | Pg Dn|  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |  +   |  -   |   _  |   =  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol+ | Vol- | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  LCK_DSP,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
  KC_TAB,  KC_HOME, XXXXXXX, KC_BSLS, KC_PIPE, KC_PMNS, KC_UNDS, KC_PIPE, KC_PSLS, XXXXXXX, KC_END,  KC_DEL,
  KC_TILD, KC_PGUP, KC_LABK, KC_LPRN, KC_LCBR, KC_LBRC, KC_RPRN, KC_RBRC, KC_RCBR, KC_RABK, KC_PGDN, KC_BSLS,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PPLS, KC_PMNS, KC_UNDS, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLU, KC_VOLD, KC_MPLY

),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |RGBTog|  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|      |      |      |      |RGBMod|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|      |      |      |      |RGBBre|RGBNor|RGBRMod|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      | Bklgt|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, RGB_TOG, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, XXXXXXX, XXXXXXX,  XXXXXXX, _______, RGB_MOD,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  XXXXXXX, XXXXXXX, _______, _______,  RGB_M_B, RGB_M_P, RGB_RMOD,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_RSFT
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case SLP_DSP:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            register_code(KC_RCTL);
            register_code(KC_POWER);
          } else {
            unregister_code(KC_RSFT);
            unregister_code(KC_RCTL);
            unregister_code(KC_POWER);
          }
          return false;
          break;
        case LCK_DSP:
          if (record->event.pressed) {
            register_code(KC_RCMD);
            register_code(KC_RCTL);
            register_code(KC_Q);
          } else {
            unregister_code(KC_RCMD);
            unregister_code(KC_RCTL);
            unregister_code(KC_Q);
          }
        return false;
        break;
      }
    return true;
};
