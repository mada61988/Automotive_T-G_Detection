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
uint8 TDM_u8ClrDispArr[] = "      ";
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
char arr1[10];
char arr2[10];
 void TDS_vidGetCurrTemp()
 {

   // algorithm
  /*
    float ADC_u8Resolution = 5.0/1024; //4.88v
    float Vout = ((ADC_u8ReadChannel((uint8) 0) ) * ADC_u8Resolution);
    TDM_u8Cu(char)intValuerrentTemp = (Vout/0.01);
  
    itoa(TDM_u8CurrentTemp,TDS_u8CurrTempArr,10.00);
*/
uint16 container=0;

     // for(uint8 i =0;i<10;i++) container += ADC_u8ReadChannel((uint8) 0);

      //uint16 ADC_fValue = container / 10;
      uint16 ADC_fRawADC = ADC_u8ReadChannel((uint8) 0);
      double Vout = ADC_fRawADC * 0.0048828;
     // double temp = Vout/0.01;


      float TDM_u16MiliVolt = ( ((uint32)ADC_u8ReadChannel((uint8) 0)) * 5000UL ) / 256UL;
      float celcuis = TDM_u16MiliVolt / 10;  

      double temperature = ((double)ADC_fRawADC / 255.0) * 100.0;
            int intValue = (int)temperature;
       int decimalPart = (temperature - intValue) * 100;
 //float TDM_u16Volt = TDM_u16MiliVolt / (float)1000;

for(uint8 i=0;i<16;i++){
TDS_u8CurrTempArr[i] = ' ';
}

itoa(intValue,arr1,10);

itoa(decimalPart,arr2,10);

      // Every 0.01V is equal to 1C, so to get the current Temp we devide the voltage with 0.01
    //  float temp = TDM_u16Volt/0.01;  
        //float temp = TDM_u16MiliVolt/10;
      //uint16 adcRow = ADC_u8ReadChannel((uint8)0);

      itoa(ADC_fRawADC,TDS_u8CurrTempArr,10);

 



 }

 void TDS_vidDisplayTemp()
 {

    // Remove the current displayed number
    LCD_SEND_XY(RAW0,COLUMN10,TDM_u8ClrDispArr);
   LCD_SEND_CMD(Clear);
  


  //LCD_SEND_XY(RAW0,COLUMN0,TDS_u8CurrTempArr);
   LCD_SEND_XY(RAW0,COLUMN0,arr1);
   LCD_DISP_CHAR((char)'.');
  LCD_DISP_STR(arr2);

   TDM_u8LastTempVal = TDM_u8CurrentTemp;
 }

void TDS_vidLedHander(uint8 state)
{



}

void TDS_vidBuzzHandler(uint8 state)
{
  BUZZ_vidBuzzCycleStart(state); // Start a Buzzer Cycle
}