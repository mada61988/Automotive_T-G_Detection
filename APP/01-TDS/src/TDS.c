/*********************************************************************************
**********************   DATE:           14.11.2023         **********************
**********************   NAME:          MohamedAyman        **********************
**********************  LAYER:              APP             **********************
**********************    SWC:              NONE            **********************
**********************     VER:              01             **********************
**********************   FILE:             TDS.c            **********************
***********************************************************************************/


/*********************************    DESCRYPTION:    ********************************************
- TDS: Tempereture Detection System, the application layer for the Tempereture detection handling.
**************************************************************************************************/





/***** INCLUDES: ******/
#include "TDS.h"
#include "TDS_Wrp.h"
#include "Platform_Types.h"
#include "BIT_MATH.h" 
#include "LCD_Interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "ADC_Interface.h"

/****
- GLOBALVARS:  
****/
uint8  TDS_u8State; 
 uint8* TDS_u8CurrTempArr[16];
uint16 counter=0;
#define degree_sysmbol 0b01110010


void TDS_vidInit(void)
{
    TDS_u8State=IDLE;
    LCD_SEND_XY(0,0,"ENG-TMP: ");
}

uint8 arr[5];
void TDS_vidManager(void *pt)
{
  
   while(1)
   {

     TDS_vidGetCurrTemp();
counter++;
//sprintf(celsius, "%d%cC", ( ((ADC_u8ReadChannel((uint8) 0)) * (4.88) ) /10.00 ),degree_sysmbol);
LCD_DISP_CHAR('d');
LCD_DISP_STR("sssssssssssss");
vTaskDelay(200);

   }
   
    
}

 void TDS_vidGetCurrTemp()
 {
    /*
    uint16 temp;
    // Get ADC reading
    temp = (ADC_u8ReadChannel((uint8) 0) / 2.01);
    itoa(temp,TDS_u8CurrTempArr,10);
*/

    float ADC_u8Resolution = 5.0/1024; //4.88v
    float Vout = ((ADC_u8ReadChannel((uint8) 0) ) * ADC_u8Resolution);
    float temp = (Vout/0.01);

    sprintf(TDS_u8CurrTempArr,"%fc",temp);

 }