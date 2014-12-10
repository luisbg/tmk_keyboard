/*
 * Bu-TECK inspired Layout. Credit to Oobly
 * https://geekhack.org/index.php?topic=49721.msg1078758#msg1078758
 *
 * NOTES:
 * To be used with QWERTY US International keyboard layout
 * http://en.wikipedia.org/wiki/QWERTY#US-International
 *
 * ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT)
 * Works as a modifier key while holding, but registers a key on tap(press and release quickly)
 * From the docs it seems like the destination layer button must be the same or transparent.
 *
 * ACTION_LAYER_TAP_KEY(layer, key)
 * Turns on layer momentary while holding, but registers key on tap(press and release quickly).
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
     * |  Tab   |   B  |  U  |  Q  |  .>  |  X  | Left |           |  Up  |   P   |   C   |   L  |  M   |   F  |    ]}  |
     * |--------+------+-----+-----+------+-----|      |           |      |-------+-------+------+------+------+--------|
     * | LCtrl  |   H  |  I  | E(S)|  A(L)|  O  |------|           |------|   D   |  T(L) | R(S) |  N   |   S  |    ;:  |
     * |--------+------+-----+-----+------+-----|Right |           | Down |-------+-------+------+------+------+--------|
     * | LShift |   K  |  Y  | '"  |  ,<  |  =+ |      |           |      |   J   |   G   |   W  |  V   |   Z  | RShift |
     * `--------+------+-----+-----+------+------------'           `--------------+-------+------+------+------+--------'
     *  | LGui  |   /  |  -  |CtrlX| Lock |                                       | DeskL | DeskR| VolD | VolU | Mute  |
     *  `---------------------------------'                                       `------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | LAlt | Home |       | PgUp | RAlt |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | End  |       |PgDown|      |      |
     *                                 |Space | Bkspc|------|       |------|Enter |Space |
     *                                 |      |      |LCtrl |       |RCtrl |      |      |
     *                                 `--------------------'       `--------------------'
     *
     *
     * Layer divided in two so we can have transparent keys on the Layer Tap keys
     * Layer 1: Left                                                  Layer2: Right
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           | F12  |  F6  |  F7  |  F8  | F9   |  F10 |  Bkspc |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   `    |  ^   |  [   |  !   |  ]   |  *   | Paste|           | PgUp |  ~   |   (  |  Up  |   )  |  "   |  Del   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |CapsLck |  &   |  {   |  ?   |  }   |  +   |------|           |------|  -   | Left | Down |Right | At   |  Enter |
     * |--------+------+------+------+------+------| Copy |           |PgDown|------+------+------+------+------+--------|
     * |        |  %   |  |   |  #   |  ;   |  :   |      |           |      |  /   |  <   |   _  |  >   |  \   |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |  $   |   €  |  £   |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      | Del  |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     *
     */

    KEYMAP(  // Layer0, Left hand.
        ESC,    1,     2,     3,      4,   5,  FN8,
        TAB,    B,     U,     Q,    DOT,   X,  LEFT,
      LCTRL,    H,     I,   FN2,    FN1,   O,
     LSHIFT,    K,     Y,  FN27,  COMMA, EQL, RIGHT,
       LGUI, SLSH, MINUS,   FN4,   FN7,

                                       LALT,   HOME,
                                                END,
                                  SPC, BSPC,  LCTRL,

            // Right hand.
                TAB,    6,    7,    8,   9,   0,   LBRC,
                 UP,    P,    C,    L,   M,   F,   RBRC,
                        D,  FN0,  FN3,   N,   S, SCOLON,
               DOWN,    J,    G,    W,   V,   Z, RSHIFT,
                           FN5, FN6, VOLD, VOLU,   MUTE,

         PGUP, LALT,
         PGDN,
         RCTRL, ENT, SPC
    ),

    KEYMAP(  // Layer1, left hand, to be used with FN0
        TRNS,  F1,  F2,  F3,  F4,  F5,  F11,
        FN24, FN15, LBRACKET, FN10, RBRACKET, KP_ASTERISK, PASTE,
        CAPSLOCK, FN16, FN20, FN22, FN21, KP_PLUS,
        TRNS, FN14, FN8, FN12, SCOLON, FN23, COPY,
        TRNS, TRNS, TRNS, TRNS, TRNS,
                                      TRNS, TRNS,
                                            TRNS,
                              TRNS, DELETE, TRNS,
        // right hand empty
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer2, left hand, empty
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS,
                                      TRNS, TRNS,
                                            TRNS,
                                TRNS, TRNS, TRNS,
        // right hand, to be used with FN1
              F12,   F6,  F7,   F8,   F19,  F10,  BSPC,
               PGUP, FN9, FN17, UP, FN18, FN28, DELETE,

              KP_MINUS, LEFT, DOWN, RIGHT, FN11, ENTER,
           PGDN, SLASH, FN25, FN19, FN26, BSLASH, TRNS,
                          FN13, FN29, FN30, TRNS, TRNS,
         TRNS, TRNS,
         TRNS,
         TRNS, TRNS, TRNS
    ),
};

/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
};

