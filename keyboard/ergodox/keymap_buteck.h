/*
 * Bu-TECK inspired Layout. Credit to Oobly
 * https://geekhack.org/index.php?topic=49721.msg1078758#msg1078758
 *
 * NOTES:
 * To be used with QWERTY US 101-key keyboard layout
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
 */

enum macro_id {
  CTRLX,
  CTRL_ALT_LEFT,
  CTRL_ALT_RIGHT,
  CTRL_ALT_L,
  OPEN_PARENTHESIS,
  CLOSE_PARENTHESIS,
  EURO,
  POUND,
  ENHE,
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
    [8] =  ACTION_MODS_KEY(MOD_LSFT, KC_BSLASH),      // FN8  -  Hold=Left-Shift, Tap='\'
    [9] =  ACTION_MODS_KEY(MOD_LSFT, KC_GRAVE),       // FN9  -  Hold=Left-Shift, Tap='`'
    [10] = ACTION_MODS_KEY(MOD_LSFT, KC_1),           // FN10 -  Hold=Left-Shift, Tap=1
    [11] = ACTION_MODS_KEY(MOD_LSFT, KC_2),           // FN11 -  Hold=Left-Shift, Tap=2
    [12] = ACTION_MODS_KEY(MOD_LSFT, KC_3),           // FN12 -  Hold=Left-Shift, Tap=3
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_4),           // FN13 -  Hold=Left-Shift, Tap=4
    [14] = ACTION_MODS_KEY(MOD_LSFT, KC_5),           // FN14 -  Hold=Left-Shift, Tap=5
    [15] = ACTION_MODS_KEY(MOD_LSFT, KC_6),           // FN15 -  Hold=Left-Shift, Tap=6
    [16] = ACTION_MODS_KEY(MOD_LSFT, KC_7),           // FN16 -  Hold=Left-Shift, Tap=7
    [17] = ACTION_MACRO(OPEN_PARENTHESIS),            // FN17 -  Unshifted='(', Shifted=PgUp
    [18] = ACTION_MACRO(CLOSE_PARENTHESIS),           // FN18 -  Unshifted=')', Shifted=PgDown
    [19] = ACTION_MODS_KEY(MOD_LSFT, KC_MINUS),       // FN19 -  Hold=Left-Shift, Tap='-'
    [20] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRACKET),    // FN20 -  Hold=Left-Shift, Tap='['
    [21] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRACKET),    // FN21 -  Hold=Left-Shift, Tap=']'
    [22] = ACTION_MODS_KEY(MOD_LSFT, KC_SLASH),       // FN22 -  Hold=Left-Shift, Tap='/'
    [23] = ACTION_MODS_KEY(MOD_LSFT, KC_SCOLON),      // FN23 -  Hold=Left-Shift, Tap=';'
    [24] = ACTION_MODS_KEY(MOD_LSFT, KC_COMMA),       // FN24 -  Hold=Left-Shift, Tap=','
    [25] = ACTION_MODS_KEY(MOD_LSFT, KC_DOT),         // FN25 -  Hold=Left-Shift, Tap='.'
    [26] = ACTION_MODS_KEY(MOD_LSFT, KC_QUOTE),       // FN26 -  Hold=Left-Shift, Tap="'"
    [27] = ACTION_MACRO(EURO),                        // FN27 -  Hold=AltGr, Tap='=', Tap=e
    [28] = ACTION_MACRO(POUND),                       // FN28 -  Hold=AltGr, Tap=l, Tap=-
    [29] = ACTION_MACRO(ENHE),                        // FN29 -  Hold=AltGr, Tap=n, Hold,LShift, Tap=Grave
};

