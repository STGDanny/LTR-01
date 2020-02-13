/*
*	FILE			: sub_routines.c
*	PROJECT			: Littleroot - LTR-01
*	PROGRAMMER		: Daniel Pieczewski
*	FIRST VERSION	: 2020-02-08
*	DESCRIPTION		:
*		The function(s) in this file define small routines to be included in larger routines.
*       These can include moving motors or flashing LEDs etc.
*/

#include "../littleroot.h"

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
void turnRight(Littleroot* ltr) {
	//Send commands to the servos
	gpioServo(ltr->rightAileron.pinNumber, SERVO_MAX_COUNTER_CLOCKWISE);
	gpioServo(ltr->leftAileron.pinNumber, SERVO_MAX_CLOCKWISE);

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
void turnLeft(Littleroot* ltr) {
	//Send commands to the servos
	gpioServo(ltr->rightAileron.pinNumber, SERVO_MAX_CLOCKWISE);
	gpioServo(ltr->leftAileron.pinNumber, SERVO_MAX_COUNTER_CLOCKWISE);

	//Wait to allow the servos to reach the desired destination
	time_sleep(1);
}

/*
*	FUNCTION			: goUp
*	DESCRIPTION			:
*		This function takes a Littleroot object and moves it's ailerons to increase it's height
*
*	PARAMETERS			:
*		Littleroot* ltr : Object to perform action upon
*
*	RETURNS				:
*		void 			: void
*/
void goUp(Littleroot* ltr) {
	//Send commands to the servos
	gpioServo(ltr->rightAileron.pinNumber, SERVO_MAX_CLOCKWISE);
	gpioServo(ltr->leftAileron.pinNumber, SERVO_MAX_CLOCKWISE);

	//Wait to allow the servos to reach the desired destination
	time_sleep(1);
}

/*
*	FUNCTION			: goDown
*	DESCRIPTION			:
*		This function takes a Littleroot object and moves it's ailerons to decrease it's height
*
*	PARAMETERS			:
*		Littleroot* ltr : Object to perform action upon
*
*	RETURNS				:
*		void 			: void
*/
void goDown(Littleroot* ltr) {
	//Send commands to the servos
	gpioServo(ltr->rightAileron.pinNumber, SERVO_MAX_COUNTER_CLOCKWISE);
	gpioServo(ltr->leftAileron.pinNumber, SERVO_MAX_COUNTER_CLOCKWISE);

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
void centre(Littleroot* ltr) {
	//Send commands to the servos
	gpioServo(ltr->rightAileron.pinNumber, SERVO_MIDDLE);
	gpioServo(ltr->leftAileron.pinNumber, SERVO_MIDDLE);

	//Wait to allow the servos to reach the desired destination
	time_sleep(0.25);
}

/*
*	FUNCTION			: twitchEngine
*	DESCRIPTION			:
*		This function takes a Littleroot object and moves it's engine to test
*
*	PARAMETERS			:
*		Littleroot* ltr : Object to perform action upon
*
*	RETURNS				:
*		void 			: void
*/
void twitchEngine(Littleroot* ltr) {
	//Loop three times
	for (int i = 0; i < 3; i++) {
		//Power engine at 1 out of a possible 255
		gpioPWM(ltr->mainMotor.pinNumber, 1);
		time_sleep(0.25);
		//Turn off motor
		gpioPWM(ltr->mainMotor.pinNumber, 0);
	}
}