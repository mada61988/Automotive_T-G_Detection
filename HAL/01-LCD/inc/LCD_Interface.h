/**********************************************************************************************************************************/
/******************************************   DATE:           12.5.2022           *************************************************/
/******************************************   NAME:          MohamedAyman          *************************************************/
/******************************************  LAYER:              HAL              *************************************************/
/******************************************    SWC:             LCD                *************************************************/
/*****************************************     VER:               01               *************************************************/
/*****************************************    FILE:         lcd_interface.h           ************************************************/



#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_


/**********************************************
 * LCD Interfacing
 **********************************************/

#define Function_Set 0x38
#define Display_On 0x0C
#define Clear 0x01
#define Entry_Mode 0x06

/**********************************************/

/**********************************************
 * LCD Raws and Columns
 **********************************************/
#define RAW0        0
#define RAW1        1

#define COLUMN0     0
#define COLUMN1     1
#define COLUMN2     2
#define COLUMN3     3
#define COLUMN4     4
#define COLUMN5     5
#define COLUMN6     6
#define COLUMN7     7
#define COLUMN8     8
#define COLUMN9     9
#define COLUMN10     10
#define COLUMN11     11
#define COLUMN12     12
#define COLUMN13     13
#define COLUMN14     14
#define COLUMN15     15
#define COLUMN16     16

/**********************************************
 * LCD-FUNCTION-PROTOTYPES
 **********************************************/
void LCD_INIT();
void LCD_SEND_CMD(char);
void LCD_DISP_CHAR(char);
void LCD_DISP_STR(char[]);
void LCD_SEND_XY(uint8 row,uint8 pos,uint8 *str);
/**********************************************/

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
