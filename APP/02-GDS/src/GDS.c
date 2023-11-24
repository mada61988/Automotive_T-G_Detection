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
/****
- GLOBALVARS:  
****/
uint8  u8GDS_State; 


void GDS_vidInit(void)
{
    u8GDS_State = GDS_stateIDLE;

    LCD_SEND_XY(1,0,"SMK-LVL: ");
}

void GDS_vidManager(void *pt)
{
    
while(1)
{
LCD_SEND_XY(1,11,"IDLE");
vTaskDelay(100);
}
    
}