/*
 * NOTES:
 * ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT)
 * Works as a modifier key while holding, but registers a key on tap(press and release quickly)
 *
 * ACTION_LAYER_MOMENTARY(layernumber)
 * it activates when key is pressed and deactivate when released
 * From the docs it seems like the destination layer button must be the same or transparent.
 *
 * ACTION_LAYER_TOGGLE(layer)
 * Turns on layer with first type(press and release) and turns off with next.
 *
 * ACTION_LAYER_TAP_KEY(layer, key)
 * Turns on layer momentary while holding, but registers key on tap(press and release quickly).
 *
 * ACTION_LAYER_SET(layer, on)
 * Turn on layer only. layer_state = (1<<layer) [layer: 0-31]
 *
 * MACRO()
 *
 * ACTION_FUNCTION(id, opt)
 * Not sure how it's different from ACTION_FUNCTION_TAP
 *
 */
static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0:
     * ,-----------------------------------------------.           ,----------------------------------------------------.
     * |  Esc   |   1  |  2  |  3  |  4   |  5  |  |   |           | Tab  |   6   |   7   |   8  |  9   |  0   |    [{  |
     * |--------+------+-----+-----+------+------------|           |------+-------+-------+------+------+------+--------|
     * |  ~     |   B  |  U  |  Q  |  .>  |  X  | Left |           |  Up  |   P   |   C   |   L  |  M   |   F  |    ]}  |
     * |--------+------+-----+-----+------+-----|      |           |      |-------+-------+------+------+------+--------|
     * | LShift |   H  |  I  |  E  |  A   |  O  |------|           |------|   D   |   T   |   R  |  N   |   S  |    ;:  |
     * |--------+------+-----+-----+------+-----|Right |           | Down |-------+-------+------+------+------+--------|
     * | LCtrl  |   K  |  Y  | '"  |  ,<  |  =+ |      |           |      |   J   |   G   |   W  |  V   |   Z  | RCtrl  |
     * `--------+------+-----+-----+------+------------'           `--------------+-------+------+------+------+--------'
     *  | LAlt  | LGui |  /  |CtrlX| Lock |                                       | DeskL | DeskR| VolD | VolU | RAlt  |
     *  `---------------------------------'                                       `------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |   -  | Home |       | PgUp | ~L1  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | End  |       |PgDown|      |      |
     *                                 |Bkspc | ~L1  |------|       |------|Enter |Space |
     *                                 |      |      |LShift|       |RShift|      |      |
     *                                 `--------------------'       `--------------------'
     *
     * Layer 1:
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           | F12  |  F6  |  F7  |  F8  | F9   |  F10 |  Bkspc |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   `    |  ^   |  [   |  !   |  ]   |  *   | Paste|           | Undo |  ~   |   (  |  Up  |   )  |  "   |  Del   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |CapsLck |  &   |  {   |  ?   |  }   |  +   |------|           |------|  -   | Left | Down |Right | At   |  Enter |
     * |--------+------+------+------+------+------| Copy |           | Cut  |------+------+------+------+------+--------|
     * |        |  %   |  |   |  #   |  ;   |  :   |      |           |      |  /   |  <   |   _  |  >   |  \   |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |  $   |                                       |  €   |   £  | Mute | Mute |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |!MS_1 |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |!MS_2 |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |!MS_3 |      |      |
     *                                 `--------------------'       `--------------------'
     *
     * Layer 2:  (NOT USED. IT'S BUGGY)
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |MSWUp | MSUp |MSWDwn|      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------|      |MSLeft|MSDown|MSRght|      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |MSWLft|      |MSWRht|      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'

     */

    KEYMAP(  // Layer0, Left hand.
        ESC,    1,     2,     3,      4,   5,  FN8,
        FN9,    B,     U,     Q,    DOT,   X,  LEFT,
     LSHIFT,    H,     I,     E,      A,   O,
      LCTRL,    K,     Y, QUOTE,  COMMA, EQL, RIGHT,
       LALT, LGUI,  SLSH,   FN4,   STOP,

                                        MINUS, HOME,
                                                END,
                                 BSPC,  FN1, LSHIFT,

            // Right hand.
                TAB,    6,    7,    8,   9,   0,   LBRC,
                 UP,    P,    C,    L,   M,   F,   RBRC,
                        D,    T,    R,   N,   S, SCOLON,
               DOWN,    J,    G,    W,   V,   Z,  RCTRL,
                           FN5, FN6, VOLD, VOLU,   RALT,

         PGUP, FN1,
         PGDN,
         RSHIFT, ENT, SPC
    ),

    KEYMAP(  // Layer1, left hand
        TRNS,  F1,  F2,  F3,  F4,  F5,  F11,
        GRV, FN15, LBRACKET, FN10, RBRACKET, KP_ASTERISK, PASTE,
        CAPSLOCK, FN16, FN20, FN22, FN21, KP_PLUS,
        TRNS, FN14, FN8, FN12, SCOLON, FN23, COPY,
        TRNS, TRNS, TRNS, TRNS, FN13,
                                      TRNS, TRNS,
                                            TRNS,
                                TRNS, TRNS, TRNS,
        // right hand
              F12,   F6,  F7,   F8,   F19,  F10,  BSPC,
               UNDO, FN9, FN17, UP, FN18, FN24, DELETE,
                 MINUS, LEFT, DOWN, RIGHT, FN11, ENTER,
            CUT, SLASH, FN25, FN19, FN26, BSLASH, TRNS,
                          TRNS, TRNS, MUTE, MUTE, TRNS,
         TRNS, TRNS,
         TRNS,
         TRNS, TRNS, TRNS
    ),

    KEYMAP(  // Layer2, left hand
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS,
                                      TRNS, TRNS,
                                            TRNS,
                                TRNS, TRNS, TRNS,
        // right hand
             TRNS, TRNS,    TRNS,    TRNS,     TRNS, TRNS, TRNS,
            TRNS, TRNS, MS_WH_UP, MS_UP, MS_WH_DOWN, TRNS, TRNS,
                   TRNS, MS_LEFT, MS_DOWN, MS_RIGHT, TRNS, TRNS,
          TRNS, TRNS, MS_WH_LEFT, TRNS, MS_WH_RIGHT, TRNS, TRNS,
                            TRNS,    TRNS,     TRNS, TRNS, TRNS,
         TRNS, TRNS,
         TRNS,
         TRNS, TRNS, TRNS
    ),
};

