/*
 *         Name :Platform_Types.h
 *
 *          Date: Nov 20, 2022
 *        Author: MohamedAymanShokry
 */

#ifndef CONF_PLATFORM_TYPS_H_
#define CONF_PLATFORM_TYPS_H_

typedef unsigned short int      uint16;
typedef unsigned long int       uint32;
typedef unsigned char           uint8 ;
typedef signed char             sint8;

#define E_OK                       0 
#define E_NOK                      1
#define NULL                      255

#define TDM                         0
#define GDM                         1


//Platform STATE
#define IDLE        0
#define WARNING     1
#define DANGER      2


#endif /* CONF_STD_TYPS_H_ */
