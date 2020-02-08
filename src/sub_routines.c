/*
*	FILE			: sub_routines.c
*	PROJECT			: Littleroot - LTR-01
*	PROGRAMMER		: Daniel Pieczewski
*	FIRST VERSION	: 2020-02-08
*	DESCRIPTION		:
*		The function(s) in this file define small routines to be included in larger routines.
*       These can include moving motors or flashing LEDs etc.
*/

#include "littleroot.h"

/*
*	FUNCTION			: turnRight
*	DESCRIPTION			:
*		This function takes a Littleroot object and moves it's ailerons in a fashion that will tun the
*       plane right.
*
*	PARAMETERS			:
*		Littleroot* ltr : Object to perform action upon
*
*	RETURNS				:
*		void 			: void
*/
void turnRight(Littleroot *ltr) {
	//Send commands to the servos
	gpioServo(ltr->rightAileron.pinNumber, SERVO_MAX_CLOCKWISE);
	gpioServo(ltr->leftAileron.pinNumber, SERVO_MAX_COUNTER_CLOCKWISE);

	//Wait to allow the servos to reach the desired destination
	time_sleep(1);
}

/*
*	FUNCTION			: turnLeft
*	DESCRIPTION			:
*		This function takes a Littleroot object and moves it's ailerons in a fashion that will tun the
*       plane right.
*
*	PARAMETERS			:
*		Littleroot* ltr : Object to perform action upon
*
*	RETURNS				:
*		void 			: void
*/
void turnLeft(Littleroot *ltr) {
	//Send commands to the servos
	gpioServo(ltr->rightAileron.pinNumber, SERVO_MAX_COUNTER_CLOCKWISE);
	gpioServo(ltr->leftAileron.pinNumber, SERVO_MAX_CLOCKWISE);

	//Wait to allow the servos to reach the desired destination
	time_sleep(1);
}

/*
*	FUNCTION			: centre
*	DESCRIPTION			:
*		This function takes a Littleroot object and moves it's ailerons to flatten the plane
*
*	PARAMETERS			:
*		Littleroot* ltr : Object to perform action upon
*
*	RETURNS				:
*		void 			: void
*/
void centre(Littleroot *ltr) {
	//Send commands to the servos
	gpioServo(ltr->rightAileron.pinNumber, SERVO_MIDDLE);
	gpioServo(ltr->leftAileron.pinNumber, SERVO_MIDDLE);

	//Wait to allow the servos to reach the desired destination
	time_sleep(0.25);
}
