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
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  `~    |   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |   0  |  -_  |  =+  |   \|   |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   F  |   W  |   R  |   Y  | Home |           | End  |  '"  |   H  |   J  |   K  |   L  |  RGui  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |   A  |   S  |   D  | G/L1 |   T  |------|           |------|   P  |   C  |   E  |   O  |   I  | RShift |
     * |--------+------+------+------+------+------|      |           |  ;:  |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   M  |   B  |V/Shft|      |           |      |   U  |   N  |  ,<  |  Up  |  .>  | RCtrl  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |LCtrl | LGui | ~L1  | LCtrl| LAlt |                                       |  /?  | Left | Down | Right|  Esc   |
     *   `----------------------------------'                                       `------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |  [{  |  ]}  |       | +L1  | Del  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 | BkSp |Space |------|       |------| Space| Enter|
     *                                 |      |      | PgUp |       |PgDown|      |      |
     *                                 `--------------------'       `--------------------'
     *
     * Layer 1:
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 | WH_U |  F11 |  F12   |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      | BTN1 |  M_U | WH_D |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------|      | M_L  |  M_D | M_R  |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      |      | KP_8 |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      | TRNS |      |      |                                       | KP_0 | KP_4 | KP_2 | KB_6 |        |
     *   `----------------------------------'                                       `------------------------------------'
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
        NO,       A,     S,      D,    FN3,     T,
        LSHIFT,   Z,     X,      M,      B,   FN4,  NO,
        LCTRL, LGUI,  FN2, LCTRL,  LALT,
                                      LBRC, RBRC,
                                              NO,
                                 BSPC, SPC, PGUP,
        // Right hand.
               7,    8,   9,   0,     MINS,   EQL,    BSLS,
             END, QUOT,   H,   J,        K,     L,    RGUI,
                     P,   C,   E,        O,     I,  RSHIFT,
          SCOLON,    U,   N,   COMMA,   UP,   DOT,   RCTRL,
                        SLSH,   LEFT,  DOWN,  RGHT,    ESC,
        FN1,DEL,
        NO,
        PGDN, SPC, ENT
    ),

    KEYMAP(  // Layer1, left hand
        TRNS,  F1,  F2,  F3,  F4,  F5,  F6,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS, FN10,
                                            TRNS,
                                TRNS, TRNS, TRNS,
        // right hand
               F7,   F8,   F9,  F10, WH_U,  F11,  F12,
             TRNS, TRNS, BTN1, MS_U, WH_D, TRNS, TRNS,
                   TRNS, MS_L, MS_D, MS_R, TRNS, TRNS,
             TRNS, TRNS, TRNS, TRNS, P8,   TRNS, TRNS,
                            P0, P4,  P2,     P6, TRNS,
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

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_SET(1, ON_BOTH),                   // FN1 - Set Layer1

    [2] = ACTION_LAYER_MOMENTARY(1),                      // FN2 - Momentary Layer1

    [3] = ACTION_LAYER_TAP_KEY(1, KC_G),                  // FN3 - Momentary Layer1 on G key

    [4] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_V),            // FN4 - Tap=V, Hold=Left-Shift

    //[8] = ACTION_FUNCTION_TAP(L_CTRL_ALT_ENT),          // FN21 - momentary Layer5+CTRL+ALT on Enter, to use with F* keys on top row
};

static const uint16_t PROGMEM fn_actions_1[] = {
    [0] = ACTION_LAYER_SET(0, ON_BOTH),                   // FN0 - Set Layer0
    [10] = ACTION_FUNCTION(TEENSY_KEY),                   // FN10 - Teensy key
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
