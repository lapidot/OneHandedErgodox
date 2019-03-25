#include#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
//#include "keymap_steno.h"
#include "danl4_common_functions.c"

#ifndef MIDI_ENABLE
#error "Midi is not enabled"
#endif



/*
enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: qwerty
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  | RMB  |           | ESC    |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |  [   |           | TAB  |   Y  |   U  |   I  |   O  |   P  |   BS   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |ENTER   |
 * |--------+------+------+------+------+------| -    |           | =    |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCTRL|ALT  |CTLShTab|CTL-TAB| LGui|                                       | Arrow|  Alt |  Win | LCrtl| RCTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Symbol|LMB   |       |Plover|HalfSymb|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |MU_TOG|       | PgUp |        |      |
 *                                 | Space|DELETE|------|       |------|  enter |Space |
 *                                 |mirror|      | End  |       | PgDn | HelpR  |mirror|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_WINBASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_BTN2,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_EQL,
        KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,  		  KC_X,   KC_C,   KC_V,   KC_B,   KC_MINUS,
        KC_LCTRL, 		KC_LALT,	  LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),  MO(_XFUNC),
                                              KC_LGUI,  KC_BTN1,
                                                              MU_ON,
                                         KC_SPACE,KC_DEL,KC_END,
        // right hand
             KC_ESC,    KC_6,   KC_7,  KC_8,   KC_9,   KC_0,        SLASHES,
             KC_TAB,    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,        KC_BSPC,
                        KC_H,   KC_J,  KC_K,   KC_L,   SHSQ,		KC_ENT,
             KC_EQL,	KC_N,   KC_M,  KC_COMM,KC_DOT, SLASHES,   	OSM(MOD_LSFT),
					MO(ARROWS),	OSM(MOD_LALT),OSM(MOD_LGUI),OSM(MOD_LCTL),	OSM(MOD_RCTL),
             FUNCTN,   KC_RGUI,
             MU_OFF,
             NUMPAD,LT(_XFUNC, KC_ENT), LT(MIRROR, KC_SPACE)
    ),
/* Keymap 1: mirrored qwerty
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  BSPC  |   0  |   9  |   8  |   7  |   6  | \    |           |   `  |   5  |   4  |   3  |   2  |   1  |  ESC  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  '     |   P  |   O  |   I  |   U  |   Y  |  ]   |           |  [   |   T  |   R  |   E  |   W  |   Q  |   TAB  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ENTER  |   ;  |   L  |   K  |   J  |   H  |------|           |------|   G  |   F  |   D  |   S  |   A  | BSPC   |
 * |--------+------+------+------+------+------| -    |           | =    |------+------+------+------+------+--------|
 * | LShift |   /  |   .  |   ,  |   M  |   N  |      |           |      |   B  |   V  |   C  |   X  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCTRL|ALT  |CTLShTab|CTL-TAB| LGui|                                       |  RGui| UP   | DOWN |  ALT | RCTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|DELETE|------|       |------|  Tab   |Enter |
 *                                 |mirror|      | End  |       | PgDn |        |mirror|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_MIRROR] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_BSPC,        KC_0,         KC_9,   KC_8,   KC_7,   KC_6,   KC_TRNS,
        KC_BSLS,         KC_P,         KC_O,   KC_I,   KC_U,   KC_Y,   KC_LBRC,
        KC_ENT,        KC_SCLN,      KC_L,   KC_K,   KC_J,   KC_H,
        KC_LSFT,        KC_SLASH,  	  KC_DOT, KC_COMM,KC_M,   KC_N,   KC_RBRC,
        KC_LCTRL, 		KC_LALT,	   LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),  KC_TRNS,
                                              KC_TRNS,  KC_TRNS,
                                                              KC_TRNS,
                                         KC_TRNS,KC_DEL,KC_END,
        // right hand						
             KC_TRNS,     KC_5,   KC_4,  KC_3,   KC_2,   KC_1,             KC_ESC,
             KC_TRNS,    KC_T,   KC_R,  KC_E,   KC_W,   KC_Q,             KC_TRNS,
                          KC_G,   KC_F,  KC_D,   KC_S,   KC_A,  		   KC_TRNS,
             KC_TRNS,KC_B,   KC_V,  KC_C,   KC_X,   KC_Z,		   	   KC_TRNS,
                                  KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,           KC_TRNS,
             KC_TRNS,        KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS, KC_TRNS
    ),
	
[_NUMPAD] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_BSPC,        KC_0,         KC_9,   KC_8,   KC_7,   KC_6,   KC_N,
        KC_BSLS,         KC_P,         KC_O,   KC_I,   KC_U,   KC_Y,   KC_LBRC,
        KC_ENT,        KC_SCLN,      KC_L,   KC_K,   KC_J,   KC_H,
        KC_LSFT,        KC_SLASH,  	  KC_DOT, KC_COMM,KC_M,   KC_N,   KC_RBRC,
        KC_LCTRL, 		KC_LALT,	   LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),  KC_TRNS,
                                              KC_TRNS,  KC_TRNS,
                                                              KC_TRNS,
                                         KC_TRNS,KC_DEL,KC_END,
        // right hand
             KC_TRNS,	KC_5,   KC_4,	KC_3,   KC_2,   KC_1,	KC_TRNS,
             KC_TRNS,	KC_ASTR,KC_7,	KC_8,	KC_9,   KC_0,	KC_TRNS,
						KC_SLSH,KC_4,	KC_5,	KC_6,   KC_PLUS,KC_TRNS,
             KC_TRNS,	KC_0,	KC_1,	KC_2,	KC_3,	KC_MINS,KC_TRNS,
								KC_0,	KC_DOT,	KC_TRNS,KC_TRNS,KC_TRNS,
             KC_TRNS,        KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS, KC_TRNS
    ),	
	
/* Keymap 0: ARROWS
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  | RMB  |           | ESC    |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |  [   |           | TAB  |   Y  |   U  |   I  |   O  |   P  |   BS   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |ENTER   |
 * |--------+------+------+------+------+------| -    |           | =    |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCTRL|ALT  |CTLShTab|CTL-TAB| LGui|                                       |  RGui| UP   | DOWN |  ALT | RCTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Symbol|LMB   |       |Plover|HalfSymb|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |MU_TOG|       | PgUp |        |      |
 *                                 | Space|DELETE|------|       |------|  enter |Space |
 *                                 |mirror|      | End  |       | PgDn | HelpR  |mirror|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_ARROWS] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_BTN2,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_EQL,
        KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,  		  KC_X,   KC_C,   KC_V,   KC_B,   KC_MINUS,
        KC_LCTRL, 		KC_LALT,	  LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),  MO(_XFUNC),
                                              KC_LGUI,  KC_BTN1,
                                                              MU_ON,
                                         KC_SPACE,KC_DEL,KC_END,
        // right hand
             KC_ESC,    KC_6,   KC_7,  KC_8,   KC_9,   KC_0,        KC_A,
             KC_TAB,    XXXXXXX,   KC_HOME, KC_UP,   KC_PGUP,  XXXXXXX,        KC_BSPC,
                        XXXXXXX,   KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,		KC_ENT,
             KC_EQL,	XXXXXXX,   KC_END,  KC_DOWN, KC_PGDN,  XXXXXXX,   	KC_RSFT,
							KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,	KC_TRNS,
             KC_TRNS,   KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS, KC_TRNS
    ),
	
	
/* Keymap 5: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |   F6 |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |BkSp    |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   /  |   \  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   /    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   '  |   ;  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   -  | ENTER  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   -  |   =  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   +  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |mirror|      |------|       |------|      |mirror|
 *                                 |space |      |      |       |      |      |enter |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
/*
[_XNUMPAD] = LAYOUT_ergodox(
       // left hand VRSN,

	KC_ESC,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_NO,KC_SLASH,KC_BSLS,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_NO,KC_QUOT,KC_SCLN, KC_LPRN,KC_RPRN,KC_GRV,
       KC_NO,KC_MINUS,KC_EQL,KC_LBRC,KC_RBRC,KC_TILD,KC_NO,
          KC_0,KC_NO,KC_NO,KC_NO,KC_TRNS,
                                         KC_TRNS,KC_NO,
                                               KC_NO,
                          LT(_XFUNC, KC_SPACE),KC_NO,KC_NO,
       // right hand
       KC_F7, KC_F8,   KC_F9,  KC_F10,   KC_F11,   KC_F12,  KC_S,
       KC_NO, KC_UP, KC_KP_7, KC_KP_8,  KC_KP_9,KC_KP_ASTERISK, KC_KP_SLASH,
            KC_DOWN, KC_KP_4, KC_KP_5,  KC_KP_6,  KC_KP_MINUS, KC_KP_ENTER,
       KC_NO,KC_AMPR,KC_KP_1, KC_KP_2,  KC_KP_3,   KC_KP_PLUS, KC_NO,
                         KC_TRNS,KC_DOT,  KC_0,    KC_KP_EQUAL,  KC_NO,
       BL_OFF, KC_TRNS,
       BL_ON,
       KC_NO, KC_NO, KC_TRNS
),*/
/* Keymap 6: Mirrored Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |delete   |  F12 |  F11 |  F10 |  F9  |  F8  |   F7 |           |  F6  |  F5  |  F4  |  F3  |  F2  |  F1  |BkSp    |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |   7  |   8  |   9  |   *  |   /  |           |      |   |  |   {  |   }  |   /  |   \  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |   4  |   5  |   6  |   -  |------|           |------|   `  |   (  |   )  |   ;  |   '  |        |
 * |---------+------+------+------+------+------|enter |           |      |------+------+------+------+------+--------|
 * |         |      |   1  |   2  |   3  |   +  |      |           |      |   ~  |   [  |   ]  |   =  |   -  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |   0  |  .   |  =   |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 
// SYMBOLS
[HALFSYMB] = LAYOUT_ergodox(
       // left hand
       KC_BSPC,   KC_F13,    KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,
       KC_NO,KC_NO,KC_KP_7, KC_KP_8, KC_KP_9,KC_KP_ASTERISK,KC_KP_SLASH,
       KC_ENTER,KC_NO,KC_KP_4, KC_KP_5, KC_KP_6,KC_KP_MINUS,
       KC_NO,KC_NO,KC_KP_1, KC_KP_2, KC_KP_3,KC_KP_PLUS,KC_KP_ENTER,
          EPRM,KC_NO,KC_KP_0,KC_KP_DOT,KC_KP_EQUAL,
                                         KC_TRNS,KC_NO,
                                               KC_TRNS,
                          KC_TRANSPARENT,KC_NO,KC_NO,
       // right hand
       KC_F19, KC_F20,   KC_F21,  KC_F22,   KC_F23,   KC_F24,  KC_C,
       KC_NO,KC_PIPE,KC_LCBR,KC_RCBR, KC_SLASH, KC_BSLS, KC_NO,
             KC_GRV,KC_LPRN,KC_RPRN,  KC_SCLN, KC_QUOT, KC_NO,
       KC_NO, KC_TILD,KC_LBRC,KC_RBRC, KC_EQL,  KC_MINUS, KC_NO,
                         KC_TRNS,KC_NO,  KC_NO,    KC_NO,  KC_NO,
       KC_NO, KC_TRNS,
       KC_TRNS,
       KC_NO, KC_NO, KC_TRANSPARENT
),*/

