/***************************************************/
/***************DIO_INTERFACE***********************/
/***************************************************/

/********Contains********/
/***Function Prototypes**/

/****Function Prototypes**/


extern void DIO_VoidSetPortDirection(uint8  u8_Port,uint8  u8_Direction);
extern void DIO_VoidSetPortValue(uint8  u8_Port,uint8  u8_Value);
extern void DIO_VoidSetPinDirection(uint8  u8_Port,uint8  u8_Pin,uint8  u8_Direction);
extern void DIO_VoidSetPinValue(uint8  u8_Port,uint8  u8_Pin, uint8  u8_Value);
extern void DIO_VoidTglPin(uint8  DIO_u8Port,uint8  DIO_u8Pin);
extern void DIO_Init(void);

/* Port Initialization */
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/* Pin Initialization */
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/* HIGH LOW INIT */
#define HIGH 1
#define LOW 0

/* OUTPUT INPUT INIT */
#define OUTPUT      1
#define INPUT       0

#define ON              1
#define OFF             0

#define OUT             1
#define IN              0
