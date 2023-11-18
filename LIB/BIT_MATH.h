/*
 * BIT_MATH.h
 *
 *  Created on: Nov 20, 2022
 *      Author: MohamedAyman
 */

#ifndef CONF_BIT_MATH_H_
#define CONF_BIT_MATH_H_

#define SET_BIT(PORT,BIT) (PORT) |= (1<<BIT)
#define CLR_BIT(PORT,BIT) (PORT) &= ~(1<<BIT)
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)

#endif /* CONF_BIT_MATH_H_ */