/* Keymap 8: shortcuts
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |  BSPC  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |ENTER   |
 * |--------+------+------+------+------+------| -    |           | =    |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCTRL|ALT  |CTLShTab|CTL-TAB|     |                                       |  RGui| UP   | DOWN |  ALT | RCTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |SYMBOLS|Dvorak|       |Steno |Plover|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|DELETE|------|       |------|  Tab   |Enter |
 *                                 |mirror|      | End  |       | PgDn |        |mirror|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_XFUNC] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        RGB_MODE_KNIGHT,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_TAB,   LCTL(KC_Q),   LCTL(KC_W),LCTL(KC_E),LCTL(KC_R),LCTL(KC_T),   KC_NO,
        KC_BSPC,  LCTL(KC_A),   LCTL(KC_S),LCTL(KC_D),LCTL(KC_F),LCTL(KC_G),
        KC_LSFT,  LCTL(KC_Z),  	LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),LCTL(KC_B),   KC_MINUS,
        RESET, 		KC_LALT,	  LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),  KC_TRANSPARENT,
                                              KC_TRNS,  KC_TRNS,

                                                              KC_TRNS,
                                         KC_NO,KC_NO,KC_NO,
// right hand
             KC_RGHT,	KC_6,		KC_7,  		KC_8,		KC_9,   	KC_0,		KC_H,
             KC_TRNS,	LCTL(KC_Y),	PARAN,		CURLY,		SQUAR,		LCTL(KC_P),	KC_TRNS,
                        LCTL(KC_G),	KC_DEL,		KC_BSPC,	LCTL(KC_K),	LCTL(KC_A),	KC_TRNS,
             KC_EQL,	LCTL(KC_B),	LCTL(KC_V),	LCTL(KC_C),	LCTL(KC_X),	LCTL(KC_Z),	KC_TRNS,
									KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	RESET,
             KC_TRNS,KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS, KC_TRNS
    ),
    /* Keymap 9: Functions
 *
 PARAN TD(PAR)
#define CURLY TD(CRL)
#define SQUAR
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    F1  |  F2  |  F3  |  F4  |  F5  |   F6 |      |           |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  F7    |  F8  |  F9  |  F10 |  F11 |  F12 |      |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  F13   |  F14 |  F15 |  F16 |  F17 |  F18 |------|           |------|  F13 |  F14 |  F15 |  F16 |  F17 |  F18   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  F19   |  F20 |  F21 |  F22 |  F23 |  F24 |      |           |      |  F19 |  F20 |  F21 |  F22 |  F23 |  F24   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   c  |   v  |------|       |------|  n   |  m   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[_FUNC] = LAYOUT_ergodox(  // layout: layer 9
        // left hand
        KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_NO,
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,
        KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18,
        KC_F19,  KC_F20, KC_F21, KC_F22, KC_F23, KC_F24,   KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,
                                      KC_TRNS, KC_TRNS,
                                           KC_TRNS,
                                 KC_NO,   KC_NO,   KC_NO,
        // right hand
             KC_TRNS,  KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F,
             KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
                     KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18,
               KC_TRNS,KC_F19,  KC_F20, KC_F21, KC_F22, KC_F23, KC_F24,
                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS,  KC_TRNS,   KC_TRNS
)

}; QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
//#include "keymap_steno.h"
#include "danl4_common_functions.c"

#ifndef MIDI_ENABLE
#error "Midi is not enabled"
#endif



/*
enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: qwerty
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  | RMB  |           | ESC    |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |  [   |           | TAB  |   Y  |   U  |   I  |   O  |   P  |   BS   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |ENTER   |
 * |--------+------+------+------+------+------| -    |           | =    |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCTRL|ALT  |CTLShTab|CTL-TAB| LGui|                                       |  RGui| UP   | DOWN |  ALT | RCTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Symbol|LMB   |       |Plover|HalfSymb|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |MU_TOG|       | PgUp |        |      |
 *                                 | Space|DELETE|------|       |------|  enter |Space |
 *                                 |mirror|      | End  |       | PgDn | HelpR  |mirror|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_WINBASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_BTN2,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_EQL,
        KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,  		  KC_X,   KC_C,   KC_V,   KC_B,   KC_MINUS,
        KC_LCTRL, 		KC_LALT,	  LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),  MO(_XFUNC),
                                              KC_LGUI,  KC_BTN1,
                                                              MU_ON,
                                         KC_SPACE,KC_DEL,KC_END,
        // right hand
             KC_ESC,    KC_6,   KC_7,  KC_8,   KC_9,   KC_0,        KC_BSPC,
             KC_TAB,    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,        KC_BSPC,
                        KC_H,   KC_J,  KC_K,   KC_L,   TD(SCL),		KC_ENT,
             KC_EQL,	KC_N,   KC_M,  KC_COMM,KC_DOT, SLASHES,   	OSM(MOD_RSFT),
					MO(ARROWS),	OSM(MOD_LALT),OSM(MOD_LGUI),OSM(MOD_LCTL),	OSM(MOD_RCTL),
             MO(_FUNC),   KC_RGUI,
             MU_OFF,
             MO(NUMPAD),LT(_XFUNC, KC_ENT), LT(MIRROR, KC_SPACE)
    ),
/* Keymap 1: mirrored qwerty
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  BSPC  |   0  |   9  |   8  |   7  |   6  | \    |           |   `  |   5  |   4  |   3  |   2  |   1  |  ESC  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  '     |   P  |   O  |   I  |   U  |   Y  |  ]   |           |  [   |   T  |   R  |   E  |   W  |   Q  |   TAB  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ENTER  |   ;  |   L  |   K  |   J  |   H  |------|           |------|   G  |   F  |   D  |   S  |   A  | BSPC   |
 * |--------+------+------+------+------+------| -    |           | =    |------+------+------+------+------+--------|
 * | LShift |   /  |   .  |   ,  |   M  |   N  |      |           |      |   B  |   V  |   C  |   X  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCTRL|ALT  |CTLShTab|CTL-TAB| LGui|                                       |  RGui| UP   | DOWN |  ALT | RCTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|DELETE|------|       |------|  Tab   |Enter |
 *                                 |mirror|      | End  |       | PgDn |        |mirror|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_MIRROR] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_BSPC,        KC_0,         KC_9,   KC_8,   KC_7,   KC_6,   KC_TRNS,
        KC_BSLS,         KC_P,         KC_O,   KC_I,   KC_U,   KC_Y,   KC_LBRC,
        KC_ENT,        KC_SCLN,      KC_L,   KC_K,   KC_J,   KC_H,
        KC_LSFT,        KC_SLASH,  	  KC_DOT, KC_COMM,KC_M,   KC_N,   KC_RBRC,
        KC_LCTRL, 		KC_LALT,	   LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),  KC_TRNS,
                                              KC_TRNS,  KC_TRNS,
                                                              KC_TRNS,
                                         KC_TRNS,KC_DEL,KC_END,
        // right hand						
             KC_TRNS,     KC_5,   KC_4,  KC_3,   KC_2,   KC_1,             KC_R,
             KC_TRNS,    KC_T,   KC_R,  KC_E,   KC_W,   KC_Q,             KC_S,
                          KC_G,   KC_F,  KC_D,   KC_S,   KC_A,  		   KC_TRNS,
             KC_TRNS,KC_B,   KC_V,  KC_C,   KC_X,   KC_Z,		   	   KC_TRNS,
                                  KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,           KC_TRNS,
             KC_TRNS,        KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS, KC_TRNS
    ),
	
[_NUMPAD] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_BSPC,        KC_0,         KC_9,   KC_8,   KC_7,   KC_6,   KC_N,
        KC_BSLS,         KC_P,         KC_O,   KC_I,   KC_U,   KC_Y,   KC_LBRC,
        KC_ENT,        KC_SCLN,      KC_L,   KC_K,   KC_J,   KC_H,
        KC_LSFT,        KC_SLASH,  	  KC_DOT, KC_COMM,KC_M,   KC_N,   KC_RBRC,
        KC_LCTRL, 		KC_LALT,	   LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),  KC_TRNS,
                                              KC_TRNS,  KC_TRNS,
                                                              KC_TRNS,
                                         KC_TRNS,KC_DEL,KC_END,
        // right hand
             KC_TRNS,	KC_5,   KC_4,	KC_3,   KC_2,   KC_1,	KC_TRNS,
             KC_TRNS,	KC_ASTR,KC_7,	KC_8,	KC_9,   KC_0,	KC_TRNS,
						KC_SLSH,KC_4,	KC_5,	KC_6,   KC_PLUS,KC_TRNS,
             KC_TRNS,	KC_0,	KC_1,	KC_2,	KC_3,	KC_MINS,KC_TRNS,
								KC_0,	KC_DOT,	KC_TRNS,KC_TRNS,KC_TRNS,
             KC_TRNS,        KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS, KC_TRNS
    ),	
	
/* Keymap 0: ARROWS
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  | RMB  |           | ESC    |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |  [   |           | TAB  |   Y  |   U  |   I  |   O  |   P  |   BS   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |ENTER   |
 * |--------+------+------+------+------+------| -    |           | =    |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCTRL|ALT  |CTLShTab|CTL-TAB| LGui|                                       |  RGui| UP   | DOWN |  ALT | RCTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Symbol|LMB   |       |Plover|HalfSymb|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |MU_TOG|       | PgUp |        |      |
 *                                 | Space|DELETE|------|       |------|  enter |Space |
 *                                 |mirror|      | End  |       | PgDn | HelpR  |mirror|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_ARROWS] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_BTN2,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_EQL,
        KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,  		  KC_X,   KC_C,   KC_V,   KC_B,   KC_MINUS,
        KC_LCTRL, 		KC_LALT,	  LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),  MO(_XFUNC),
                                              KC_LGUI,  KC_BTN1,
                                                              MU_ON,
                                         KC_SPACE,KC_DEL,KC_END,
        // right hand
             KC_ESC,    KC_6,   KC_7,  KC_8,   KC_9,   KC_0,        KC_A,
             KC_TAB,    XXXXXXX,   KC_HOME, KC_UP,   KC_PGUP,  XXXXXXX,        KC_BSPC,
                        XXXXXXX,   KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,		KC_ENT,
             KC_EQL,	XXXXXXX,   KC_END,  KC_DOWN, KC_PGDN,  XXXXXXX,   	KC_RSFT,
							KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,	KC_TRNS,
             KC_TRNS,   KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS, KC_TRNS
    ),
	
	
/* Keymap 5: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |   F6 |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |BkSp    |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   /  |   \  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   /    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   '  |   ;  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   -  | ENTER  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   -  |   =  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   +  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |mirror|      |------|       |------|      |mirror|
 *                                 |space |      |      |       |      |      |enter |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
/*
[_XNUMPAD] = LAYOUT_ergodox(
       // left hand VRSN,

	KC_ESC,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_NO,KC_SLASH,KC_BSLS,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_NO,KC_QUOT,KC_SCLN, KC_LPRN,KC_RPRN,KC_GRV,
       KC_NO,KC_MINUS,KC_EQL,KC_LBRC,KC_RBRC,KC_TILD,KC_NO,
          KC_0,KC_NO,KC_NO,KC_NO,KC_TRNS,
                                         KC_TRNS,KC_NO,
                                               KC_NO,
                          LT(_XFUNC, KC_SPACE),KC_NO,KC_NO,
       // right hand
       KC_F7, KC_F8,   KC_F9,  KC_F10,   KC_F11,   KC_F12,  KC_S,
       KC_NO, KC_UP, KC_KP_7, KC_KP_8,  KC_KP_9,KC_KP_ASTERISK, KC_KP_SLASH,
            KC_DOWN, KC_KP_4, KC_KP_5,  KC_KP_6,  KC_KP_MINUS, KC_KP_ENTER,
       KC_NO,KC_AMPR,KC_KP_1, KC_KP_2,  KC_KP_3,   KC_KP_PLUS, KC_NO,
                         KC_TRNS,KC_DOT,  KC_0,    KC_KP_EQUAL,  KC_NO,
       BL_OFF, KC_TRNS,
       BL_ON,
       KC_NO, KC_NO, KC_TRNS
),*/
/* Keymap 6: Mirrored Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |delete   |  F12 |  F11 |  F10 |  F9  |  F8  |   F7 |           |  F6  |  F5  |  F4  |  F3  |  F2  |  F1  |BkSp    |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |   7  |   8  |   9  |   *  |   /  |           |      |   |  |   {  |   }  |   /  |   \  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |   4  |   5  |   6  |   -  |------|           |------|   `  |   (  |   )  |   ;  |   '  |        |
 * |---------+------+------+------+------+------|enter |           |      |------+------+------+------+------+--------|
 * |         |      |   1  |   2  |   3  |   +  |      |           |      |   ~  |   [  |   ]  |   =  |   -  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |   0  |  .   |  =   |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 
// SYMBOLS
[HALFSYMB] = LAYOUT_ergodox(
       // left hand
       KC_BSPC,   KC_F13,    KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,
       KC_NO,KC_NO,KC_KP_7, KC_KP_8, KC_KP_9,KC_KP_ASTERISK,KC_KP_SLASH,
       KC_ENTER,KC_NO,KC_KP_4, KC_KP_5, KC_KP_6,KC_KP_MINUS,
       KC_NO,KC_NO,KC_KP_1, KC_KP_2, KC_KP_3,KC_KP_PLUS,KC_KP_ENTER,
          EPRM,KC_NO,KC_KP_0,KC_KP_DOT,KC_KP_EQUAL,
                                         KC_TRNS,KC_NO,
                                               KC_TRNS,
                          KC_TRANSPARENT,KC_NO,KC_NO,
       // right hand
       KC_F19, KC_F20,   KC_F21,  KC_F22,   KC_F23,   KC_F24,  KC_C,
       KC_NO,KC_PIPE,KC_LCBR,KC_RCBR, KC_SLASH, KC_BSLS, KC_NO,
             KC_GRV,KC_LPRN,KC_RPRN,  KC_SCLN, KC_QUOT, KC_NO,
       KC_NO, KC_TILD,KC_LBRC,KC_RBRC, KC_EQL,  KC_MINUS, KC_NO,
                         KC_TRNS,KC_NO,  KC_NO,    KC_NO,  KC_NO,
       KC_NO, KC_TRNS,
       KC_TRNS,
       KC_NO, KC_NO, KC_TRANSPARENT
),*/

