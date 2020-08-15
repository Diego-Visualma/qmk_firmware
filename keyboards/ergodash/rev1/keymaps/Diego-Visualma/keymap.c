#include QMK_KEYBOARD_H

#define _COLEMAKMD 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4
#define _NUMPAD 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  NUMPAD,
  COLEMK,
  ENIE,
};

//Tap Dance declarations
typedef struct {
	bool is_press_action;
	uint8_t state;
} tap;

enum {
	SINGLE_TAP = 1,
	SINGLE_HOLD,
	DOUBLE_TAP,
	DOUBLE_HOLD,
	DOUBLE_SINGLE_TAP,
	TRIPLE_TAP,
	TRIPLE_HOLD,
};

enum {
	TD_LOWER,
  TD_RAISE,
	TD_SHCPS,
};

//Tap Dance definitios
uint8_t cur_dance(qk_tap_dance_state_t *state);
void lower_finished(qk_tap_dance_state_t *state, void *user_data);
void lower_reset(qk_tap_dance_state_t *state, void *user_data);
void raise_finished(qk_tap_dance_state_t *state, void *user_data);
void raise_reset(qk_tap_dance_state_t *state, void *user_data);
void shcps_finished(qk_tap_dance_state_t *state, void *user_data);
void shcps_reset(qk_tap_dance_state_t *state, void *user_data);