/* Define function actions for readability of keymap below */
#define KC_TML       KC_FN0
#define KC_AML       KC_FN1
#define KC_EMS       KC_FN2
#define KC_RMS       KC_FN3
#define KC_CTRLX     KC_FN4
#define KC_CTALLEFT  KC_FN5
#define KC_CTALRGHT  KC_FN6
#define KC_CTRLALTL  KC_FN7
#define KC_PIPE      KC_FN8
#define KC_TILDE     KC_FN9
#define KC_EXCL      KC_FN10
#define KC_AT        KC_FN11
#define KC_HASH      KC_FN12
#define KC_DOLLR     KC_FN13
#define KC_PRCNT     KC_FN14
#define KC_CARET     KC_FN15
#define KC_AMPRS     KC_FN16
#define KC_OPAREN    KC_FN17
#define KC_CPAREN    KC_FN18
#define KC_UNDRSC    KC_FN19
#define KC_OCUBRC    KC_FN20
#define KC_CCUBRC    KC_FN21
#define KC_QUESTN    KC_FN22
#define KC_COLON     KC_FN23
#define KC_SMLRT     KC_FN24
#define KC_GRTRT     KC_FN25
#define KC_DQUOT     KC_FN26
#define KC_EURO      KC_FN27
#define KC_POUND     KC_FN28
#define KC_ENHE      KC_FN29

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0:
     * ,-----------------------------------------------.           ,----------------------------------------------------.
     * |  Esc   |   1  |  2  |  3  |  4   |  5  |  /   |           |   |  |   6   |   7   |   8  |  9   |  0   |    [{  |
     * |--------+------+-----+-----+------+------------|           |------+-------+-------+------+------+------+--------|
     * |  Tab   |   B  |  U  |  Q  |  .>  |  X  | Left |           |  Up  |   P   |   C   |   L  |  M   |   F  |    ]}  |
     * |--------+------+-----+-----+------+-----|      |           |      |-------+-------+------+------+------+--------|
     * | LCtrl  |   H  |  I  | E(S)|  A(L)|  O  |------|           |------|   D   |  T(L) | R(S) |  N   |   S  |    ;:  |
     * |--------+------+-----+-----+------+-----|Right |           | Down |-------+-------+------+------+------+--------|
     * | Ctrl-X |   K  |  Y  | '"  |  ,<  |  =+ |      |           |      |   J   |   G   |   W  |  V   |   Z  |  VolU  |
     * `--------+------+-----+-----+------+------------'           `--------------+-------+------+------+------+--------'
     *  | Mute  |   ~  |  -  | LSft| LCtrl|                                       | LCtrl | LSft | PrevD| NextD|  VolD |
     *  `---------------------------------'                                       `------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | LAlt | Home |       | PgUp | LAlt |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | End  |       |PgDown|      |      |
     *                                 | Tab  | Bkspc|------|       |------|Enter |Space |
     *                                 |      |      | LGui |       | Lock |      |      |
     *                                 `--------------------'       `--------------------'
     *
     *
     * Layer divided in two so we can have transparent keys on the Layer Tap keys
     * Layer 1: Left                                                  Layer2: Right
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           | F12  |  F6  |  F7  |  F8  | F9   |  F10 |  Bkspc |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   `    |  ^   |  [   |  !   |  ]   |  *   | Home |           | PgUp |  ~   |   (  |  Up  |   )  |  $   |  Del   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |CapsLck |  &   |  {   |  ?   |  }   |  +   |------|           |------|  -   | Left | Down |Right |  "   |  Enter |
     * |--------+------+------+------+------+------|  End |           |PgDown|------+------+------+------+------+--------|
     * |        |  %   |  |   |  #   |  ;   |  :   |      |           |      |  /   |  <   |   _  |  >   |  \   |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |  €   |   £  |      |      |                                       |      |      |  Ñ   |  At  |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |  Esc | Del  |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     *
     */

    KEYMAP(  // Layer0, Left hand.
        ESC,     1,       2,      3,      4,   5,  SLSH,
        TAB,     B,       U,      Q,    DOT,   X,  LEFT,
      LCTRL,     H,       I,    EMS,    AML,   O,
      CTRLX,     K,       Y,  QUOTE,  COMMA, EQL, RIGHT,
       MUTE, TILDE,   MINUS, LSHIFT,  LCTRL,

                                       LALT, HOME,
                                              END,
                                  TAB, BSPC, LGUI,

             // Right hand.
             PIPE,    6,    7,      8,        9,        0,   LBRC,
               UP,    P,    C,      L,        M,        F,   RBRC,
                D,  TML,  RMS,      N,        S,   SCOLON,
             DOWN,    J,    G,      W,        V,        Z,   VOLU,
                        LCTRL, LSHIFT, CTALLEFT, CTALRGHT,   VOLD,

           PGUP,    LALT,
           PGDN,
        CTRLALTL, ENT, SPC
    ),

    KEYMAP(  // Layer1, left hand, to be used with TML
            TRNS,    F1,       F2,     F3,       F4,          F5,  F11,
           GRAVE, CARET, LBRACKET,   EXCL, RBRACKET, KP_ASTERISK, HOME,
        CAPSLOCK, AMPRS,   OCUBRC, QUESTN,   CCUBRC,     KP_PLUS,
            TRNS, PRCNT,     PIPE,   HASH,   SCOLON,       COLON,  END,
            TRNS,  EURO,    POUND,   TRNS,     TRNS,

                                       TRNS, TRNS,
                                             TRNS,
                                ESC, DELETE, TRNS,

             // right hand empty
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
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

             // right hand, to be used with AML
                  F12,     F6,     F7,     F8,    F19,    F10,   BSPC,
                 PGUP,  TILDE, OPAREN,     UP, CPAREN,  DOLLR, DELETE,
             KP_MINUS,   LEFT,   DOWN,  RIGHT,  DQUOT,  ENTER,
                 PGDN,  SLASH,  SMLRT, UNDRSC,  GRTRT, BSLASH,     NO,
                                 TRNS,   TRNS,   ENHE,     AT,     NO,
         TRNS, TRNS,
         TRNS,
         TRNS, TRNS, TRNS
    ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if(!record->event.pressed) {
    unregister_mods(MOD_BIT(KC_LCTL));
    return MACRO_NONE;
  }

  switch (id) {
  case CTRLX:
    return MACRO( I(15), D(LCTL), T(X), U(LCTL), END );
  case CTRL_ALT_LEFT:
    return MACRO( I(15), D(LCTL), D(LALT), T(LEFT), U(LALT), U(LCTL), END );
  case CTRL_ALT_RIGHT:
    return MACRO( I(15), D(LCTL), D(LALT), T(RIGHT), U(LALT), U(LCTL), END );
  case OPEN_PARENTHESIS:
    if(!get_mods() & (MOD_BIT(KC_LSHIFT)))    // unshifted: open parenthesis
      return MACRO( I(15), D(LSFT), T(9), U(LSFT), END );
    else                                      // shifted: page up
      return MACRO( I(15), T(PGUP), END );
  case CLOSE_PARENTHESIS:
    if(!get_mods() & (MOD_BIT(KC_LSHIFT)))    // unshifted: close parenthesis
      return MACRO( I(15), D(LSFT), T(0), U(LSFT), END );
    else                                      // shifted: page down
      return MACRO( I(15), T(PGDOWN), END );
  case EURO:
    return MACRO( I(15), D(RALT), T(EQL), T(E), U(RALT), END );
  case POUND:
    return MACRO( I(15), D(RALT), T(L), T(MINUS), U(RALT), END );
  case ENHE:
    return MACRO( I(15), D(RALT), T(N), D(LSHIFT),  T(GRAVE), U(LSHIFT), U(RALT),
                  END );
  case CTRL_ALT_L:
    return MACRO( I(15), D(LCTL), D(LALT), T(L), U(LALT), U(LCTL), END );
  }
  return MACRO_NONE;
}

/*
 * translates Fn keycode to action
 * for some layers, use different translation table
 */
action_t keymap_fn_to_action(uint8_t keycode)
{
    uint8_t layer = biton32(layer_state);

    action_t action;
    action.code = ACTION_NO;

    // by default, use fn_actions from default layer 0
    // this is needed to get mapping for same key, that was used switch to some layer,
    // to have possibility to switch layers back
    if (action.code == ACTION_NO &&
        FN_INDEX(keycode) < (sizeof(fn_actions)   / sizeof(fn_actions[0]))) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    }

    return action;
}
