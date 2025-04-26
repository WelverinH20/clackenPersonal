#pragma once

/* Serial communication */
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN D3  // Example: adjust for real TX pin (Right side)
#define SERIAL_USART_RX_PIN D2  // Example: adjust for real RX pin (Left side)

/* Defines handedness EEPROM */
#define EE_HANDS

#define ANALOG_JOYSTICK_X_AXIS_PIN A3
#define ANALOG_JOYSTICK_Y_AXIS_PIN A2

#define MATRIX_COL_PINS_RIGHT { B4, B5, B6, B2, B3 }  // Example columns
#define MATRIX_ROW_PINS_RIGHT { D0, D1, D4, C6 }      // Example rows

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

