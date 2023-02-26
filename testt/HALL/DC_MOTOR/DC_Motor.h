/*
 * DC_Motor.h
 *
 *  Created on: Dec 17, 2022
 *      Author: essam
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "..\..\HALL\DC_MOTOR\DC_Motor_CFG.h"

typedef enum
{
	Clock_Wise,
	Anti_Clock_Wise
	}DC_Motor_Dir; //////////////motor rotation direction

/*DC_Motor1&2 Functions prototype*/
void DC_Motors_INIT(void);

void DC_Motor1_START(Uint16 speed, DC_Motor_Dir dir);

void DC_Motor2_START(Uint16 speed, DC_Motor_Dir dir);

/*DC_Movement Functions prototype*/
void DC_Forward(void);

void DC_STOP(void);

void DC_Rot_Left(Uint16 angle);

void DC_Rot_Right(Uint16 angle);

void DC_Rot_180(void);



#endif /* DC_MOTOR_H_ */
