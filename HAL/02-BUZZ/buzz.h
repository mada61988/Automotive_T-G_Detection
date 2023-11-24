
//HeaderGuard
#ifndef BUZZ_H_
#define BUZZ_H_

#define BUZZ_ON   0 
#define BUZZ_OFF  1  

#define BUZZ_PORT_REG   PORTD_REG
#define BUZZ_PIN            0

void BUZZ_vidSetBuzzState(uint8 state);

#endif