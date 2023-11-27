
//HeaderGuard
#ifndef BUZZ_H_
#define BUZZ_H_

#define BUZZ_ON   1 
#define BUZZ_OFF  2  

#define BUZZ_PORT_REG   PORTD_REG
#define BUZZ_PIN            0

void BUZZ_vidSetBuzzState(uint8 state);
void BUZZ_vidBuzzCycleManager(void *pt);

typedef struct
{
    uint8 buzzState; 
    uint8 dangerSeverity;
}BuzzState;

#endif