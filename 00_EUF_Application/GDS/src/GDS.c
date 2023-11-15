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

/****
- GLOBALVARS:  
****/
uint8 u8GDS_State; 


void GDS_vidInit(void)
{
    u8GDS_State = IDLE;
}

void GDS_vidManager(void *pv)
{
    // do something
}