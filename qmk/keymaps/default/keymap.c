#include QMK_KEYBOARD_H

#define JOY_X_PIN A0 // Define X axis potentiometer pin
#define JOY_Y_PIN A1 // Define Y axis potentiometer pin

// Function to initialize the joystick
void matrix_init_user(void) {
    analogReference(DEFAULT); // Use the default analog reference voltage (5V)
    // Any other initialization code can go here
}

// Function to read joystick values
/*uint16_t read_joystick(void) {
    uint16_t x_value = analogRead(JOY_X_PIN); // Read X axis
    uint16_t y_value = analogRead(JOY_Y_PIN); // Read Y axis

    // Send the joystick data to the Master side
    send_joystick_data(x_value, y_value);

    return x_value;  // Return X value (you can modify this as needed)
}

// Function to send joystick data to Master via serial
void send_joystick_data(uint16_t x_value, uint16_t y_value) {
    // Send the X and Y joystick values as two bytes each (high byte and low byte)
    Serial.write((x_value >> 8) & 0xFF); // Send high byte of X value
    Serial.write(x_value & 0xFF);        // Send low byte of X value
    Serial.write((y_value >> 8) & 0xFF); // Send high byte of Y value
    Serial.write(y_value & 0xFF);        // Send low byte of Y value
}*/

// This function is called whenever a key is pressed or released
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // When any key is pressed, read joystick input and send it
        uint16_t joystick_value = read_joystick();
        // You can also add additional functionality here if needed
    }

    return true;
}

// Optional: Use this to process serial data from the Master side
void matrix_scan_user(void) {
    // Handle any custom actions based on the joystick data or serial input from the Master
    if (Serial.available() > 0) {
        // Read the joystick data from the Master side
        uint8_t x_high = Serial.read();
        uint8_t x_low = Serial.read();
        uint8_t y_high = Serial.read();
        uint8_t y_low = Serial.read();

        uint16_t x_value = (x_high << 8) | x_low;
        uint16_t y_value = (y_high << 8) | y_low;

        // Process the joystick data (e.g., map it to key presses, mouse movements, etc.)
        // Here, we just print the values for now
        // For example, you could call a function to move the mouse or take action
    }
}

// Define your keymap here
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_clack(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,                               KC_5,    KC_6,    KC_7,    KC_8,    KC_9,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F, KC_MS_L, KC_MS_R,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
                                   KC_LGUI, KC_SPC, KC_BSPC,          KC_SPC,   KC_ENT,  KC_RALT
    )
};
