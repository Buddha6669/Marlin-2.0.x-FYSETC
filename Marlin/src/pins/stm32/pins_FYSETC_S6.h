/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#ifndef STM32F4
  #error "Oops! Select an STM32F4 board in 'Tools > Board.'"
#elif HOTENDS > 3 || E_STEPPERS > 3
  #error "RUMBA32 supports up to 3 hotends / E-steppers."
#endif

#define RUMBA32_V1_0
//#define BOARD_NAME           "FYSETC S6"
#define DEFAULT_MACHINE_NAME BOARD_NAME

//#define I2C_EEPROM

//
// Limit Switches
//
#define X_MIN_PIN          PB15 // D31
//#define X_MAX_PIN          PB13 // D29
#define Y_MIN_PIN          PD9  // D57
//#define Y_MAX_PIN          PD10 // D58
#define Z_MIN_PIN          PB12 // D28
#define Z_MAX_PIN          PD8  // D56

//
// Servos
//
#define SERVO0_PIN         PB13 // D29 // share with X_MAX_PIN

//
// Steppers
//
#define X_STEP_PIN         PC14 // D46
#define X_DIR_PIN          PC15 // D47
#define X_ENABLE_PIN       PA11 // D11
#define X_CS_PIN           PA0  // D0

#define Y_STEP_PIN         PE4  // D68
#define Y_DIR_PIN          PE5  // D69
#define Y_ENABLE_PIN       PD1  // D49
#define Y_CS_PIN           PB14 // D30

#define Z_STEP_PIN         PD2  // D50
#define Z_DIR_PIN          PC12 // D44
#define Z_ENABLE_PIN       PD3  // D51
#define Z_CS_PIN           PD0  // D48

#define E0_STEP_PIN        PD5  // D53
#define E0_DIR_PIN         PD4  // D52
#define E0_ENABLE_PIN      PD6  // D54
#define E0_CS_PIN          PC13 // D45

#define E1_STEP_PIN        PB6  // D22
#define E1_DIR_PIN         PB5  // D21
#define E1_ENABLE_PIN      PB7  // D23
#define E1_CS_PIN          PD7  // D55

#define E2_STEP_PIN        PE2  // D66
#define E2_DIR_PIN         PE1  // D65
#define E2_ENABLE_PIN      PE3  // D67
#define E2_CS_PIN          PD12 // D60

#if HAS_TMC220x
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  Serial
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL  Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  //#define Z_HARDWARE_SERIAL  Serial1
  //#define Z2_HARDWARE_SERIAL Serial1
  //#define E0_HARDWARE_SERIAL Serial1
  //#define E1_HARDWARE_SERIAL Serial1
  //#define E2_HARDWARE_SERIAL Serial1
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1

  //
  // Software serial
  //
  #define X_SERIAL_TX_PIN  PC4  // D36
  #define X_SERIAL_RX_PIN  PE13 // D77

  #define Y_SERIAL_TX_PIN  PC5  // D37
  #define Y_SERIAL_RX_PIN  PE11 // D75

  #define Z_SERIAL_TX_PIN  PB10 // D26
  #define Z_SERIAL_RX_PIN  PE15 // D79

  #define E0_SERIAL_TX_PIN PD13 // D61
  #define E0_SERIAL_RX_PIN PE6  // D70

  #define E1_SERIAL_TX_PIN PD11 // D59
  #define E1_SERIAL_RX_PIN PE0  // D64

  #define E2_SERIAL_TX_PIN PA12 // D12
  #define E2_SERIAL_RX_PIN PE14 // D78
#endif

//
// Temperature Sensors
//
#define TEMP_0_PIN         PC0  // D32
#define TEMP_1_PIN         PC1  // D33
#define TEMP_2_PIN         PC2  // D34
#define TEMP_BED_PIN       PC3  // D35

//
// Heaters / Fans
//
#define HEATER_0_PIN       PC6  // D38
#define HEATER_1_PIN       PC7  // D39
#define HEATER_2_PIN       PC8  // D40
#define HEATER_BED_PIN     PA1  // D1

#define FAN_PIN            PA8  // D8 
#define FAN1_PIN           PC9  // D41
#define FAN2_PIN           PD14 // D62

//
// I2C
//
#define SCK_PIN            PA5
#define MISO_PIN           PA6
#define MOSI_PIN           PA7

//
// Misc. Functions
//
//#define LED_PIN            PB14
//#define BTN_PIN            PC10
//#define PS_ON_PIN          PE11
//#define KILL_PIN           PC5

#define SDSS               PA4 // D4

//
// LCD / Controller
//

#define BEEPER_PIN         PE8 // D72
#define SD_DETECT_PIN      PB0 // D16

#if ENABLED(FYSETC_MINI_12864)
  //
  // See https://wiki.fysetc.com/Mini12864_Panel/?fbclid=IwAR1FyjuNdVOOy9_xzky3qqo_WeM5h-4gpRnnWhQr_O1Ef3h0AFnFXmCehK8
  //
  #define DOGLCD_A0        PC10 // D42
  #define DOGLCD_CS        PC11 // D43

  //#define LCD_BACKLIGHT_PIN -1
  //#define KILL_PIN          -1

  #define LCD_RESET_PIN    PE12 // Must be high or open for LCD to operate normally.
                                // Seems to work best if left open.

  #if EITHER(FYSETC_MINI_12864_1_2, FYSETC_MINI_12864_2_0)
    #ifndef RGB_LED_R_PIN
      #define RGB_LED_R_PIN PA15 // D15
    #endif
    #ifndef RGB_LED_G_PIN
      #define RGB_LED_G_PIN PB3  // D19
    #endif
    #ifndef RGB_LED_B_PIN
      #define RGB_LED_B_PIN PB4  // D20
    #endif
  #elif ENABLED(FYSETC_MINI_12864_2_1)
    #define NEOPIXEL_PIN    PA15 // D15
  #endif

#elif HAS_GRAPHICAL_LCD

  #define LCD_PINS_RS      PC10 // D42
  #define LCD_PINS_ENABLE  PC11 // D43
  #define LCD_PINS_D4      PE12 // D76
  #define LCD_PINS_D5      PA15 // D15
  #define LCD_PINS_D6      PB3  // D19
  #define LCD_PINS_D7      PB4  // D20

  #if ENABLED(MKS_MINI_12864)
    #define DOGLCD_CS      PA15 // D15
    #define DOGLCD_A0      PB3  // D19
  #endif

#endif

#if ENABLED(NEWPANEL)
  #define BTN_EN1          PB1  // D17
  #define BTN_EN2          PB2  // D18
  #define BTN_ENC          PE7  // D71
#endif

#ifndef RGB_LED_R_PIN
  #define RGB_LED_R_PIN    PD15 // D63
#endif
#ifndef RGB_LED_G_PIN
  #define RGB_LED_G_PIN    PE9  // D73
#endif
#ifndef RGB_LED_B_PIN
  #define RGB_LED_B_PIN    PE10 // D74
#endif
#ifndef RGB_LED_W_PIN
  #define RGB_LED_W_PIN    -1
#endif

