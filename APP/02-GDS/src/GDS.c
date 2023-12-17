/*********************************************************************************
**********************   DATE:           14.11.2023         **********************
**********************   NAME:          MohamedAyman        **********************
**********************  LAYER:              APP             **********************
**********************    SWC:              NONE            **********************
**********************     VER:              01             **********************
**********************   FILE:             GDS.c            **********************
***********************************************************************************/


/*********************************    DESCRYPTION:    *****************************
- GDS: Gas Detection System, the application layer for the gas detection handling.
***********************************************************************************/


/****
- INCLUDES:  
****/
#include "Platform_Types.h"
#include "GDS.h"
#include "GDS_Wrp.h"
#include "Platform_Types.h"
#include "BIT_MATH.h"
#include "LCD_Interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "MQ2_Interface.h"
#include <stdlib.h>

/****
- GLOBALVARS:  
****/
uint8  GDM_u8State; 
float Ro; 
uint8 smoke[5];
uint8 lpg[16];   //Liquified petroleum gas
uint8 GDM_u8ClearLcdArr[3] = {' ',' ',' '};

void GDM_vidInit(void)
{
    GDM_u8State = GDM_u8StateIDLE;
    Ro = SensorCalibration();
    LCD_SEND_XY(1,0,"SMK-LVL: ");
    //LCD_SEND_XY(1,11,"IDLE");
}

/***
* \brief   : Manager for Gas Deletction Module 
  \returns : NONE 
***/


void GDM_vidManager(void *pt)
{
    
while(1)
{

    switch(GDM_u8State)
    {
        case GDM_u8StateIDLE:
        // First Get the GAS Persentage
        itoa(GetGasPercentage(ReadSensor()/Ro,LPG), smoke, 10);
        // LCD_SEND_XY(RAW1,COLUMN10,smoke[0]);
       //itoa(GetGasPercentage(ReadSensor()/Ro,SMOKE), smoke, 10);
      // itoa(Ro,smoke,10);
       // LCD_SEND_XY(1,0,GDM_u8ClearLcdArr);
       // LCD_SEND_XY(1,0,smoke);

        break;

        case GDM_u8StateWRNG:

        break;


        case GDM_u8StateDNGR:

        break;
        
    }

vTaskDelay(100);
}
    
}