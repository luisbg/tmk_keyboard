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
     * ,----------------------------------------------------.           ,------------------------------------------------------.
     * |  `~    |   1  |   2  |   3  |    4   |   5  |   6  |           |   7  |   8   |    9   |   0  |   -_  |  =+  |   \|   |
     * |--------+------+------+------+--------+-------------|           |------+-------+--------+------+-------+------+--------|
     * |  Tab   |   Q  |   F  |   W  |    R   |   Y  | Home |           | End  |  '"   |    H   |   J  |   K   |   L  |  PgUp  |
     * |--------+------+------+------+--------+------|      |           |      |-------+--------+------+-------+------+--------|
     * |  Tab   |   A  |   S  |   D  |    G   |   X  |------|           |------|  ,<   |    C   |   E  |   I   |   O  |  PgDwn |
     * |--------+------+------+------+--------+------|  Esc |           |  ;:  |-------+--------+------+-------+------+--------|
     * | LShift |   Z  |   T  |   M  |   B/L1 |   V  |      |           |      |.>/RAlt|  N/L1  |   P  |   L   |   U  | RShift |
     * `--------+------+------+------+--------+-------------'           `--------------+--------+------+-------+------+--------'
     *   |LCtrl | LAlt | C-v  |  C-c |  Bksp  |                                        |/? RCtrl| Left |  Down |  Up  | Right |
     *   `------------------------------------'                                        `--------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |  [{  |  ]}  |       |  L1  | Del  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |  F2  |       |  F3  |      |      |
     *                                 |Space | LAlt |------|       |------| Space| Enter|
     *                                 |      |      | LGui |       |  F1  |      |      |
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
     * |        |      |      |      | TRNS |      |      |           |      |      | TRNS | BTN2 | KP_8 |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       | KP_0 | KP_4 | KP_2 | KP_6 |       |
     *   `----------------------------------'                                       `-----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |Teensy|       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |  L0  |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */

    KEYMAP(  // Layer0, Left hand.
        GRV,      1,     2,      3,      4,     5,     6,
        TAB,      Q,     F,      W,      R,     Y,  HOME,
        TAB,      A,     S,      D,      G,     X,
        LSHIFT,   Z,     T,      M,    FN3,     V,   ESC,
        LCTRL, LALT,   FN8,    FN4,   BSPC,

                                      LBRC, RBRC,
                                              F2,
                                 SPC, LALT, LGUI,

            // Right hand.
               7,    8,    9,      0,  MINS,   EQL,    BSLS,
             END, QUOT,    H,      J,     K,     L,    PGUP,
                 COMMA,    C,      E,     I,     O,    PGDN,
          SCOLON,  FN7,  FN9,      P,     L,     U,  RSHIFT,
                         FN6,   LEFT,  DOWN,    UP,    RGHT,

        FN12, DEL,
          F3,
          F1, SPC, ENT
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
             TRNS, TRNS, TRNS, BTN2,   P8, TRNS, TRNS,
                            P0,  P4,   P2,   P6, TRNS,
        TRNS,TRNS,
        FN0,
        TRNS,TRNS,TRNS
    ),
};

/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
    CUSTOM_KEY,
    L_CTRL_ALT_ENT,
    R_CTRL_ALT_ENT,
};

enum macro_id {
  CTRLC,
  CTRLV,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [2] =  ACTION_LAYER_MOMENTARY(1),                     // FN2 -  Momentary L1
    [3] =  ACTION_LAYER_TAP_KEY(1, KC_B),                 // FN3 -  Tap=B, Hold=L1
    [4] =  ACTION_MACRO(CTRLC),                           // FN4 -  C-c
    //[5] =  ACTION_MODS_TAP_KEY(MOD_LCTL, KC_SPC),         // FN5 -  Tap=G, Hold=Left-SHIFT
    [6] =  ACTION_MODS_TAP_KEY(MOD_RCTL, KC_SLSH),        // FN6 -  Tap=Slash, Hold=RCtrl

    [7] =  ACTION_MODS_TAP_KEY(MOD_RALT, KC_DOT),         // FN7 -  Tap=., Hold=Right-Alt
    [8] =  ACTION_MACRO(CTRLV),                           // FN8 -  C-v
    [9] =  ACTION_LAYER_TAP_KEY(1, KC_N),                 // FN9 -  Tap=N, Hold=L1
    //[10] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_PGDN),        // FN10 - Tap=PGDOWN, Hold=Left-ALT
    //[11] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_I),           // FN11 - Tap=I, Hold=Right-GUI
    [12] = ACTION_LAYER_SET(1, ON_BOTH),                  // FN12 -  Set L1
};

static const uint16_t PROGMEM fn_actions_1[] = {
    [0] = ACTION_LAYER_SET(0, ON_BOTH),                   // FN0  - Set Layer0
    [1] = ACTION_FUNCTION(TEENSY_KEY),                    // FN1  - Teensy key
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

    if (id == L_CTRL_ALT_ENT || id == R_CTRL_ALT_ENT) {
        if (record->tap.count == 0 || record->tap.interrupted) {
            uint8_t weak_mods;
            uint8_t layer;

            if (id == L_CTRL_ALT_ENT) {
                weak_mods = MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT);
                layer     = 5;
            } else {
                weak_mods = MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT);
                layer     = 6;
            }

            if (record->event.pressed) {
                layer_on(layer);
                add_weak_mods(weak_mods);
            } else {
                del_weak_mods(weak_mods);
                layer_off(layer);
            }
        } else {
            if (record->event.pressed) {
                add_key(KC_ENT);
                send_keyboard_report();
            } else {
                del_key(KC_ENT);
                send_keyboard_report();
            }
        }
    }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch (id) {
          case CTRLC:
            return (record->event.pressed ?
                MACRO( D(LCTL), D(C), U(C), U(LCTL), END ) :
                MACRO_NONE );
          case CTRLV:
            return (record->event.pressed ?
                MACRO( D(LCTL), D(V), U(V), U(LCTL), END ) :
                MACRO_NONE );
        }
    }
    return MACRO_NONE;
}

#define FN_ACTIONS_SIZE     (sizeof(fn_actions)   / sizeof(fn_actions[0]))
#define FN_ACTIONS_1_SIZE   (sizeof(fn_actions_1) / sizeof(fn_actions_1[0]))

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
