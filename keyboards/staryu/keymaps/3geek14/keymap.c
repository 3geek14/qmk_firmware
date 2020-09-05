/*
Copyright 2018 Kenneth Aloysius

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
  _LAYER0,
  _LAYER1,
  _LAYER2,
  _LAYER3,
  _LAYER4
};

enum custom_keycodes {
  PHANTASY = SAFE_RANGE,
};

enum unicode_names {
    INTERRO,
    IRONY,
    SNEK
};

const uint32_t PROGMEM unicode_map[] = {
    [INTERRO]  = 0x203D,	// ‽
    [IRONY] = 0x2E2E,	// ⸮
    [SNEK]  = 0x1F40D,	// 🐍
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_LAYER0] = LAYOUT(
/* ┌─────────┬─────────┬─────────┐ */
              KC_UP,    TO(_LAYER1),
/* ├─────────┼─────────┼─────────┤ */
    PHANTASY, KC_DOWN,  KC_RIGHT
/* └─────────┴─────────┴─────────┘ */
  ),

  [_LAYER1] = LAYOUT(
/* ┌─────────┬─────────┬─────────┐ */
              KC_PGUP,  TO(_LAYER2),
/* ├─────────┼─────────┼─────────┤ */
    KC_HOME,  KC_PGDN,  KC_END
/* └─────────┴─────────┴─────────┘ */
  ),

  [_LAYER2] = LAYOUT(
/* ┌─────────┬─────────┬─────────┐ */
              KC_MSEL,  TO(_LAYER3),
/* ├─────────┼─────────┼─────────┤ */
    KC_MPRV,  KC_MPLY,  KC_MNXT
/* └─────────┴─────────┴─────────┘ */
  ),

  [_LAYER3] = LAYOUT(
/* ┌─────────┬─────────┬─────────┐ */
              KC_MS_U,  TO(_LAYER4),
/* ├─────────┼─────────┼─────────┤ */
    KC_MS_L,  KC_MS_D,  KC_MS_R
/* └─────────┴─────────┴─────────┘ */
  ),

  [_LAYER4] = LAYOUT(
/* ┌─────────┬─────────┬─────────┐ */
              XXXXXXX,  TO(_LAYER0),
/* ├─────────┼─────────┼─────────┤ */
    RGB_TOG,  BL_TOGG,  BL_STEP 
/* └─────────┴─────────┴─────────┘ */
  ),

};

void eeconfig_init_user(void) {
  // use the non noeeprom versions, to write these values to EEPROM too
  rgblight_enable();
  rgblight_mode(RGBLIGHT_MODE_BREATHING+1);

  backlight_enable();
}

void keyboard_post_init_user(void) {
  //layer_state_set_user is not called for inital state - set it here
  rgblight_sethsv_noeeprom_white();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _LAYER1:
        rgblight_sethsv_noeeprom_cyan();
        break;
    case _LAYER2:
        rgblight_sethsv_noeeprom_magenta();
        break;
    case _LAYER3:
        rgblight_sethsv_noeeprom_red();
        break;
    case _LAYER4:
        rgblight_sethsv_noeeprom_orange();
        break;
    case _LAYER0:
    default: //  for any other layers, or the default layer
        rgblight_sethsv_noeeprom_white();
        break;
    }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PHANTASY:
      if (record->event.pressed) {
        send_unicode_hex_string("1F456 1F351 1F30A 1F31F"); // 👖🍑🌊🌟
        return true;
      }
  }
  return true;
}