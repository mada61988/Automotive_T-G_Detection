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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "buzz.h"

/****
- GLOBALVARS:  
****/
uint8 TDS_u8State; 
uint8 TDS_u8CurrTempArr[16];
uint8 TDS_u8CelsiusSymbol[]={0b11011111,'C'};
float TDS_flCurrentTempInInteger;


void TDS_vidInit(void)
{
    TDS_u8State=IDLE;
    LCD_SEND_XY(RAW0,COLUMN0,"ENG-TMP: ");
}


void TDS_vidManager(void *pt)
{
  
   while(1)
   {



   switch(TDS_u8State)
   {
   case IDLE:

         TDS_vidGetCurrTemp();

         TDS_vidDisplayTemp();

         TDS_vidLedHander(IDLE);
         TDS_vidBuzzHandler(IDLE);

         if(TDS_flCurrentTempInInteger > MAX_TEMP) TDS_u8State = DANGER;
         
         else if( (TDS_flCurrentTempInInteger > WARNING_TEMP) &&  (TDS_flCurrentTempInInteger < MAX_TEMP) ) TDS_u8State = WARNING;
         
         else; // same state IDLE state
   
   break;

   case WARNING:

         TDS_vidGetCurrTemp();
         TDS_vidDisplayTemp();
         TDS_vidLedHander(WARNING);
         TDS_vidBuzzHandler(WARNING);

         if(TDS_flCurrentTempInInteger <= WARNING_TEMP) 
         {
               TDS_u8State=IDLE; 
         }

         else if(TDS_flCurrentTempInInteger > MAX_TEMP)
         {
            TDS_u8State=DANGER; 
         }

         else; //same state WARNING
         
   break;
   
   case DANGER:
         TDS_vidGetCurrTemp();
         TDS_vidDisplayTemp();
         TDS_vidLedHander(DANGER);
         TDS_vidBuzzHandler(DANGER);

         if(TDS_flCurrentTempInInteger <= WARNING_TEMP) 
         {
               TDS_u8State=IDLE; 
         }

         else if((TDS_flCurrentTempInInteger > WARNING_TEMP) &&  (TDS_flCurrentTempInInteger < MAX_TEMP))
         {
            TDS_u8State=WARNING; 
         }

         else; //same state WARNING
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
  
    float ADC_u8Resolution = 5.0/1024; //4.88v
    float Vout = ((ADC_u8ReadChannel((uint8) 0) ) * ADC_u8Resolution);
    TDS_flCurrentTempInInteger = (Vout/0.01);
  
    itoa(TDS_flCurrentTempInInteger,TDS_u8CurrTempArr,10.00);

 }

 void TDS_vidDisplayTemp()
 {
   LCD_SEND_XY(RAW0,COLUMN10,TDS_u8CurrTempArr);
   LCD_SEND_XY(RAW0,COLUMN14,TDS_u8CelsiusSymbol);
 }

void TDS_vidLedHander(uint8 state)
{

switch (state)
{
   case IDLE:

      

   break;

   case WARNING:
   
   break;

   case DANGER:
   
   break;

default:
   break;
}

}

void TDS_vidBuzzHandler(uint8 state)
{

}