/*********************************************************************************
**********************   DATE:           14.11.2023         **********************
**********************   NAME:          MohamedAyman        **********************
**********************  LAYER:              APP             **********************
**********************    SWC:              NONE            **********************
**********************     VER:              01             **********************
**********************   FILE:             main.c            **********************
***********************************************************************************/


/*********************************    DESCRYPTION:    ********************************************
- MAIN: main file of the projece, initialize the OS and Tasks
**************************************************************************************************/



/****
- INCLUDES:  
****/
#include "Platform_Types.h"
#include "FreeRTOS.h"
#include "task.h"
#include <avr/delay.h>
#include "TDS.h"
#include "GDS.h"
#include "dio_interface.h"

/****
- GLOBALVARS:  
****/


int main()
{

// Initialize
GDS_vidInit();
TDS_vidInit();
DIO_INIT();
// create task for every manager function
xTaskCreate(&TDS_vidManager,NULL,100,NULL,0,NULL);
xTaskCreate(&GDS_vidManager,NULL,100,NULL,0,NULL);

while(1);

return 0;
}