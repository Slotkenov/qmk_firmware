// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
// Wanted to map default layer of my EZ to my existing Kinesis Mapping.
// Only default layer was remapped all others layers are standard Ergodox EZ
// Very personal mapping of-course, but who knows a starting point for others.

#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "sendchar.h"
#include "virtser.h"

#define BASE 0 // default layer
#define SHFT 1 // shifted keys
#define SYMB 2 // symbols
#define MDIA 3 // media keys
#define TXBOLT 4 // TxBolt Steno Virtual Serial

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | LCTL | LALT | Tab  |   |  |   €  |      |           |      |      |      | Esc  | RALT | RCTL |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | SYMB   |   '  |   ,  |   .  |   P  |   Y  | MDIA |           | TX   |   F  |   G  |   C  |   R  |   L  |  SYMB  |
 * |--------+------+------+------+------+------|      |           | BOLT |------+------+------+------+------+--------|
 * | SHFT   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |  SHFT  |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LGUI   |;/Ctrl|   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Ctrl|  RGUI  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | LCTL |      | Down |  Up  |                                       | Left | Right|      | RCTL |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Backs|Delete|------|       |------|  Enter |Space |
 *                                 | pace |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_NO,    KC_LCTL,        KC_LALT, KC_TAB,  KC_PIPE, LALT(KC_AT), KC_NO,
        MO(SYMB), KC_QUOT,        KC_COMM, KC_DOT,  KC_P,    KC_Y,        MO(MDIA),
        MO(SHFT), KC_A,           KC_O,    KC_E,    KC_U,    KC_I,
        KC_LGUI,  CTL_T(KC_SCLN), KC_Q,    KC_J,    KC_K,    KC_X,        ALL_T(KC_NO),
        KC_NO,    KC_LCTL,        KC_NO,   KC_DOWN, KC_UP,
                                                             KC_NO,       KC_NO,
                                                                          KC_HOME,
                                                    KC_BSPC, KC_DELT,     KC_END,
        // right hand
        KC_NO,        KC_NO,   KC_NO,    KC_ESC,   KC_RALT, KC_RCTL,     KC_NO,
        TG(TXBOLT),   KC_F,    KC_G,     KC_C,     KC_R,    KC_L,        MO(SYMB),
                      KC_D,    KC_H,     KC_T,     KC_N,    KC_S,        MO(SHFT),
        MEH_T(KC_NO), KC_B,    KC_M,     KC_W,     KC_V,    CTL_T(KC_Z), KC_RGUI,
                               KC_LEFT,  KC_RIGHT, KC_NO,   KC_RCTL,     KC_NO,
        KC_NO,        KC_NO,
        KC_PGUP,
        KC_PGDN,      KC_ENT, KC_SPC
    ),
/* Keymap 1: Shifted keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      | Tab  |   !  |   ~  |      |           |      |      |      | Esc  |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   "  |   (  |   )  |   P  |   Y  |      |           |      |   F  |   G  |   C  |   R  |   L  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   :  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Down |  Up  |                                       | Left | Right|      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PGUP |        |      |
 *                                 | Backs|Delete|------|       |------|  Enter |Space |
 *                                 | pace |      | End  |       | PGDN |        |      |
 *                                 `--------------------'       `----------------------'
 */
[SHFT] = KEYMAP(
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, S(KC_TAB),  KC_EXLM,    KC_TILD,    KC_TRNS,
        KC_TRNS, KC_DQUO, KC_LPRN, KC_RPRN,    S(KC_P),    S(KC_Y),    KC_TRNS,
        KC_TRNS, S(KC_A), S(KC_O), S(KC_E),    S(KC_U),    S(KC_I),
        KC_TRNS, KC_COLN, S(KC_Q), S(KC_J),    S(KC_K),    S(KC_X),    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, S(KC_DOWN), S(KC_UP),
                                                           KC_TRNS,    KC_TRNS,
                                                                       S(KC_HOME),
                                               S(KC_BSPC), S(KC_DELT), S(KC_END),
        // right hand
        KC_TRNS,    KC_TRNS,   KC_TRNS,    S(KC_ESC),   KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,    S(KC_F),   S(KC_G),    S(KC_C),     S(KC_R), S(KC_L), KC_TRNS,
                    S(KC_D),   S(KC_H),    S(KC_T),     S(KC_N), S(KC_S), KC_TRNS,
        KC_TRNS,    S(KC_B),   S(KC_M),    S(KC_W),     S(KC_V), S(KC_Z), KC_TRNS,
                               S(KC_LEFT), S(KC_RIGHT), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,    KC_TRNS,
        S(KC_PGUP),
        S(KC_PGDN), S(KC_ENT), S(KC_SPC)
    ),
