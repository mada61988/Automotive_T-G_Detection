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
#define GET_AVERAGE(val,t)  (val = val/t) 
#define ROR(REG,NUM) (REG = ((REG >> NUM) | (REG << (8-NUM))))
#define ROL(REG,NUM) (REG = ((REG << NUM) | (REG >> (8-NUM))))
#define Bit_Is_Set(REG,BIT) (REG & (1<<BIT))
#define Bit_Is_Clear(REG,BIT) (!(REG & (1<<BIT)))

#endif /* CONF_BIT_MATH_H_ */
