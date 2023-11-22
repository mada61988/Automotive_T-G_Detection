/*********************************************************************************
**********************   DATE:           118.11.2023         **********************
**********************   NAME:          MohamedAyman        **********************
**********************  LAYER:              MCAL             **********************
**********************    SWC:              DIO            **********************
**********************     VER:              01             **********************
**********************   FILE:             dio_cfg.h         **********************
***********************************************************************************/

/********************************************
 DESCRYPTION: Configuration file for dio driver. 
**********************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H
/*****
INCLUDES: 
*****/
#include "dio_register.h"
#include "dio_interface.h"



/***
 INFO: PORTA Pin Configuration
 VALUES: 1- OUT
         2- IN
         3- OFF
****/
#define PORTA_PIN0_DIR      IN
#define PORTA_PIN1_DIR      IN
#define PORTA_PIN2_DIR      IN
#define PORTA_PIN3_DIR      IN
#define PORTA_PIN4_DIR      IN
#define PORTA_PIN5_DIR      IN
#define PORTA_PIN6_DIR      IN
#define PORTA_PIN7_DIR      IN


/***
 INFO: PORTB Pin Configuration
 VALUES: 1- OUT
         2- IN
         3- OFF
****/
#define PORTB_PIN0_DIR      IN
#define PORTB_PIN1_DIR      IN
#define PORTB_PIN2_DIR      IN
#define PORTB_PIN3_DIR      IN
#define PORTB_PIN4_DIR      IN
#define PORTB_PIN5_DIR      IN
#define PORTB_PIN6_DIR      IN
#define PORTB_PIN7_DIR      IN

/***
 INFO: PORTC Pin Configuration
 VALUES: 1- OUT
         2- IN
         3- OFF
****/
#define PORTC_PIN0_DIR      OUT
#define PORTC_PIN1_DIR      OUT
#define PORTC_PIN2_DIR      OUT
#define PORTC_PIN3_DIR      OUT
#define PORTC_PIN4_DIR      OUT
#define PORTC_PIN5_DIR      OUT
#define PORTC_PIN6_DIR      OUT
#define PORTC_PIN7_DIR      OUT

/***
 INFO: PORTD Pin Configuration
 VALUES: 1- OUT
         2- IN
         3- OFF
****/
#define PORTD_PIN0_DIR      OUT
#define PORTD_PIN1_DIR      OUT
#define PORTD_PIN2_DIR      OUT
#define PORTD_PIN3_DIR      IN
#define PORTD_PIN4_DIR      IN
#define PORTD_PIN5_DIR      IN
#define PORTD_PIN6_DIR      IN
#define PORTD_PIN7_DIR      IN



/***
 INFO: PORTA Pin Configuration
 VALUES: 1- HIGH
         2- LOW
       
****/
#define PORTA_PIN0_VAL      LOW
#define PORTA_PIN1_VAL      LOW
#define PORTA_PIN2_VAL      LOW
#define PORTA_PIN3_VAL      LOW
#define PORTA_PIN4_VAL      LOW
#define PORTA_PIN5_VAL      LOW
#define PORTA_PIN6_VAL      LOW
#define PORTA_PIN7_VAL      LOW

/***
 INFO: PORTA Pin Configuration
 VALUES: 1- HIGH
         2- LOW
       
****/
#define PORTB_PIN0_VAL      LOW
#define PORTB_PIN1_VAL      LOW
#define PORTB_PIN2_VAL      LOW
#define PORTB_PIN3_VAL      LOW
#define PORTB_PIN4_VAL      LOW
#define PORTB_PIN5_VAL      LOW
#define PORTB_PIN6_VAL      LOW
#define PORTB_PIN7_VAL      LOW

/***
 INFO: PORTA Pin Configuration
 VALUES: 1- HIGH
         2- LOW
       
****/
#define PORTC_PIN0_VAL      LOW
#define PORTC_PIN1_VAL      LOW
#define PORTC_PIN2_VAL      LOW
#define PORTC_PIN3_VAL      LOW
#define PORTC_PIN4_VAL      LOW
#define PORTC_PIN5_VAL      LOW
#define PORTC_PIN6_VAL      LOW
#define PORTC_PIN7_VAL      LOW

/***
 INFO: PORTA Pin Configuration
 VALUES: 1- HIGH
         2- LOW
       
****/
#define PORTD_PIN0_VAL      LOW
#define PORTD_PIN1_VAL      LOW
#define PORTD_PIN2_VAL      LOW
#define PORTD_PIN3_VAL      LOW
#define PORTD_PIN4_VAL      LOW
#define PORTD_PIN5_VAL      LOW
#define PORTD_PIN6_VAL      LOW
#define PORTD_PIN7_VAL      LOW

#endif