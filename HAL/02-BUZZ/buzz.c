#include "Platform_Types.h"
#include "BIT_MATH.h"
#include "dio_interface.h"
#include "dio_register.h"
#include "buzz.h"



void BUZZ_vidSetBuzzState(uint8 state)
{
    switch(state)
    {
        case BUZZ_ON:  SET_BIT(BUZZ_PORT_REG,BUZZ_PIN); break;   // Set Buzzer ON
        case BUZZ_OFF: CLR_BIT(BUZZ_PORT_REG,BUZZ_PIN); break;   //Set Buzzer OFF
    }
}