/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
    CUSTOM_KEY,
    CTRLC_AND_LALT,
};

enum macro_id {
  CTRLX,
  CTRL_ALT_LEFT,
  CTRL_ALT_RIGHT,
  PIPE,
  TILDE,
  EXCLAMATION,
  AT,
  HASH,
  DOLLAR,
  PERCENT,
  CARET,
  AMPERSAND,
  OPEN_PARENTHESIS,
  CLOSE_PARENTHESIS,
  UNDERSCORE,
  LBRACES,
  RBRACES,
  QUESTION,
  COLON,
  DQUOTES,
  SMALLER_THAN,
  GREATER_THAN,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [1] =  ACTION_LAYER_MOMENTARY(1),                 // FN1  -  Momentary L1
    [2] =  ACTION_LAYER_MOMENTARY(2),                 // FN2  -  Momentary L2
    [4] =  ACTION_MACRO(CTRLX),                       // FN5  -  Ctrl-X
    [5] =  ACTION_MACRO(CTRL_ALT_LEFT),               // FN6  -  Ctrl-Alt-Left
    [6] =  ACTION_MACRO(CTRL_ALT_RIGHT),              // FN7  -  Ctrl-Alt-Right
    [8] =  ACTION_MACRO(PIPE),                        // FN4  -  Tap=\, Hold=Left-Shift
    [9] =  ACTION_MACRO(TILDE),                       // FN9  -  Tap=`, Hold=Left-Shift
    [10] = ACTION_MACRO(EXCLAMATION),                 // FN10 -  Tap=1, Hold=Left-Shift
    [11] = ACTION_MACRO(AT),                          // FN11 -  Tap=2, Hold=Left-Shift
    [12] = ACTION_MACRO(HASH),                        // FN12 -  Tap=3, Hold=Left-Shift
    [13] = ACTION_MACRO(DOLLAR),                      // FN13 -  Tap=4, Hold=Left-Shift
    [14] = ACTION_MACRO(PERCENT),                     // FN14 -  Tap=5, Hold=Left-Shift
    [15] = ACTION_MACRO(CARET),                       // FN15 -  Tap=6, Hold=Left-Shift
    [16] = ACTION_MACRO(AMPERSAND),                   // FN16 -  Tap=7, Hold=Left-Shift
    [17] = ACTION_MACRO(OPEN_PARENTHESIS),            // FN17 -  Tap=9, Hold=Left-Shift
    [18] = ACTION_MACRO(CLOSE_PARENTHESIS),           // FN18 -  Tap=0, Hold=Left-Shift
    [19] = ACTION_MACRO(UNDERSCORE),                  // FN19 -  Tap=-, Hold=Left-Shift
    [20] = ACTION_MACRO(LBRACES),                     // FN20 -  Tap=[, Hold=Left-Shift
    [21] = ACTION_MACRO(RBRACES),                     // FN21 -  Tap=], Hold=Left-Shift
    [22] = ACTION_MACRO(QUESTION),                    // FN22 -  Tap=/, Hold=Left-Shift
    [23] = ACTION_MACRO(COLON),                       // FN23 -  Tap=;, Hold=Left-Shift
    [24] = ACTION_MACRO(DQUOTES),                     // FN24 -  Tap=', Hold=Left-Shift
    [25] = ACTION_MACRO(SMALLER_THAN),                // FN25 -  Tap=,, Hold=Left-Shift
    [26] = ACTION_MACRO(GREATER_THAN),                // FN26 -  Tap=., Hold=Left-Shift
};

