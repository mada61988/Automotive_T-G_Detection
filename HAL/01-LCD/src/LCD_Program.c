/**********************************************************************************************************************************/
/******************************************   DATE:           12.5.2022           *************************************************/
/******************************************   NAME:          MohamedAyman          *************************************************/
/******************************************  LAYER:              HAL              *************************************************/
/******************************************    SWC:             LCD                *************************************************/
/*****************************************     VER:               01               *************************************************/
/*****************************************    FILE:         lcd_program.c           ************************************************/

#include <avr/delay.h>
#include "Platform_Types.h"
#include "BIT_MATH.h"
#include "dio_register.h"
#include "dio_interface.h"
#include "LCD_Register.h"
#include "LCD_Interface.h"





void LCD_INIT(){

	// INIT LCD IN 4BIT MODE

	//1- WAIT FOR MORE THAN 30ms
	_delay_ms(35);


	//2- Commands
	LCD_SEND_CMD(0x33);
	_delay_ms(10);
	LCD_SEND_CMD(0x32);	// Send for 4 bit initialization of LCD
	_delay_ms(10);
	LCD_SEND_CMD(0x28);	// 2 line, 5*7 matrix in 4-bit mode
	_delay_ms(10);
	LCD_SEND_CMD(0x0C);	/// Display on cursor off
	_delay_ms(10);
	LCD_SEND_CMD(0x06);	// Increment cursor (shift cursor to right)
	_delay_ms(10);
	LCD_SEND_CMD(0x81);
	_delay_ms(10);
	LCD_SEND_CMD(0x01);
	_delay_ms(10);

}
void LCD_SEND_CMD(char cmd){

	/*
	 * SENDING UPPER NIBBLE
	 * */
	LCD_PORT = (LCD_PORT & 0x0F) | (cmd & 0xF0);
	// RS=0
	//LCD_PORT &= ~(1<<RS);
	CLR_BIT(LCD_PORT,RS);
	//RW=0
	//LCD_PORT &= ~(1<<RW);
	CLR_BIT(LCD_PORT,RW);

	//Enable=1
	//LCD_PORT |= (1<<Enable);
	SET_BIT(LCD_PORT,Enable);


	_delay_ms(15);

	//LCD_PORT &= ~(1<<Enable);
	CLR_BIT(LCD_PORT,Enable);

	/*
		 * SENDING LOWER NIBBLE
		 * */

	LCD_PORT = (LCD_PORT & 0x0F) | (cmd <<4);


	//Enable=1
		//LCD_PORT |= (1<<Enable);
		SET_BIT(LCD_PORT,Enable);
		_delay_ms(10);

		//LCD_PORT &= ~(1<<Enable);
		CLR_BIT(LCD_PORT,Enable);
		_delay_ms(10);

}
void LCD_DISP_CHAR(char c){
	//if(LCD_DISP_CURR_POS==0x90) LCD_DISP_CURR_POS=0xC0;
//LCD_SEND_XY();
	/*s I have explained earlier about comma
	 * SENDING UPPER NIBBLE
	 * */
	//data
	LCD_PORT = (LCD_PORT & 0x0F)| (c & 0xF0);
	//RS=1
	LCD_PORT |= (1<<RS);

	//RW=0
	LCD_PORT &= ~(1<<RW);

	//Enable =1
	LCD_PORT |= (1<<Enable);

	_delay_ms(5);

	//Enable =0
		LCD_PORT &= ~ (1<<Enable);



		/*
		 * SENDING LOWER NIBBLE
		 * */
		LCD_PORT = (LCD_PORT & 0x0F) | (c <<4);

		//Enable =1
		LCD_PORT |= (1<<Enable);

		_delay_ms(5);

		//Enable =0
		LCD_PORT &= ~ (1<<Enable);

		//LCD_DISP_CURR_POS++;


}
void LCD_DISP_STR(char arr[]){
int i=0;

while(arr[i] != '\0'){
	LCD_DISP_CHAR(arr[i]);
	i++;
}
}

void LCD_SEND_XY(uint8 row,uint8 pos,uint8 *str)
{
if (row == 0 && pos<16)
	LCD_SEND_CMD((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_SEND_CMD((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_DISP_STR(str);		/* Call LCD string function */
}