/* Keymap 2: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   `  |   (  |   )  |   ^  |   $  |      |           |      |   /  |   7  |   8  |   9  |   %  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   @  |   {  |   }  |   ?  |   _  |------|           |------|   =  |   4  |   5  |   6  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   [  |   ]  |   &  |   \  |      |           |      |   *  |   1  |   2  |   3  |   +  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Down |  Up  |                                       |   0  |   ,  |   .  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PGUP |        |      |
 *                                 | Backs|Delete|------|       |------|  Enter |Space |
 *                                 | pace |      | End  |       | PGDN |        |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS

[SYMB] = KEYMAP(
        // left hand
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
        KC_TRNS, KC_GRV,  KC_LABK, KC_RABK, KC_CIRC, KC_DLR,  KC_TRNS,
        KC_TRNS, KC_AT,   KC_LCBR, KC_RCBR, KC_QUES, KC_UNDS,
        KC_TRNS, KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR, KC_BSLS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_DOWN, KC_UP,
                                                     KC_TRNS, KC_TRNS,
                                                              KC_HOME,
                                            KC_BSPC, KC_DELT, KC_END,
        // right hand
        KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_PERC, KC_TRNS,
                 KC_EQL,  KC_4,    KC_5,    KC_6,    KC_MINS, KC_TRNS,
        KC_TRNS, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_PLUS, KC_TRNS,
                          KC_0,    KC_COMM, KC_DOT,  KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS,
        KC_PGUP,
        KC_PGDN, KC_ENT,  KC_SPC
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
// TxBolt Codes
#define Sl 0b00000001
#define Tl 0b00000010
#define Kl 0b00000100
#define Pl 0b00001000
#define Wl 0b00010000
#define Hl 0b00100000
#define Rl 0b01000001
#define Al 0b01000010
#define Ol 0b01000100
#define X  0b01001000
#define Er 0b01010000
#define Ur 0b01100000
#define Fr 0b10000001
#define Rr 0b10000010
#define Pr 0b10000100
#define Br 0b10001000
#define Lr 0b10010000
#define Gr 0b10100000
#define Tr 0b11000001
#define Sr 0b11000010
#define Dr 0b11000100
#define Zr 0b11001000
#define NM 0b11010000
#define GRPMASK 0b11000000
#define GRP0 0b00000000
#define GRP1 0b01000000
#define GRP2 0b10000000
#define GRP3 0b11000000
/* Keymap 3: TxBolt (Serial)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BKSPC  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   S  |   T  |   P  |   H  |------|           |------|   F  |   P  |   L  |   T  |   D  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   S  |   K  |   W  |   R  |  *   |           |   *  |   R  |   B  |   G  |   S  |   Z  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|   E  |   U  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// TxBolt over Serial
[TXBOLT] = KEYMAP(
       KC_BSPC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  
       KC_NO,   KC_NO,   M(NM),   M(NM),   M(NM),   M(NM),   KC_NO,  
       KC_NO,   KC_NO,   M(Sl),   M(Tl),   M(Pl),   M(Hl),
       KC_NO,   KC_NO,   M(Sl),   M(Kl),   M(Wl),   M(Rl),   M(X),
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                           KC_NO,   KC_NO,  
                                                    KC_NO,  
                                  M(Al),   M(Ol),   KC_NO,  
    // right hand
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   
       KC_TRNS,  M(NM),   M(NM),   M(NM),   M(NM),   M(NM),  KC_NO,   
                 M(Fr),   M(Pr),   M(Lr),   M(Tr),   M(Dr),  KC_NO,   
       M(X),     M(Rr),   M(Br),   M(Gr),   M(Sr),   M(Zr),  KC_NO,   
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  
       KC_NO,   KC_NO,  
       KC_NO,  
       KC_NO,   M(Er),   M(Ur)
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

uint8_t chord[4] = {0,0,0,0};
uint8_t pressed_count = 0;

void send_chord(void)
{
  for(uint8_t i = 0; i < 4; i++)
  {
    if(chord[i])
      virtser_send(chord[i]);
  }
  virtser_send(0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  // We need to track keypresses in all modes, in case the user
  // changes mode whilst pressing other keys.
  if (record->event.pressed)
    pressed_count++;
  else
    pressed_count--;
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function

  if (record->event.pressed) {
    uint8_t grp = (id & GRPMASK) >> 6;
    chord[grp] |= id;
  }
  else {
    if (pressed_count == 0) {
      send_chord();
      chord[0] = chord[1] = chord[2] = chord[3] = 0;
    }
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
