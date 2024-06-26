/*
 * LCD.h
 *
 *  Created on: Mar 29, 2024
 *      Author: Dell
 */

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"
#include "GPIO.h"

/*************** LCD PINS *****************/
/* Control pins */
#define LCD_RS 0
#define LCD_RW 1
#define LCD_E  2
/* Data pins */
#define LCD_DB0 3
#define LCD_DB1 4
#define LCD_DB2 5
#define LCD_DB3 6
#define LCD_DB4 7
#define LCD_DB5 8
#define LCD_DB6 9
#define LCD_DB7 10

#define LCD_PINS_NUM 11

/* Callback Function Pointer for LCD */
typedef void (*LCD_CBF)(void);

typedef struct
{
    void* PORT;
    u32 PIN;
} LCD_PinCgf_t;

/********* LCD error types ********/
typedef enum
{
    LCD_enuOk,            /* Operation successful */
    LCD_enuNullPtr ,      /* Null Pointer */
    LCD_enuWrongPosition, /* Wrong x,y position at DDRAM */
    LCD_WrongBlockNum     /* Wrong block number at CGRAM */
} LCD_enumError_t;

/**
 * @brief  : Function to initialize the LCD Pins
 * @param  : none
 * @return : none
 */
void LCD_InitPins(void);

/**
 * @brief  : Function to request a LCD initialization process
 * @param  : cbf - Pointer to the callback function for asynchronous initialization
 * @return : None
 */
void LCD_init_asynch(LCD_CBF cbf );

/**
 * @brief  : Saves user request for writing a string on LCD
 * @param  : string - Pointer to the string to be written
 * @param  : cbf - Pointer to the callback function for asynchronous operation
 * @return : LCD_enumError_t - Error code indicating the status of the operation
 */
LCD_enumError_t LCD_enuWriteString_asynch(const char* string, LCD_CBF cbf);

/**
 * @brief  : Saves user request for writing a number on LCD
 * @param  : Copy_u8Number - The number to be written
 * @return : None
 */
void LCD_enuWriteNumber_asynch(u16 Copy_u8Number);

/**
 * @brief  : Saves user request for LCD clear
 * @param  : None
 * @return : None
 */
void LCD_ClearScreen_async(void);

/**
 * @brief  : Saves user request for setting the cursor position on the LCD
 * @param  : Copy_u8X - The X coordinate of the position (0 for first line, 1 for second line)
 * @param  : Copy_u8Y - The Y coordinate of the position (0 to 15)
 * @param  : cbf - Pointer to the callback function for asynchronous operation
 * @return : LCD_enumError_t - Error code indicating the status of the operation
 */
LCD_enumError_t LCD_GotoPos_XY_async(u8 Copy_u8X, u8 Copy_u8Y, LCD_CBF cbf);

#endif /* LCD_H_ */
