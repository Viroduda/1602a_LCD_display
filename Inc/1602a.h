// MACROS //
#define PIN_RS 10 // RS pin
#define PIN_RW 9 // RW pin
#define PIN_E 8 // E pin
#define D0 0 // D0 pin
#define D1 1 // D1 pin
#define D2 11 // D2 pin
#define D3 12 // D2 pin
#define D4 4 // D4 pin
#define D5 5 // D5 pin
#define D6 6 // D6 pin
#define D7 7 // D7 pin

#define CLEAR 0x01
#define HOME 0x02
//#define

// INCLUDES //
#include "stdint.h"
#include "string.h"
#include "../../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal.h"

// FUNCTIONS //
void LCD_Init(void);
void setPosition(uint8_t row, uint8_t column);
void prepareMessage(void);
void sendMessage(void);
void writeNumber(uint8_t number);
void writeCharacter (char character);
void writeWord (char word[]);
void sendCommand(char command);
