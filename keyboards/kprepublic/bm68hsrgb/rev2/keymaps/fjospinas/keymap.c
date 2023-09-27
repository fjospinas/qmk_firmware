 /* Copyright 2022 bdtc123
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

enum layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _FN,
  _MOV,
  _NUM
};

#include QMK_KEYBOARD_H
enum keycodes {
    // RGB
    RMT = SAFE_RANGE,
    RMS,
    RMIH,
    RMDH,
    RMIS,
    RMDS,
    RMIV,
    RMDV,
    // Snnipets
    SNIPI,
    SNIPO,
    SNIPW,
    SNIPF,
    SNIPC,
    // Keycodes to set default layer
    QWERTY,
    DVORAK,
    COLEMAK

};


#define FN MO(_FN)
#define MOV LT(_MOV, KC_SPC)
#define NUM LT(_NUM, KC_CAPS)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
  * .--------------------------------------------------------------------------------------------------------.
  * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  | Bksp | Home |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |   \  | Pg Up|
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * | FN  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |    Enter    | Pg Dn|
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |     Shift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |  Up  | End  |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl| GUI | Alt  | GUI  |                Space               | Alt  |      | Ctrl | Left | Down |Right |
  * '--------------------------------------------------------------------------------------------------------'
  */
  [_QWERTY] = LAYOUT_65_ansi(
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
      NUM,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
      KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
      KC_LCTL, KC_LGUI, KC_LALT,                            MOV,                       KC_RALT, FN,      KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Colemak
  * .--------------------------------------------------------------------------------------------------------.
  * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  | Bksp | Home |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |   [  |   ]  |   \  | Pg Up|
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * | Caps |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |    Enter    | Pg Dn|
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |     Shift   |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |  Up  | End  |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl| GUI | Alt  | GUI  |                Space               | Alt  |      | Ctrl | Left | Down |Right |
  * '--------------------------------------------------------------------------------------------------------'
  */
  [_COLEMAK] = LAYOUT_65_ansi(
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
      NUM,     KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,          KC_ENT,  KC_PGDN,
      KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
      KC_LCTL, KC_LGUI, KC_LALT,                            MOV,                       KC_RALT, FN,   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Dvorak
  * .--------------------------------------------------------------------------------------------------------.
  * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   [  |   ]  | Bksp | Home |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   /  |   =  |   \  | Pg Up|
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * | Caps |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |    Enter    | Pg Dn|
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |     Shift   |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |  Up  | End  |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl| GUI | Alt  | GUI  |                Space               | Alt  | MO(1)| Ctrl | Left | Down |Right |
  * '--------------------------------------------------------------------------------------------------------'
  */
  [_DVORAK] = LAYOUT_65_ansi(
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC, KC_HOME,
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS, KC_PGUP,
      NUM,     KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,          KC_ENT,  KC_PGDN,
      KC_LSFT,          KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, KC_UP,   KC_END,
      KC_LCTL, KC_LGUI, KC_LALT,                            MOV,                       KC_RALT, FN,      KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  /* Functions
  * .--------------------------------------------------------------------------------------------------------.
  * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F0  |  FPP | FP2  | Del | Reset |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |      | Rmt  | Rms  | Rmih | Rmdh | Rmis | Rmds | Rmiv | Rmdv |      |      |      |             |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |             | Mprv | Mnxt | Mply |      |      | Togg |      |      |      |      |      |Volup |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |                                  |      |      |      |      |Voldw |      |
  * '--------------------------------------------------------------------------------------------------------'
  */
  [_FN] = LAYOUT_65_ansi(
        QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  QK_BOOT,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, _______, _______, _______, _______,
        _______, RMT,     RMS,     RMIH,    RMDH,    RMIS,    RMDS,    RMIV,    RMDV,    _______, _______,  _______,         _______, _______,
        _______,          KC_MPRV, KC_MNXT, KC_MPLY, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, KC_VOLU, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, KC_VOLD, _______
    ),
  /* MOVEMENT
  * .--------------------------------------------------------------------------------------------------------.
  * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F0  |  FPP | FP2  | Bksp | Reset|
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      | PGUP | PSCR |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |      | HOME | END  | LSFT | LCTL | PGDN | Left | Down |  Up  | Right|      |      |             |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |             |      |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |                                  |      |      |      |      |      |      |
  * '--------------------------------------------------------------------------------------------------------'
  */
  [_MOV] = LAYOUT_65_ansi(
      QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  QK_BOOT,
      _______, _______, _______, _______, _______, KC_PGUP, KC_PSCR, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, KC_HOME, KC_END,  KC_LSFT, KC_LCTL, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, _______,
      _______,          _______, _______, _______, RMDV,    _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
  ),
   /* Functions
  * .--------------------------------------------------------------------------------------------------------.
  * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F0  |  FPP | FP2  |Delete|      |
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |Snipi |Snipo |Snipw |Snipf |Snipc |      |  7   |  8   |  9   |  +   |      |      |      |Querty|
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |  4   |  5   |  6   |  -   |      |             |Colemk|
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |             |      |      |      |      |      |  0   |  1   |  2   |  3   |  *   |      |      |Dvorak|
  * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |                                  |      |      |  /   |      |      |      |
  * '--------------------------------------------------------------------------------------------------------'
  */
  [_NUM] = LAYOUT_65_ansi(
      QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______,
      _______, SNIPI,   SNIPO,   SNIPW,   SNIPF,   SNIPC,   _______, KC_7,    KC_8,    KC_9,    KC_PPLS, _______, _______, _______, QWERTY,
      _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_PMNS, _______,          _______, COLEMAK,
      _______,          _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_PAST, _______, _______, DVORAK,
      _______, _______, _______,                            _______,                   _______, _______, KC_PSLS, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Snippets
    case SNIPI:
      if (record->event.pressed){
        SEND_STRING("if expression:\npass\nelse:\npass\n");
      }
      return false;
    case SNIPO:
      if (record->event.pressed){
        SEND_STRING("for i in iterable:\npass\n");
      }
      return false;
    case SNIPW:
      if (record->event.pressed){
        SEND_STRING("while expression:\npass\n");
      }
      return false;
    case SNIPF:
      if (record->event.pressed){
        SEND_STRING("def func(param: type) -> return_type:\n\"\"\"docstring");
        SEND_STRING(SS_TAP(X_ESC) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT));
        SEND_STRING("\n# Put your code here\nreturn output\n");
      }
      return false;
    case SNIPC:
      if (record->event.pressed){
        SEND_STRING("class ClassName:\n\"\"\"docstring");
        SEND_STRING(SS_TAP(X_ESC) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT));
        SEND_STRING("\ndef __init__(, param: type) -> None:\nself.param = param\n");
      }
      return false;
    // Default layout
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    // RGB Manage
    case RMT:
      if (record->event.pressed){
        rgb_matrix_toggle();
      }
      return false;
    case RMS:
      if (record->event.pressed){
        rgb_matrix_step();
      }
      return false;
    case RMIH:
      if (record->event.pressed){
        rgb_matrix_increase_hue();
      }
      return false;
    case RMDH:
      if (record->event.pressed){
        rgb_matrix_decrease_hue();
      }
      return false;
    case RMIS:
      if (record->event.pressed){
        rgb_matrix_increase_sat();
      }
      return false;
    case RMDS:
      if (record->event.pressed){
        rgb_matrix_decrease_sat();
      }
      return false;
    case RMIV:
      if (record->event.pressed){
        rgb_matrix_increase_val();
      }
      return false;
    case RMDV:
      if (record->event.pressed){
        rgb_matrix_decrease_val();
      }
      return false;
    default:
      return true;
  }
};
