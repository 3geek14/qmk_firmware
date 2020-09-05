#include QMK_KEYBOARD_H
#include "version.h"

#define SCREEN_LEFT LCTL(LGUI(KC_LEFT))
#define SCREEN_RIGHT LCTL(LGUI(KC_RIGHT))
#define SCREENSHOT LGUI(LSFT(KC_S))

enum layers {
    BASE,	// default layer
    UTIL,	// symbols
    MNCRFT,	// media keys
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD,
  SHRUG,
  SIGNATURE,
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

enum tap_dance_declarations {
  TD_DOT_DOTS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |   6  |           |   5  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LAlt   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------|  L2  |           |  L2  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  | ./…  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                       ,---------------.       ,---------------.
 *                                       |Ctrl/App| LGui |       | Alt  |Ctrl/Esc|
 *                                ,------|--------|------|       |------+--------+------.
 *                                |      |        | Home |       | PgUp |        |      |
 *                                | Space|Backsp  |------|       |------|  Tab   |Enter |
 *                                |      |ace     | End  |       | PgDn |        |      |
 *                                `----------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  KC_EQUAL,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,                     	KC_5,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_MINUS,
  KC_DELETE,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	TG(UTIL),	TG(UTIL),	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_BSLASH,
  KC_LALT,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,			KC_H,	KC_J,	KC_K,	KC_L,	LT(MNCRFT,KC_SCOLON),	LGUI_T(KC_QUOTE),
  KC_LSHIFT,	LCTL_T(KC_Z),	KC_X,	KC_C,	KC_V,	KC_B,	TG(MNCRFT),	TG(MNCRFT),	KC_N,	KC_M,	KC_COMMA,	TD(TD_DOT_DOTS),	RCTL_T(KC_SLASH),	KC_RSHIFT,
  LT(UTIL,KC_GRAVE),	KC_QUOTE,	LALT(KC_LSHIFT),	KC_LEFT,	KC_RIGHT,					KC_UP,	KC_DOWN,	KC_LBRACKET,	KC_RBRACKET,	MO(UTIL),
  
                                                  		LCTL_T(KC_APPLICATION),	KC_LGUI,     	KC_LALT,	LCTL_T(KC_ESCAPE),
			KC_HOME,	KC_PGUP,		
	KC_SPACE,	KC_BSPACE,	KC_END,	KC_PGDOWN,	KC_TAB,	KC_ENTER
  ),
/* Keymap 1: Utility
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |ScrSht|      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |   ‽  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      | ScrL | ScrR |                                       |VolUp |VolDn | Mute |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Sig  |Shrug |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[UTIL] = LAYOUT_ergodox_pretty(
  KC_TRNS,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F6,                 	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,
  KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_F12,
  KC_TRNS,	KC_TRNS,	SCREENSHOT,	KC_TRNS,	KC_TRNS,	KC_TRNS,			KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
  KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	X(INTERRO),	KC_TRNS,
  KC_TRNS,	KC_TRNS,	KC_TRNS,	SCREEN_LEFT,	SCREEN_RIGHT,					KC_VOLU,	KC_VOLD,	KC_MUTE,	KC_TRNS,	KC_TRNS,
  
                                                      		KC_TRNS,	KC_TRNS,     	KC_TRNS,	KC_TRNS,
			KC_TRNS,	KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	SIGNATURE,	SHRUG
  ),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | RGui |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |      |LClick| MsUp |RClick|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |------|           |------|      |MsLeft|MsDown|MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   Z  |   X  |   C  |   V  |   B  |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space|      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MNCRFT] = LAYOUT_ergodox_pretty(
  KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,               	KC_RGUI,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
  KC_TRNS,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_BTN1,	KC_MS_U,	KC_BTN2,	KC_TRNS,	KC_TRNS,
  KC_LSHIFT,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,			KC_TRNS,	KC_MS_L,	KC_MS_D,	KC_MS_R,	KC_TRNS,	KC_TRNS,
  KC_LCTRL,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
  KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,					KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,

                                             		KC_TRNS,	KC_TRNS,     	KC_TRNS,	KC_TRNS,
			KC_TRNS,	KC_TRNS,
	KC_SPC,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      }
    #ifdef RGBLIGHT_ENABLE
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
        return false;
      }
    #endif
    case SHRUG:
      if (record->event.pressed) {
        send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF"); // ¯\_(ツ)_/¯
        return true;
      }
    case SIGNATURE:
      if (record->event.pressed) {
        send_unicode_hex_string("0034 2211 0028 002D 0031 0029 005E 0069 00F7 0028 0032 0069 002B 0031 0029 0020 1F6A3 1F3A3"); // 4∑(-1)^i÷(2i+1) 🚣🎣
        return true;
      }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};

void dot_dots(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        send_unicode_hex_string("2026");
		// SEND_STRING("ellipsis");
        reset_tap_dance(state);
    } else {
	    int i;
		for (i = 0; i < state->count; ++i) {
		    SEND_STRING(".");
		}
		reset_tap_dance(state);
	}
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Period, thrice for ellipsis
    [TD_DOT_DOTS] = ACTION_TAP_DANCE_FN(dot_dots),
};
