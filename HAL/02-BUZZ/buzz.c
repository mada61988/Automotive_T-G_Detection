/*********************************************************************************
**********************   DATE:           14.11.2023         **********************
**********************   NAME:          MohamedAyman        **********************
**********************  LAYER:              HAL             **********************
**********************    SWC:              Buzzer          **********************
**********************     VER:              01             **********************
**********************   FILE:             buzz.c            **********************
***********************************************************************************/


/*********************************    DESCRYPTION:    ********************************************
- BUZZ: Buzzer Module, controls the buzzer state and cycle
**************************************************************************************************/


/****
- INCLUDES:  
****/

#include "Platform_Types.h"
#include "BIT_MATH.h"
#include "dio_interface.h"
#include "dio_register.h"
#include "buzz.h"
#include "buzz_interface.h"
#include <avr/delay.h>
#include "FreeRTOS.h"
#include "task.h"


/****
- GLOBALVARS:  
****/


BuzzState BUZZ_stBuzzState = {255U,255U};


void BUZZ_vidSetBuzzState(uint8 state)
{
    switch(state)
    {
        case BUZZ_ON:  SET_BIT(BUZZ_PORT_REG,BUZZ_PIN); break;   // Set Buzzer ON
        case BUZZ_OFF: CLR_BIT(BUZZ_PORT_REG,BUZZ_PIN); break;   //Set Buzzer OFF
    }
}

void BUZZ_vidBuzzCycleManager(void *pt)
{
        while(1)
        {
           
            if(BUZZ_stBuzzState.buzzState == BUZZ_ON)
            {
                switch (BUZZ_stBuzzState.dangerSeverity)
                {
                case WARNING:
                    
                    BUZZ_vidSetBuzzState(BUZZ_ON);

                    _delay_ms(500);

                    BUZZ_vidSetBuzzState(BUZZ_OFF);

                    _delay_ms(1500);

                    break;

                 case DANGER:

                    BUZZ_vidSetBuzzState(BUZZ_ON);

                    _delay_ms(500);

                    BUZZ_vidSetBuzzState(BUZZ_OFF);

                    _delay_ms(500);

                    break;

                default:
                // Do nothing
                    break;
                }
            }
            BUZZ_stBuzzState.buzzState  = BUZZ_OFF;
            vTaskDelay(200);
        }
}

void BUZZ_vidBuzzCycleStart(uint8 feat_u8State)
{
  BUZZ_stBuzzState.buzzState  = BUZZ_ON;
  BUZZ_stBuzzState.dangerSeverity = feat_u8State;
}

