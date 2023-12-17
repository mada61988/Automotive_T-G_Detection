/*********************************************************************************
**********************   DATE:           14.11.2023         **********************
**********************   NAME:          MohamedAyman        **********************
**********************  LAYER:              APP             **********************
**********************    SWC:              NONE            **********************
**********************     VER:              01             **********************
**********************   FILE:             TDS.c            **********************
***********************************************************************************/


/*********************************    DESCRYPTION:    ********************************************
- TDS: Tempereture Detection Module, the application layer for the Tempereture detection handling.
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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "buzz_interface.h"
#include <avr/delay.h>

/****
- GLOBALVARS:  
****/
uint8 TDS_u8State; 
uint8 TDS_u8CurrTempArr[16];
uint8 TDS_u8CelsiusSymbol[]={0b11011111,0b01000011};
uint8 TDM_u8CurrentTemp;
uint8 TDM_u8ClrDispArr[] = "   ";
uint8 TDM_u8LastTempVal;

void TDS_vidInit(void)
{
    TDS_u8State=IDLE;
    LCD_SEND_XY(RAW0,COLUMN0,"ENG-TMP: ");
    LCD_SEND_XY(RAW0,COLUMN13,"");
   LCD_DISP_CHAR(0b11011111);
   LCD_DISP_CHAR(0b01000011);
}


void TDS_vidManager(void *pt)
{
  
   while(1)
   {
         TDS_vidGetCurrTemp();

         TDS_vidDisplayTemp();

   switch(TDS_u8State)
   {
   case IDLE:



         TDS_vidLedHander(IDLE);
        

         if(TDM_u8CurrentTemp > MAX_TEMP) TDS_u8State = DANGER;
         
         else if( (TDM_u8CurrentTemp > WARNING_TEMP) &&  (TDM_u8CurrentTemp < MAX_TEMP) ) TDS_u8State = WARNING;
         
         else; // same state IDLE state
   
   break;

   case WARNING:


         TDS_vidLedHander(WARNING);
         TDS_vidBuzzHandler(WARNING);

         if(TDM_u8CurrentTemp <= WARNING_TEMP) 
         {
               TDS_u8State=IDLE; 
         }

         else if(TDM_u8CurrentTemp > MAX_TEMP)
         {
            TDS_u8State=DANGER; 
         }

         else; //same state WARNING
         
   break;
   
   case DANGER:
         
         
         TDS_vidLedHander(DANGER);
         TDS_vidBuzzHandler(DANGER);

         if(TDM_u8CurrentTemp <= WARNING_TEMP) 
         {
               TDS_u8State=IDLE; 
         }

         else if((TDM_u8CurrentTemp > WARNING_TEMP) &&  (TDM_u8CurrentTemp < MAX_TEMP))
         {
            TDS_u8State=WARNING; 
         }

         else; //same state DANGER  
   break;

   default:
   //do nothing
   break;
   }

   vTaskDelay(200);

   }
   
    
}

 void TDS_vidGetCurrTemp()
 {

   // algorithm
  /*
    float ADC_u8Resolution = 5.0/1024; //4.88v
    float Vout = ((ADC_u8ReadChannel((uint8) 0) ) * ADC_u8Resolution);
    TDM_u8CurrentTemp = (Vout/0.01);
  
    itoa(TDM_u8CurrentTemp,TDS_u8CurrTempArr,10.00);
*/

      float ADC_fValue = ADC_u8ReadChannel((uint8) 0);
      float Vout = ADC_fValue * 0.0048828;
      float temp = Vout/0.01;
      itoa(temp,TDS_u8CurrTempArr,10);

 }

 void TDS_vidDisplayTemp()
 {
   if( (TDM_u8LastTempVal >= 100) && (TDM_u8CurrentTemp < 100) )
   {
    // Remove the current displayed number
    LCD_SEND_XY(RAW0,COLUMN10,TDM_u8ClrDispArr);
   
   }


  LCD_SEND_XY(RAW0,COLUMN10,TDS_u8CurrTempArr);
   

   TDM_u8LastTempVal = TDM_u8CurrentTemp;
 }

void TDS_vidLedHander(uint8 state)
{



}

void TDS_vidBuzzHandler(uint8 state)
{
  BUZZ_vidBuzzCycleStart(state); // Start a Buzzer Cycle
}