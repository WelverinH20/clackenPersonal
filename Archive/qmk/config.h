// Copyright 2024 Carter Pollan (@Carter Pollan)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 * These options are also useful to firmware size reduction.
 */

 /* Serial communication */
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP6 // Left: GP3 Right: GP6
#define SERIAL_USART_RX_PIN GP29 // Left: GP4 Right: GP29

/* Defines handedness EEPROM */
#define EE_HANDS
/*
add these flags when flashing to set the handedness

-bl uf2-split-left
-bl uf2-split-right*/

#define MATRIX_COL_PINS_RIGHT { GP4, GP3, GP28, GP27, GP26 }
#define MATRIX_ROW_PINS_RIGHT { GP2, GP1, GP0, GP7 } //{ GP2, GP1, GP0, GP7 }

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