#define EISU LALT(KC_GRV)
#define SHIFTAB LSFT(KC_TAB)
#define PRETAB LCTL(KC_PGUP)
#define NEXTAB LCTL(KC_PGDN)
#define ALTAB LALT(KC_TAB)
#define OSSTFT OSM(MOD_LSFT)
#define EXPN TD(TD_EXPN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |NUMPAD|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      | Enter|      | Space|      |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+ Space+------+------+------+ Enter+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | AlGr |||||||| Lower|      | Ctrl |      | Ctrl |      | Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,                        KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    NUMPAD, \
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_BSPC,                        KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    TD(TD_SHCPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_ENT ,      KC_SPC ,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_ALGR,        TD(TD_LOWER),   KC_SPC ,KC_LCTL,      KC_RCTL,  KC_ENT , TD(TD_RAISE),            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

    /* Colemak
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |NUMPAD|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   F  |   P  |   B  |   -  |                    |   =  |   J  |   L  |   U  |   Y  |   ;  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   R  |   S  |   T  |   G  |  Del |                    | Bksp |   H  |   N  |   E  |   I  |   O  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   D  |   V  |      | Enter|      | Space|      |   K  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+ Space+------+------+------+ Enter+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | AlGr |||||||| Lower|      | Ctrl |      | Ctrl |      | Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_COLEMAKMD] = LAYOUT( \
    KC_ESC  ,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,                        KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    NUMPAD, \
    KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_MINS,                        KC_EQL , KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_BSLS, \
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_BSPC,                        KC_BSPC, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
    TD(TD_SHCPS), KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,            KC_ENT ,      KC_SPC ,           KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_ALGR,         TD(TD_LOWER),   KC_SPC, KC_LCTL,      KC_RCTL,  KC_ENT , TD(TD_RAISE),            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ESC  |   1  |   2  |   3  |   4  |   5  |  Del |                    |  Del | Left | Down |  Up  | Right| ENIE |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  |      | STOP |      | NEXT |      | ENIE |   M  |   <  |   >  |   -  | Shift|
   * |-------------+------+------+------+------+ Space+------+------+------+ Enter+------+------+------+------+------+------|
   * | Ctrl |  GUI |  ALt | AlGr |||||||| Lower|      | PLAY |      | PREV |      | Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL ,                        KC_DEL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ENIE   , KC_DQT , \
    OSSTFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,            KC_MSTP ,        KC_MNXT ,        ENIE,    KC_M,    KC_LT,   KC_GT,   KC_MINS, KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_ALGR,          TD(TD_LOWER),   KC_SPC, KC_MPLY,        KC_MPRV, KC_ENT, TD(TD_RAISE),            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ESC  |   1  |   2  |   3  |   4  |   5  |  Del |                    |  Del | Left | Down |  Up  | Right| ENIE |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  |      | STOP |      | NEXT |      | ENIE |   M  |   <  |   >  |   -  | Shift|
   * |-------------+------+------+------+------+ Space+------+------+------+ Enter+------+------+------+------+------+------|
   * | Ctrl |  GUI |  ALt | AlGr |||||||| Lower|      | PLAY |      | PREV |      | Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL ,                        KC_DEL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ENIE   , KC_DQT , \
    OSSTFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,            KC_MSTP ,        KC_MNXT ,        ENIE,    KC_M,    KC_LT,   KC_GT,   KC_MINS, KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_ALGR,          TD(TD_LOWER),   KC_SPC, KC_MPLY,        KC_MPRV, KC_ENT, TD(TD_RAISE),            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

    /* Numpad
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |      |      |      |      |      |      |                    | CALC |      |      |      |      |NUMLCK|NUMPAD|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      | Home |PageUp|  Up  |PageDn|  End |      |                    |      |      |   7  |   8  |   9  |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ESC  |ShfTab| Left | Down | Right| Tab  |      |                    |      |   =  |   4  |   5  |   6  |   +  |  -   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      |      |      |      |      |      |   ,  |   1  |   2  |   3  |   *  |  /   |
   * |-------------+------+------+------+------+ Space+------+------+------+ Enter+------+------+------+------+------+------|
   * | Ctrl |  GUI |  ALt |      ||||||||      |      | Ctrl |      | Ctrl |      |      ||||||||   0  |   .x  |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_NUMPAD] = LAYOUT(
    KC_ESC , _______, _______, _______, _______, _______, _______,                        KC_CALC, _______, _______, _______, _______, KC_NLCK,  NUMPAD, \
    _______, KC_HOME, KC_PGUP,   KC_UP, KC_PGDN,  KC_END, _______,                        _______, _______, KC_P7  , KC_P8  , KC_P9  , _______, _______, \
    KC_ESC,  SHIFTAB, KC_LEFT, KC_DOWN, KC_RGHT,  KC_TAB, _______,                        _______, KC_PEQL, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_PMNS, \
    KC_LSFT, _______, _______, _______, _______, _______,         _______,       _______ ,         KC_PCMM, KC_P1  , KC_P2  , KC_P3  , KC_PAST, KC_PSLS, \
    KC_LCTL, KC_LGUI, KC_LALT, _______,          _______, KC_SPC, KC_LCTL,        KC_RCTL, KC_PENT,_______,          KC_P0  , KC_PDOT, _______, _______  \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |RGB ON|  MODE| RMODE|  HUE+|  HUE-| SAT- |  SAT+|                    |      | BL ON|BL STP|  INC |   DEC|  BRTG|      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |  VAL+|                    |      |      |      |      |      |      |GUI ON|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |PRETAB|NEXTAB|ALTAB | SLEEP|  VAL-|                    |      |BRGHT+|      |      |      |      |GUIOFF|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | WBAK | WFWD | WREF |      | POWER|      | LYCLM|      |      |      |BRGHT-|      |      |      |      |      |
   * |-------------+------+------+------+------+      +------+------+------+      +------+------+------+------+-------------|
   * |RESET |      |      |      ||||||||      |      | LYQRT||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD, RGB_SAI,RGB_SAD,                      _______, BL_TOGG, BL_STEP, BL_INC, BL_DEC  , BL_BRTG, _______, \
    _______, _______, _______, _______, _______, _______,RGB_VAI,                       _______, _______, _______, _______, _______, _______, GUI_ON, \
    _______, _______, PRETAB , NEXTAB , ALTAB  , KC_SLEP,RGB_VAD,                       _______, KC_BRIU, _______, _______, _______, _______, GUI_OFF, \
    _______, KC_WBAK, KC_WFWD, KC_WREF, _______, KC_PWR ,         COLEMK,        _______,         KC_BRID, _______, _______, _______, _______, _______, \
    RESET  , _______, _______, _______,          _______,_______, QWERTY,        _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
	      layer_move(_QWERTY);
        set_single_persistent_default_layer(_QWERTY);
      }
      return 
      false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
          layer_invert(_NUMPAD);
	}
    break;
    case ENIE:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          tap_code(KC_GRAVE);
          tap_code(KC_N);
        } else {
          register_code(KC_LSHIFT);
          tap_code(KC_GRAVE);
          unregister_code(KC_LSHIFT);
          tap_code(KC_N);
        }
      }  	
    break;
    case COLEMK:
      if (record->event.pressed) {
	layer_move(_COLEMAKMD);      
        set_single_persistent_default_layer(_COLEMAKMD);
      } 
    break;
  }
  return true;
}

// Change lights based on layer state via callback
layer_state_t layer_state_set_user(layer_state_t state){
	switch(biton32(state)){
		case _QWERTY:
			rgblight_mode(RGBLIGHT_MODE_BREATHING);
			rgblight_sethsv_noeeprom(HSV_ORANGE);
			break;
		case _COLEMAKMD:
			rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
			rgblight_sethsv(100,230,110);
			break;
		case _NUMPAD:
			rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
			rgblight_sethsv_noeeprom(HSV_GOLD);
			break;
		case _LOWER:
			//rgblight_mode();
			break;
		case _RAISE:
			//rgblight_mode();
			break;
		case _ADJUST:
			rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
			rgblight_sethsv_noeeprom(HSV_RED);
			break;
		default:
			rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
			rgblight_sethsv_noeeprom(HSV_CYAN);
			break;
	}
	return state;
}

//multi tap dance
uint8_t cur_dance(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || state->pressed) return SINGLE_HOLD;
		else return SINGLE_TAP;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	if (state->count == 3) {
		if (state->interrupted || !state->pressed) return TRIPLE_TAP;
		else return TRIPLE_HOLD;
	} else return 8;
}
//create instances of tap for each key
static tap lr_tap_state = {
	.is_press_action = true,
	.state = 0
};
static tap ra_tap_state = {
	.is_press_action = true,
	.state = 0
};
static tap sh_tap_state = {
	.is_press_action = true,
	.state = 0
};

void lower_finished(qk_tap_dance_state_t *state, void *user_data) {
	lr_tap_state.state = cur_dance(state);
	switch (lr_tap_state.state){
		case SINGLE_TAP: register_code(KC_LBRC); break;
		case SINGLE_HOLD: 
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
    break;
		case DOUBLE_TAP: break;
		case DOUBLE_HOLD:
        layer_on(_QWERTY);
    break;
		case DOUBLE_SINGLE_TAP: break;
	}
}
void lower_reset(qk_tap_dance_state_t *state, void *user_data) {
	switch (lr_tap_state.state){
		case SINGLE_TAP: unregister_code(KC_LBRC); break;
		case SINGLE_HOLD: 
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
    break;
		case DOUBLE_TAP: break;
		case DOUBLE_HOLD: 
        layer_off(_QWERTY);
    break;
		case DOUBLE_SINGLE_TAP: break;
	}
  lr_tap_state.state = 0;
}

void raise_finished(qk_tap_dance_state_t *state, void *user_data) {
	ra_tap_state.state = cur_dance(state);
	switch (ra_tap_state.state){
		case SINGLE_TAP: register_code(KC_RBRC); break;
		case SINGLE_HOLD: 
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
    break;
		case DOUBLE_TAP: break;
		case DOUBLE_HOLD:
        layer_on(_QWERTY);
    break;
		case DOUBLE_SINGLE_TAP: break;
	}
}
void raise_reset(qk_tap_dance_state_t *state, void *user_data) {
	switch (ra_tap_state.state){
		case SINGLE_TAP: unregister_code(KC_RBRC); break;
		case SINGLE_HOLD: 
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
    break;
		case DOUBLE_TAP: break;
		case DOUBLE_HOLD: 
        layer_off(_QWERTY);
    break;
		case DOUBLE_SINGLE_TAP: break;
	}
  ra_tap_state.state = 0;
}

void shcps_finished(qk_tap_dance_state_t *state, void *user_data) {
	sh_tap_state.state = cur_dance(state);
	switch (sh_tap_state.state){
		case SINGLE_TAP: register_code(KC_LSFT); break;
		case SINGLE_HOLD: register_code(KC_LSFT); break;
		case DOUBLE_TAP: register_code(KC_CAPSLOCK); break;
		case DOUBLE_HOLD: register_code(KC_LSFT); break;
		case DOUBLE_SINGLE_TAP: break;
	}
}
void shcps_reset(qk_tap_dance_state_t *state, void *user_data) {
	switch (sh_tap_state.state){
		case SINGLE_TAP: unregister_code(KC_LSFT); break;
		case SINGLE_HOLD: unregister_code(KC_LSFT); break;
		case DOUBLE_TAP: unregister_code16(KC_CAPSLOCK); break;
		case DOUBLE_HOLD:unregister_code(KC_LSFT); break;
		case DOUBLE_SINGLE_TAP: break;
	}
  sh_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_LOWER] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, lower_finished, lower_reset, 215),
  [TD_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, raise_finished, raise_reset, 215),
	[TD_SHCPS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, shcps_finished, shcps_reset, 215),
};
