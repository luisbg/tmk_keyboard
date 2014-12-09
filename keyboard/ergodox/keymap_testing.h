/*
 * Layout to test if all keys work
 *
 * NOTES:
 * ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT)
 * Works as a modifier key while holding, but registers a key on tap(press and release quickly)
 * From the docs it seems like the destination layer button must be the same or transparent.
 *
 * ACTION_LAYER_MOMENTARY(layernumber)
 * it activates when key is pressed and deactivate when released
 * From the docs it seems like the destination layer button must be the same or transparent.
 *
 * ACTION_LAYER_TAP_KEY(layer, key)
 * Turns on layer momentary while holding, but registers key on tap(press and release quickly).
 * From the docs it seems like the destination layer button must be the same or transparent.
 *
 */
static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0:
     * ,-----------------------------------------------.           ,----------------------------------------------------.
     * |  0     |   1  |  2  |  3  |  4   |  5  |  6   |           |  0   |   1   |   2   |   3  |  4   |   5  |    6   |
     * |--------+------+-----+-----+------+------------|           |------+-------+-------+------+------+------+--------|
     * |  1     |   2  |  3  |  4  |  5   |  6  |  7   |           |  1   |   2   |   3   |   4  |  5   |   6  |    7   |
     * |--------+------+-----+-----+------+-----|      |           |      |-------+-------+------+------+------+--------|
     * |  2     |   3  |  4  |  5  |  6   |  7  |------|           |------|   3   |   4   |   5  |  6   |   7  |    8   |
     * |--------+------+-----+-----+------+-----|  8   |           |  2   |-------+-------+------+------+------+--------|
     * |  3     |   4  |  5  |  6  |  7   |  8  |      |           |      |   4   |   5   |   6  |  7   |   8  |    9   |
     * `--------+------+-----+-----+------+------------'           `--------------+-------+------+------+------+--------'
     *  | 4     |   5  |  6  |  7  |  8   |                                       |   6   |   7  |  8   |   9  |    0  |
     *  `---------------------------------'                                       `------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |   1  |  3   |       |  0   |  3   |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |  4   |       |  1   |      |      |
     *                                 |  0   |   2  |------|       |------|  A   |  B   |
     *                                 |      |      |  5   |       |  2   |      |      |
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
     */

    KEYMAP(  // Layer0, Left hand.
          0,    1,     2,     3,      4,    5,     6,
          1,    2,     3,     4,      5,    6,     7,
          2,    3,     4,     5,      6,    7,
          3,    4,     5,     6,      7,    8,     8,
          4,    5,     6,     7,      8,

                                               1,  3,
                                                   4,
                                           0,  2,  5,

            // Right hand.
                   0,    1,    2,    3,    4,    5,    6,
                   1,    2,    3,    4,    5,    6,    7,
                         3,    4,    5,    6,    7,    8,
                   2,    4,    5,    6,    7,    8,    9,
                               6,    7,    8,    9,    0,

          0,  1,
          1,
          2,  FN1,  FN2
    ),

    KEYMAP(  // Layer1, left hand
          L,    L,     L,     L,      L,    L,     L,
          L,    L,     L,     L,      L,    L,     L,
          L,    L,     L,     L,      L,    L,
          L,    L,     L,     L,      L,    L,     L,
          L,    L,     L,     L,      L,

                                               L,  L,
                                                   L,
                                           L,  L,  L,

            // Right hand.
                   L,    L,    L,    L,    L,    L,    L,
                   L,    L,    L,    L,    L,    L,    L,
                         L,    L,    L,    L,    L,    L,
                   L,    L,    L,    L,    L,    L,    L,
                               L,    L,    L,    L,    L,

          L,  L,
          L,
          L,  TRNS,  TRNS
    ),
};

/* id for user defined functions */
enum function_id {
  TEENSY_KEY,       // UNUSED
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
  [0] =  ACTION_FUNCTION(TEENSY_KEY),               // FN0  = Teensy key - UNUSED
  [1] =  ACTION_LAYER_TAP_KEY(1, KC_A),             // FN1  = momentary Layer1 on A key
  [2] =  ACTION_MODS_TAP_KEY(MOD_LSFT, KC_B),       // FN2  = LShift with tap B key
};

static const uint16_t PROGMEM fn_actions_1[] = {
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  print("action_function called\n");
  print("id  = "); phex(id); print("\n");
  print("opt = "); phex(opt); print("\n");

  if (id == TEENSY_KEY) {
    clear_keyboard();
    print("\n\nJump to bootloader... ");
    _delay_ms(50);
    bootloader_jump(); // should not return
    print("not supported.\n");
  }
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