/* Keymap 8: shortcuts
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |  BSPC  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |ENTER   |
 * |--------+------+------+------+------+------| -    |           | =    |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCTRL|ALT  |CTLShTab|CTL-TAB|     |                                       |  RGui| UP   | DOWN |  ALT | RCTRL  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |SYMBOLS|Dvorak|       |Steno |Plover|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|DELETE|------|       |------|  Tab   |Enter |
 *                                 |mirror|      | End  |       | PgDn |        |mirror|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_XFUNC] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        RGB_MODE_KNIGHT,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_TAB,   LCTL(KC_Q),   LCTL(KC_W),LCTL(KC_E),LCTL(KC_R),LCTL(KC_T),   KC_NO,
        KC_BSPC,  LCTL(KC_A),   LCTL(KC_S),LCTL(KC_D),LCTL(KC_F),LCTL(KC_G),
        KC_LSFT,  LCTL(KC_Z),  	LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),LCTL(KC_B),   KC_MINUS,
        RESET, 		KC_LALT,	  LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),  KC_TRANSPARENT,
                                              KC_TRNS,  KC_TRNS,

                                                              KC_TRNS,
                                         KC_NO,KC_NO,KC_NO,
// right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_H,
             KC_TRNS,LCTL(KC_Y),PARAN,CURLY,SQUAR ,LCTL(KC_P),KC_BSLS,
                          LCTL(KC_H),KC_DEL,KC_BSPC,LCTL(KC_L),LCTL(KC_SCLN),KC_ENT,
             KC_EQL,LCTL(KC_B),LCTL(KC_V),LCTL(KC_C),LCTL(KC_X),LCTL(KC_Z),KC_RSFT,
                                  KC_TRNS, KC_UP,KC_DOWN,KC_RALT,           RESET,
             KC_TRNS,KC_TRNS,
             KC_NO,
             KC_NO,KC_NO, KC_NO
    ),
    /* Keymap 9: Functions
 *
 PARAN TD(PAR)
#define CURLY TD(CRL)
#define SQUAR
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    F1  |  F2  |  F3  |  F4  |  F5  |   F6 |      |           |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  F7    |  F8  |  F9  |  F10 |  F11 |  F12 |      |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  F13   |  F14 |  F15 |  F16 |  F17 |  F18 |------|           |------|  F13 |  F14 |  F15 |  F16 |  F17 |  F18   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  F19   |  F20 |  F21 |  F22 |  F23 |  F24 |      |           |      |  F19 |  F20 |  F21 |  F22 |  F23 |  F24   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   c  |   v  |------|       |------|  n   |  m   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[_FUNC] = LAYOUT_ergodox(  // layout: layer 9
        // left hand
        KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_NO,
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,
        KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18,
        KC_F19,  KC_F20, KC_F21, KC_F22, KC_F23, KC_F24,   KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,
                                      KC_TRNS, KC_TRNS,
                                           KC_TRNS,
                                 KC_NO,   KC_NO,   KC_NO,
        // right hand
             KC_TRNS,  KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F,
             KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
                     KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18,
               KC_NO,KC_F19,  KC_F20, KC_F21, KC_F22, KC_F23, KC_F24,
                              KC_TRNS, KC_TRNS,  KC_NO,   KC_NO,     KC_NO,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_NO,  KC_NO,   KC_NO
)

};
