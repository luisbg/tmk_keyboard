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
     * |  `~    |   1  |  2  |  3  |  4   |  5  |   6  |           |   7  |   8   |   9   |   0  |  KP0 |  =+  |   \|   |
     * |--------+------+-----+-----+------+------------|           |------+-------+-------+------+------+------+--------|
     * |  Tab   |   Q  |  F  |  W  |  R   |  Y  | Home |           | End  |  ;:   |   H   |   J  |  K   |   L  |  PgUp  |
     * |--------+------+-----+-----+------+-----|      |           |      |-------+-------+------+------+------+--------|
     * |  '"    |   A  |  S  |  D  |  G   |  X  |------|           |------|  ,<   |   C   |   E  |  I   |   O  |  PgDwn |
     * |--------+------+-----+-----+------+-----|  [{  |           |  ]}  |-------+-------+------+------+------+--------|
     * | LShift |   Z  |  T  |  M  | B/L1 |  V  |      |           |      |/? RAlt| N/L1  |   P  |  .>  |   U  | RShift |
     * `--------+------+-----+-----+------+------------'           `--------------+-------+------+------+------+--------'
     *  | LCtrl | Esc  |S-Ins| LAlt| Bksp |                                       | Space | Left | Down |  Up  | Right |
     *  `---------------------------------'                                       `------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |  F2  | LGui |       |  L2  |  F1  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | C-x  |       |  F3  |      |      |
     *                                 | C-c  |  -_  |------|       |------| LAlt |Enter |
     *                                 |      |      | C-v  |       | Del  |      |RCtrl |
     *                                 `--------------------'       `--------------------'
     *
     * Layer 1:
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 | WH_U |  F11 |   F12  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |  Up  |      |      |      |           |      |      |      |  M_U | WH_D |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      | Left | Down | Right|      |------|           |------|      |  M_L |  M_D |  M_R | BTN1 |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      | TRNS |      |      |           |      |      | TRNS | BTN2 |      | KP_8 |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       | KP_0 |      | KP_4 | KP_2 | KP_6 |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |Teensy|       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |  L0  |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */

    KEYMAP(  // Layer0, Left hand.
        GRV,    1,     2,     3,      4,   5,     6,
        TAB,    Q,     F,     W,      R,   Y,  HOME,
      QUOTE,    A,     S,     D,      G,   X,
     LSHIFT,    Z,     T,     M,    FN3,   V,  LBRC,
      LCTRL,  ESC,  FN10,  LALT,   BSPC,

                                         F2, LGUI,
                                             FN11,
                                  FN8, MINS,  FN4,

            // Right hand.
               7,      8,    9,   0,   P0,   EQL,   BSLS,
             END, SCOLON,    H,   J,    K,     L,   PGUP,
                   COMMA,    C,   E,    I,     O,   PGDN,
            RBRC,   FN7,  FN9,    P,  DOT,     U, RSHIFT,
                           SPC, LEFT, DOWN,   UP,   RGHT,

        FN12,   F1,
          F3,
         DEL, LALT, FN6
    ),

    KEYMAP(  // Layer1, left hand
        TRNS,  F1,  F2,  F3,  F4,  F5,  F6,
        TRNS,TRNS,TRNS,  UP,TRNS,TRNS,TRNS,
        TRNS,TRNS,LEFT,DOWN,RGHT,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,  FN1,
                                            TRNS,
                                TRNS, TRNS, TRNS,
        // right hand
               F7,   F8,   F9,  F10, WH_U, F11,  F12,
             TRNS, TRNS, TRNS, MS_U, WH_D, TRNS, TRNS,
                   TRNS, MS_L, MS_D, MS_R, BTN1, TRNS,
             TRNS, TRNS, TRNS, BTN2, TRNS,   P8, TRNS,
                           P0, TRNS,   P4,   P2,   P6,
        TRNS,TRNS,
        FN0,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer2: steno for plover
        NO, NO,  NO,  NO,  NO,  NO,  NO,
        NO,  1,   2,   3,   4,   5,   NO,
        NO,  Q,   W,   E,   R,   T,
        NO,  A,   S,   D,   F,   G,   NO,
        NO,  NO,  NO,  C,   V,
                                  NO, NO,
                                      NO,
                            BSPC, NO, NO,

                NO, NO,  NO,  NO,   NO,   NO,    NO,
                NO,  6,   7,   8,    9,    0,    NO,
                     Y,   U,   I,    O,    P,  LBRC,
                NO,  H,   J,   K,    L, SCLN,  QUOT,
                          N,   M,   NO,   NO,    NO,
        NO,  NO,
       FN0,
        NO,  NO, NO
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
  CTRLC,
  CTRLV,
  SHIFTINS,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [2] =  ACTION_LAYER_MOMENTARY(1),                   // FN2 -  Momentary L1
    [3] =  ACTION_LAYER_TAP_KEY(1, KC_B),               // FN3 -  Tap=B, Hold=L1
    [4] =  ACTION_MACRO(CTRLV),                         // FN4 -  C-v
    //[5] =  ACTION_MODS_TAP_KEY(MOD_LALT, KC_DOT),       // FN5 -  Tap=dot, Hold=Left-Alt
    [6] =  ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),       // FN6 -  Tap=Enter, Hold=RCtrl
    [7] =  ACTION_MODS_TAP_KEY(MOD_RALT, KC_SLSH),      // FN7 -  Tap=/, Hold=Right-Alt
    [8] =  ACTION_MACRO(CTRLC),                         // FN4 -  C-c
    [9] =  ACTION_LAYER_TAP_KEY(1, KC_N),               // FN9 -  Tap=N, Hold=L1
    [10] = ACTION_MACRO(SHIFTINS),                      // FN10 -  Shift-Ins
    [11] = ACTION_MACRO(CTRLX),                         // FN11 -  C-x
    [12] = ACTION_LAYER_SET(2, ON_BOTH),                // FN12 -  Set L1
    //[13] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_QUOTE),     // FN13
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
    case CTRLV:
      if(!record->event.pressed) {
        unregister_mods(MOD_BIT(KC_LCTL));
      }
      return (record->event.pressed ?
          MACRO( I(15), D(LCTL), T(V), U(LCTL), END ) :
          MACRO_NONE);
    case CTRLC:
      if(!record->event.pressed) {
        unregister_mods(MOD_BIT(KC_LCTL));
      }
      return (record->event.pressed ?
          MACRO( I(15), D(LCTL), T(C), U(LCTL), END ) :
          MACRO_NONE);
    case SHIFTINS:
      if(!record->event.pressed) {
        unregister_mods(MOD_BIT(KC_LSHIFT));
      }
      return (record->event.pressed ?
          MACRO( I(15), D(LSHIFT), T(INSERT), U(LSHIFT), END ) :
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

/*
    // templates to copy from
    KEYMAP(  // LayerN: fully transparent
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      |        |
     *   `----------------------------------'                                       `------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
 */
