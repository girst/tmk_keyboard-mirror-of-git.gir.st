#include "keymap_common.h"
   // use ____ or TODO as keyboard keys in KEYMAP
   #define KC_____ KC_NO
   #define KC_TODO KC_NO


/* TODO XXX TODO:
 * single apostrophe has not been placed (best on layer2)
 * 
 * can.t hit ctrl-tab
 * 
 * define bottom row Fn keys
 * 
 * you can only have 32 Fn keys -- migrate shift+key and AltGr+key to actionmap
 * see: https://github.com/tmk/tmk_keyboard/wiki/FAQ-Keymap#actionmap
 *      http://kb.sized.io/
 * currently not placed due to shortage: ctrl-left, ctrl-right, µ
 */

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* Layer: Base Layer
    * ,-------------------------------------------------.
    * |Esc|  Q|  W|  E|  R|  T|  Z|  U|  I|  O|  P| BSp |
    * |-------------------------------------------------|
    * |C/^I|  A|  S|  D|  F|  G|  H|  J|  K|  L|  /|Fn2 |
    * |-------------------------------------------------|
    * |Shift|  Y|  X|  C|  V|  B|  N|  M|  ,|  .|  -|Sft|
    * |-------------------------------------------------|
    * |Alt |  XXX  |XXX |Enter| Space |XXX |XXX  |  Fn3 | TODO: where to put Fn1
    * `-------------------------------------------------'
    */
   KEYMAP(
     ESC ,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,  BSPC, \
     FN0  ,   A,   S,   D,   F,   G,   H,   J,   K,   L,FN11, FN2,  \
     LSHIFT,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH, RSHIFT, \
     LALT,  FN1,  LGUI,     ENT,       SPC,   RALT,   RSFT,  FN3    ),

   /* Layer: Movement Layer (wrd=ctrl-right, bck=crtl-left) TOGGLE
    * ,-------------------------------------------------.
    * |Esc|   |wrd|   |END|   |   |PUp|   |Hom|   | Del | TODO: move Home?
    * |-------------------------------------------------| TODO: ctrl-right: use actionmap
    * |    |   |   |PDn|   |   |Lft| Up| Dn| Rt|   |    |
    * |-------------------------------------------------|
    * |     |Psc|   |   |   |bck|   |   |   |   |   |   | TODO: where NUM, CAPS, SCROLL, PAUSE
    * |-------------------------------------------------| TODO: ctrl-left: use actionmap
    * |    |  Gui  |    |     |       |    |     |      |
    * `-------------------------------------------------'
    */ //TODO
   KEYMAP(
     ESC ,____,TODO,____, END,____,____,PGUP,____,HOME,____,   DEL, \
     TRNS ,____,____,PGDN,____,TRNS,LEFT,DOWN,  UP,RGHT,____, TRNS, \
     TRNS  ,PSCR,____,____,____,TODO,____,____,____,____,____,____, \
     TRNS, TRNS,  TRNS,    TRNS,      TRNS,   TRNS,   TRNS,  TRNS   ),

   /* Layer: Numbers and ASCII-Symbols Layer MOMENTARY+TOGGLE
    * ,-------------------------------------------------.
    * |  ^|  !|  "|  §|  $|  %|  &|  /|  (|  )|  =|   ? |
    * |-------------------------------------------------|
    * |   `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|Fn2 | TODO: where to put FN15='
    * |-------------------------------------------------|
    * |    #|  <|  ||  >|  +|  *|  {|  [|  ]|  }|  \|  ~|
    * |-------------------------------------------------|
    * |    |       |    |     |       |    |     |      |
    * `-------------------------------------------------'
    */
   KEYMAP(
     GRV , FN5, FN6, FN7, FN8, FN9,FN10,FN11,FN12,FN13,FN14,  FN17, \
     FN18 ,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0, TRNS, \
     BSLS  ,NUBS,FN30,FN31,RBRC,FN20,FN24,FN25,FN26,FN27,FN28,FN29, \
     TRNS, TRNS,  TRNS,    TRNS,      TRNS,   TRNS,   TRNS,  TRNS   ),

   /* Layer: Layer for Function keys and Unicode Symbols MOMENTARY
    * ,-------------------------------------------------.
    * | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|  F12|
    * |-------------------------------------------------|
    * |    |   |   |   |   |   |   |   |  Ä|  Ö|  Ü|Entr| Ä=" Ö=: Ü={
    * |-------------------------------------------------|
    * |     |   |   |  °|  ²|  ³|  µ|  ä|  ö|  ü|  ß|   | ä=' ö=; ü=[ ß=-
    * |-------------------------------------------------| TODO: µ
    * |    |       |    |Space| Enter |    |     |      |
    * `-------------------------------------------------'
    */
   KEYMAP(
     F1  ,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11,   F12, \
     TRNS ,____,____,____,____,____,____,____,FN16,FN21,FN19,  ENT, \
     TRNS  ,____,____, FN4,FN22,FN23,TODO,QUOT,SCLN,LBRC,MINS,RSFT, \
     TRNS, TRNS,  TRNS,     SPC,       ENT,   TRNS,   TRNS,  TRNS  ),
};

const action_t PROGMEM fn_actions[] = {
    [0] =  ACTION_MODS_TAP_KEY(MOD_LCTL, KC_TAB),
    [1]  = ACTION_LAYER_MOMENTARY(1),
    [2]  = ACTION_LAYER_MOMENTARY(2),
    [3]  = ACTION_LAYER_MOMENTARY(3),
    [4]  = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),
    [5]  = ACTION_MODS_KEY(MOD_LSFT, KC_1),
    [6]  = ACTION_MODS_KEY(MOD_LSFT, KC_2),
    [7]  = ACTION_MODS_KEY(MOD_LSFT, KC_3),
    [8]  = ACTION_MODS_KEY(MOD_LSFT, KC_4),
    [9]  = ACTION_MODS_KEY(MOD_LSFT, KC_5),
    [10] = ACTION_MODS_KEY(MOD_LSFT, KC_6),
    [11] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
    [12] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
    [14] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
    [15] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS), // #' key
    [16] = ACTION_MODS_KEY(MOD_LSFT, KC_QUOT), // ä key
    [17] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS), // ß?\ key
    [18] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL),  // ´` key
    [19] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC), // ü key
    [20] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC), // +*~ key
    [21] = ACTION_MODS_KEY(MOD_LSFT, KC_SCLN), // ö key
    [22] = ACTION_MODS_KEY(MOD_RALT, KC_2), // ²
    [23] = ACTION_MODS_KEY(MOD_RALT, KC_3), // ³
    [24] = ACTION_MODS_KEY(MOD_RALT, KC_7), // {
    [25] = ACTION_MODS_KEY(MOD_RALT, KC_8), // [
    [26] = ACTION_MODS_KEY(MOD_RALT, KC_9), // ]
    [27] = ACTION_MODS_KEY(MOD_RALT, KC_0), // }
    [28] = ACTION_MODS_KEY(MOD_RALT, KC_MINS), // "\"
    [29] = ACTION_MODS_KEY(MOD_RALT, KC_RBRC), // ~
    [30] = ACTION_MODS_KEY(MOD_RALT, KC_NUBS), // <|>
    [31] = ACTION_MODS_KEY(MOD_LSFT, KC_NUBS), // <|>
    //[32] = ACTION_MODS_KEY(MOD_RALT, KC_M), // µ TODO: use actionmap
};