enum macro_id {
  CTRLX,
  CTRL_ALT_LEFT,
  CTRL_ALT_RIGHT,
  CTRL_ALT_L,
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
  GRAVE,
  SMALLER_THAN,
  GREATER_THAN,
  QUOTE,
  DQUOTES,
  EURO,
  POUND,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [0] =  ACTION_LAYER_TAP_KEY(1, KC_T),             // FN0  -  Momentary Layer1 on A key
    [1] =  ACTION_LAYER_TAP_KEY(2, KC_A),             // FN1  -  Momentary Layer1 on T key
    [2] =  ACTION_MODS_TAP_KEY(MOD_LSFT, KC_E),       // FN2  -  Tap for E, Hold for Shift
    [3] =  ACTION_MODS_TAP_KEY(MOD_LSFT, KC_R),       // FN3  -  Tap for R, Hold for Shift
    [4] =  ACTION_MACRO(CTRLX),                       // FN4  -  Ctrl-X
    [5] =  ACTION_MACRO(CTRL_ALT_LEFT),               // FN5  -  Ctrl-Alt-Left
    [6] =  ACTION_MACRO(CTRL_ALT_RIGHT),              // FN6  -  Ctrl-Alt-Right
    [7] =  ACTION_MACRO(CTRL_ALT_L),                  // FN7  -  Ctrl-Alt-L, set in the window manager to lock screen
    [8] =  ACTION_MACRO(PIPE),                        // FN8  -  Tap=\, Hold=Left-Shift
    [9] =  ACTION_MACRO(TILDE),                       // FN9  -  Tap=`, Hold=Left-Shift, Tap=Space
    [10] = ACTION_MACRO(EXCLAMATION),                 // FN10 -  Tap=1, Hold=Left-Shift
    [11] = ACTION_MACRO(AT),                          // FN11 -  Tap=2, Hold=Left-Shift
    [12] = ACTION_MACRO(HASH),                        // FN12 -  Tap=3, Hold=Left-Shift
    [13] = ACTION_MACRO(DOLLAR),                      // FN13 -  Tap=4, Hold=Left-Shift
    [14] = ACTION_MACRO(PERCENT),                     // FN14 -  Tap=5, Hold=Left-Shift
    [15] = ACTION_MACRO(CARET),                       // FN15 -  Tap=6, Hold=Left-Shift. Tap=Space
    [16] = ACTION_MACRO(AMPERSAND),                   // FN16 -  Tap=7, Hold=Left-Shift
    [17] = ACTION_MACRO(OPEN_PARENTHESIS),            // FN17 -  Tap=9, Hold=Left-Shift
    [18] = ACTION_MACRO(CLOSE_PARENTHESIS),           // FN18 -  Tap=0, Hold=Left-Shift
    [19] = ACTION_MACRO(UNDERSCORE),                  // FN19 -  Tap=-, Hold=Left-Shift
    [20] = ACTION_MACRO(LBRACES),                     // FN20 -  Tap=[, Hold=Left-Shift
    [21] = ACTION_MACRO(RBRACES),                     // FN21 -  Tap=], Hold=Left-Shift
    [22] = ACTION_MACRO(QUESTION),                    // FN22 -  Tap=/, Hold=Left-Shift
    [23] = ACTION_MACRO(COLON),                       // FN23 -  Tap=;, Hold=Left-Shift
    [24] = ACTION_MACRO(GRAVE),                       // FN24 -  Tap=`, Hold=Left-Shift, Tap=Space
    [25] = ACTION_MACRO(SMALLER_THAN),                // FN25 -  Tap=,, Hold=Left-Shift
    [26] = ACTION_MACRO(GREATER_THAN),                // FN26 -  Tap=., Hold=Left-Shift
    [27] = ACTION_MACRO(QUOTE),                       // FN27 -  Tap=', Tap=Space
    [28] = ACTION_MACRO(DQUOTES),                     // FN28 -  Tap=', Hold=Left-Shift, Tap=Space
    [29] = ACTION_MACRO(EURO),                        // FN29 -  Tap=5, Hold=AltGr
    [30] = ACTION_MACRO(POUND),                       // FN30 -  Tap=4, Hold=Left-Shift, Hold=AltGr
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
            MACRO( I(15), D(LSFT), T(GRAVE), U(LSFT), T(SPC), END ) :
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
            MACRO( I(15), D(LSFT), T(6), U(LSFT), T(SPC), END ) :
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
  case GRAVE:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), T(GRAVE), T(SPC), END ) :
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
  case QUOTE:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), T(QUOTE), T(SPC), END ) :
            MACRO_NONE);
  case DQUOTES:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LSFT), T(QUOTE), U(LSFT), T(SPC), END ) :
            MACRO_NONE);
  case CTRL_ALT_LEFT:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LCTL), D(LALT), T(LEFT), U(LALT), U(LCTL), END ) :
            MACRO_NONE);
  case EURO:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(RALT), T(5), U(RALT), END ) :
            MACRO_NONE);
  case POUND:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(RALT), D(LSHIFT), T(4), U(LSHIFT), U(RALT), END ) :
            MACRO_NONE);
  case CTRL_ALT_RIGHT:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LCTL), D(LALT), T(RIGHT), U(LALT), U(LCTL), END ) :
            MACRO_NONE);
  case CTRL_ALT_L:
    if(!record->event.pressed) {
      unregister_mods(MOD_BIT(KC_LCTL));
    }
    return (record->event.pressed ?
            MACRO( I(15), D(LCTL), D(LALT), T(L), U(LALT), U(LCTL), END ) :
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
