/*******************************************************************************/
/**********************************DIO_PROGRAM*********************************/
/******************************************************************************/

/****INCLUDES****/
#include "Platform_Types.h"
#include "BIT_MATH.h"
#include "dio_cfg.h"


/*****
INITIALIZE:
*****/

void DIO_Init(void)
{


		// PORTA Direction
		DIO_SetPinDirection(PORTA,PIN0,PORTA_PIN0_DIR);
		DIO_SetPinDirection(PORTA,PIN1,PORTA_PIN1_DIR);
		DIO_SetPinDirection(PORTA,PIN2,PORTA_PIN2_DIR);
		DIO_SetPinDirection(PORTA,PIN3,PORTA_PIN3_DIR);
		DIO_SetPinDirection(PORTA,PIN4,PORTA_PIN4_DIR);
		DIO_SetPinDirection(PORTA,PIN5,PORTA_PIN5_DIR);
		DIO_SetPinDirection(PORTA,PIN6,PORTA_PIN6_DIR);
		DIO_SetPinDirection(PORTA,PIN7,PORTA_PIN7_DIR);

		//PORTB Direction
		DIO_SetPinDirection(PORTB,PIN0,PORTB_PIN0_DIR);
		DIO_SetPinDirection(PORTB,PIN1,PORTB_PIN1_DIR);
		DIO_SetPinDirection(PORTB,PIN2,PORTB_PIN2_DIR);
		DIO_SetPinDirection(PORTB,PIN3,PORTB_PIN3_DIR);
		DIO_SetPinDirection(PORTB,PIN4,PORTB_PIN4_DIR);
		DIO_SetPinDirection(PORTB,PIN5,PORTB_PIN5_DIR);
		DIO_SetPinDirection(PORTB,PIN6,PORTB_PIN6_DIR);
		DIO_SetPinDirection(PORTB,PIN7,PORTB_PIN7_DIR);

		//PORTC Direction
		DIO_SetPinDirection(PORTC,PIN0,PORTC_PIN0_DIR);
		DIO_SetPinDirection(PORTC,PIN1,PORTC_PIN1_DIR);
		DIO_SetPinDirection(PORTC,PIN2,PORTC_PIN2_DIR);
		DIO_SetPinDirection(PORTC,PIN3,PORTC_PIN3_DIR);
		DIO_SetPinDirection(PORTC,PIN4,PORTC_PIN4_DIR);
		DIO_SetPinDirection(PORTC,PIN5,PORTC_PIN5_DIR);
		DIO_SetPinDirection(PORTC,PIN6,PORTC_PIN6_DIR);
		DIO_SetPinDirection(PORTC,PIN7,PORTC_PIN7_DIR);


		//PORTD Direction
		DIO_SetPinDirection(PORTD,PIN0,PORTD_PIN0_DIR);
		DIO_SetPinDirection(PORTD,PIN1,PORTD_PIN1_DIR);
		DIO_SetPinDirection(PORTD,PIN2,PORTD_PIN2_DIR);
		DIO_SetPinDirection(PORTD,PIN3,PORTD_PIN3_DIR);
		DIO_SetPinDirection(PORTD,PIN4,PORTD_PIN4_DIR);
		DIO_SetPinDirection(PORTD,PIN5,PORTD_PIN5_DIR);
		DIO_SetPinDirection(PORTD,PIN6,PORTD_PIN6_DIR);
		DIO_SetPinDirection(PORTD,PIN7,PORTD_PIN7_DIR);

//===================================================================================
		
		//PORTA PIN VALUE
		//DIO_SetPinValue(PORTA,PIN0,PORTA_PIN0_VAL);
		//DIO_SetPinValue(PORTA,PIN1,PORTA_PIN1_VAL);
		DIO_SetPinValue(PORTA,PIN2,PORTA_PIN2_VAL);
		DIO_SetPinValue(PORTA,PIN3,PORTA_PIN3_VAL);
		DIO_SetPinValue(PORTA,PIN4,PORTA_PIN4_VAL);
		DIO_SetPinValue(PORTA,PIN5,PORTA_PIN5_VAL);
		DIO_SetPinValue(PORTA,PIN6,PORTA_PIN6_VAL);
		DIO_SetPinValue(PORTA,PIN7,PORTA_PIN7_VAL);

		//PORTB PIN VALUE
		DIO_SetPinValue(PORTB,PIN0,PORTB_PIN0_VAL);
		DIO_SetPinValue(PORTB,PIN1,PORTB_PIN1_VAL);
		DIO_SetPinValue(PORTB,PIN2,PORTB_PIN2_VAL);
		DIO_SetPinValue(PORTB,PIN3,PORTB_PIN3_VAL);
		DIO_SetPinValue(PORTB,PIN4,PORTB_PIN4_VAL);
		DIO_SetPinValue(PORTB,PIN5,PORTB_PIN5_VAL);
		DIO_SetPinValue(PORTB,PIN6,PORTB_PIN6_VAL);
		DIO_SetPinValue(PORTB,PIN7,PORTB_PIN7_VAL);

		//PORTC PIN VALUE
		DIO_SetPinValue(PORTC,PIN0,PORTC_PIN0_VAL);
		DIO_SetPinValue(PORTC,PIN1,PORTC_PIN1_VAL);
		DIO_SetPinValue(PORTC,PIN2,PORTC_PIN2_VAL);
		DIO_SetPinValue(PORTC,PIN3,PORTC_PIN3_VAL);
		DIO_SetPinValue(PORTC,PIN4,PORTC_PIN4_VAL);
		DIO_SetPinValue(PORTC,PIN5,PORTC_PIN5_VAL);
		DIO_SetPinValue(PORTC,PIN6,PORTC_PIN6_VAL);
		DIO_SetPinValue(PORTC,PIN7,PORTC_PIN7_VAL);


		//PORTD PIN VALUE
		DIO_SetPinValue(PORTD,PIN0,PORTD_PIN0_VAL);
		DIO_SetPinValue(PORTD,PIN1,PORTD_PIN1_VAL);
		DIO_SetPinValue(PORTD,PIN2,PORTD_PIN2_VAL);
		DIO_SetPinValue(PORTD,PIN3,PORTD_PIN3_VAL);
		DIO_SetPinValue(PORTD,PIN4,PORTD_PIN4_VAL);
		DIO_SetPinValue(PORTD,PIN5,PORTD_PIN5_VAL);
		DIO_SetPinValue(PORTD,PIN6,PORTD_PIN6_VAL);
		DIO_SetPinValue(PORTD,PIN7,PORTD_PIN7_VAL);


	
}