static const uint16_t PROGMEM fn_actions_1[] = {
    [0] = ACTION_LAYER_SET(0, ON_BOTH),                   // FN0  - Set Layer0
    [1] = ACTION_FUNCTION(TEENSY_KEY),                    // FN1  - Teensy key
};

static const uint16_t PROGMEM fn_actions_2[] = {
    [0] = ACTION_LAYER_SET(0, ON_BOTH),                   // FN0  - Set Layer0
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // print("action_function called\n");
    // print("id  = "); phex(id); print("\n");
    // print("opt = "); phex(opt); print("\n");

    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(50);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }

    if (id == CTRLC_AND_LALT) {
      if (record->event.pressed) {
        if (record->tap.count > 0 && !record->tap.interrupted) {
          if (record->tap.interrupted) {
            register_mods(MOD_BIT(KC_LALT));
          }
        } else {
          register_mods(MOD_BIT(KC_LALT));
        }
      } else {
        if (record->tap.count > 0 && !(record->tap.interrupted)) {
          add_weak_mods(MOD_BIT(KC_LCTL));
          send_keyboard_report();
          register_code(KC_C);
          unregister_code(KC_C);
          del_weak_mods(MOD_BIT(KC_LCTL));
          send_keyboard_report();
          record->tap.count = 0;  // ad hoc: cancel tap
        } else {
          unregister_mods(MOD_BIT(KC_LALT));
        }
      }
    }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
  case CTRLX:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LCTL), T(X), U(LCTL), END ) :
            MACRO_NONE);
  case PIPE:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(BSLS), U(LSFT), END ) :
            MACRO_NONE);
  case TILDE:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(GRAVE), U(LSFT), END ) :
            MACRO_NONE);
  case EXCLAMATION:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(1), U(LSFT), END ) :
            MACRO_NONE);
  case AT:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(2), U(LSFT), END ) :
            MACRO_NONE);
  case HASH:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(3), U(LSFT), END ) :
            MACRO_NONE);
  case DOLLAR:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(4), U(LSFT), END ) :
            MACRO_NONE);
  case PERCENT:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(5), U(LSFT), END ) :
            MACRO_NONE);
  case CARET:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(6), U(LSFT), END ) :
            MACRO_NONE);
  case AMPERSAND:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(7), U(LSFT), END ) :
            MACRO_NONE);
  case OPEN_PARENTHESIS:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(9), U(LSFT), END ) :
            MACRO_NONE);
  case CLOSE_PARENTHESIS:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(0), U(LSFT), END ) :
            MACRO_NONE);
  case UNDERSCORE:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(MINUS), U(LSFT), END ) :
            MACRO_NONE);
  case LBRACES:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(LBRACKET), U(LSFT), END ) :
            MACRO_NONE);
  case RBRACES:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(RBRACKET), U(LSFT), END ) :
            MACRO_NONE);
  case QUESTION:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(SLASH), U(LSFT), END ) :
            MACRO_NONE);
  case COLON:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(SCOLON), U(LSFT), END ) :
            MACRO_NONE);
  case DQUOTES:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(QUOTE), U(LSFT), END ) :
            MACRO_NONE);
  case SMALLER_THAN:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(COMMA), U(LSFT), END ) :
            MACRO_NONE);
  case GREATER_THAN:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(DOT), U(LSFT), END ) :
            MACRO_NONE);
  case CTRL_ALT_LEFT:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LCTL), D(LALT), T(LEFT), U(LALT), U(LCTL), END ) :
            MACRO_NONE);
  case CTRL_ALT_RIGHT:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LCTL), D(LALT), T(RIGHT), U(LALT), U(LCTL), END ) :
            MACRO_NONE);
  }
  return MACRO_NONE;
}

#define FN_ACTIONS_SIZE     (sizeof(fn_actions)   / sizeof(fn_actions[0]))
#define FN_ACTIONS_1_SIZE   (sizeof(fn_actions_1) / sizeof(fn_actions_1[0]))
#define FN_ACTIONS_2_SIZE   (sizeof(fn_actions_2) / sizeof(fn_actions_2[0]))

/*
 * translates Fn keycode to action
 * for some layers, use different translation table
 */
action_t keymap_fn_to_action(uint8_t keycode)
{
    uint8_t layer = biton32(layer_state);

    action_t action;
    action.code = ACTION_NO;

    if (layer == 1 && FN_INDEX(keycode) < FN_ACTIONS_1_SIZE) {
        action.code = pgm_read_word(&fn_actions_1[FN_INDEX(keycode)]);
    }
    if (layer == 2 && FN_INDEX(keycode) < FN_ACTIONS_2_SIZE) {
        action.code = pgm_read_word(&fn_actions_2[FN_INDEX(keycode)]);
    }

    // by default, use fn_actions from default layer 0
    // this is needed to get mapping for same key, that was used switch to some layer,
    // to have possibility to switch layers back
    if (action.code == ACTION_NO && FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    }

    return action;
}
