/*
 * Bit_Math.h
 *
 *  Created on: Dec 17, 2022
 *      Author: essam
 */

#ifndef LIBRARY_BIT_MATH_H_
#define LIBRARY_BIT_MATH_H_
/*---------------- SET BIT  -------------------*/
#define Set_Bit(var,bit)     (var |= (1<<bit))
/*---------------- TOGGLE BIT -------------------*/
#define Toggle_Bit(var,bit)  (var ^= (1<< bit))
/*---------------- CLEAR BIT -------------------*/
#define Clear_Bit(var,bit)   (var &=~ (1<< bit))
/*---------------- GET BIT -------------------*/
#define Get_Bit(var,bit)     ((var>>bit)&1)


#endif /* LIBRARY_BIT_MATH_H_ */