/**************************SET-PORT-DIRECTION******************/
void DIO_SetPortDirection(uint8 Copy_u8Port,uint8 Copy_u8Direction){

/*****************************/
/****SET-PORT-OUTPUT**********/
/*****************************/
if(Copy_u8Direction == OUTPUT)
{
switch(Copy_u8Port){
case PORTA: DDRA_REG=0xFF; break;
case PORTB: DDRB_REG=0xFF; break;
case PORTC: DDRC_REG=0xFF; break;
case PORTD: DDRD_REG=0xFF; break;
}
}

/*****************************/
/****SET-PORT-INPUT**********/
/*****************************/
else if(Copy_u8Direction == INPUT){
switch(Copy_u8Port){
case PORTA: DDRA_REG=0x00; break;
case PORTB: DDRB_REG=0x00; break;
case PORTC: DDRC_REG=0x00; break;
case PORTD: DDRD_REG=0x00; break;
}
}

}



/**************************SET-PIN-DIRECTION******************/
void DIO_SetPinDirection(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 Copy_u8Direction){


/*****************************/
/****SET-PIN-OUTPUT**********/
/*****************************/
if(Copy_u8Direction==1){
switch(Copy_u8Port){
case PORTA: SET_BIT(DDRA_REG,Copy_u8Pin); break;
case PORTB: SET_BIT(DDRB_REG,Copy_u8Pin); break;
case PORTC: SET_BIT(DDRC_REG,Copy_u8Pin); break;
case PORTD: SET_BIT(DDRD_REG,Copy_u8Pin); break; 
}
}

/*****************************/
/****SET-PIN-INPUT**********/
/*****************************/
else if(Copy_u8Direction==INPUT){
switch(Copy_u8Port){
case PORTA: CLR_BIT(DDRA_REG,Copy_u8Pin); break;
case PORTB: CLR_BIT(DDRB_REG,Copy_u8Pin); break;
case PORTC: CLR_BIT(DDRC_REG,Copy_u8Pin); break;
case PORTD: CLR_BIT(DDRD_REG,Copy_u8Pin); break; 
}
}

}

/**************************SET-PORT-VALUE******************/
void DIO_SetPortValue(uint8 Copy_u8Port,uint8 Copy_u8Value){

/*****************************/
/****SET-PORT-HIGH**********/
/*****************************/
if(Copy_u8Value==HIGH){
switch(Copy_u8Port){
case PORTA: PORTA_REG=0xFF; break;
case PORTB: PORTB_REG=0xFF; break;
case PORTC: PORTC_REG=0xFF; break;
case PORTD: PORTD_REG=0xFF; break;
}	
}

/*****************************/
/****SET-PORT-LOW**********/
/*****************************/
else if(Copy_u8Value==LOW){
switch(Copy_u8Port){
case PORTA: PORTA_REG=0x00; break;
case PORTB: PORTB_REG=0x00; break;
case PORTC: PORTC_REG=0x00; break;
case PORTD: PORTD_REG=0x00; break;
}
}
}

/**************************SET-PIN-VALUE******************/
void DIO_SetPinValue(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 Copy_u8Value){

/*****************************/
/****SET-PIN-HIGH**********/
/*****************************/
if(Copy_u8Value==HIGH){
switch(Copy_u8Port){
	case PORTA: SET_BIT(PORTA_REG,Copy_u8Pin); break;
	case PORTB: SET_BIT(PORTB_REG,Copy_u8Pin); break;
	case PORTC: SET_BIT(PORTC_REG,Copy_u8Pin); break;
	case PORTD: SET_BIT(PORTD_REG,Copy_u8Pin); break;
}	
}

/*****************************/
/****SET-PIN-LOW**********/
/*****************************/
if(Copy_u8Value==LOW){
switch(Copy_u8Port){
	case PORTA: CLR_BIT(PORTA_REG,Copy_u8Pin); break;
	case PORTB: CLR_BIT(PORTB_REG,Copy_u8Pin); break;
	case PORTC: CLR_BIT(PORTC_REG,Copy_u8Pin); break;
	case PORTD: CLR_BIT(PORTD_REG,Copy_u8Pin); break;
}
}
}


/*****************************/
/****Toggle Pin**********/
/*****************************/
void DIO_VoidTglPin(uint8  DIO_u8Port,uint8  DIO_u8Pin)
{

switch(DIO_u8Port)
{
	case PORTA: TOG_BIT(PORTA_REG,DIO_u8Pin); break;
	case PORTB: TOG_BIT(PORTB_REG,DIO_u8Pin); break;
	case PORTC: TOG_BIT(PORTC_REG,DIO_u8Pin); break;
	case PORTD: TOG_BIT(PORTD_REG,DIO_u8Pin); break;
}


}