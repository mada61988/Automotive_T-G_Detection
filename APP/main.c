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
#include "LCD_Interface.h"
#include "ADC_Interface.h"
/****
- GLOBALVARS:  
****/
xTaskHandle TDSTaskHandler = NULL;
xTaskHandle GDSTaskHandler = NULL;


int main()
{
    // Initialize Modules
DIO_Init();
LCD_INIT();
ADC_Init();
// Display Application Startup Logo
LCD_SEND_XY(0,0," Automotive T&G ");
_delay_ms(100);
LCD_SEND_XY(1,4,"Detector");
_delay_ms(500);

LCD_SEND_CMD(Clear);

LCD_SEND_XY(0,2,"Initializing");
_delay_ms(100);
LCD_SEND_XY(1,3,"Compnents...");
_delay_ms(500);

LCD_SEND_CMD(Clear);
_delay_ms(100);
GDS_vidInit();
TDS_vidInit();

//LCD_SEND_XY(1,6,"MADA");
//LCD_DISP_STR("HEllo WOrld");
// Create task for every manager function
xTaskCreate(&TDS_vidManager,NULL,200,NULL,tskIDLE_PRIORITY,NULL);
xTaskCreate(&GDS_vidManager,NULL,200,NULL,tskIDLE_PRIORITY,NULL);

// Run the Scheduler 
vTaskStartScheduler();

//Start while for app 
while(1);


return 0;
}
