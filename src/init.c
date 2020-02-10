/*
*	FILE			: init.c
*	PROJECT			: Littleroot - LTR-01
*	PROGRAMMER		: Daniel Pieczewski
*	FIRST VERSION	: 2020-02-08
*	DESCRIPTION		:
*		The function(s) in this file set up and initialise pins on a raspberry pi for use with the project
*/

#include "littleroot.h"

//Local prototypes
void setPins(Littleroot*);

/*
*	FUNCTION			: init
*	DESCRIPTION			:
*		This function takes a Littleroot object and initialises all needed GPIO pins / performs mode setting
*
*	PARAMETERS			:
*		Littleroot* ltr : Object to initialise / set the modes of
*
*	RETURNS				:
*		int 			: Integer value representing a status code
*/
int init(Littleroot* ltr) {
	//Initialize the GPIO library
	if (gpioInitialise() < 0) {
		printf("Failure at gpioInitialise()!");
		return false;
	}

	//Set all the pin numbers
	setPins(ltr);

	//Set the pin modes
	if (gpioSetMode(LEFT_AILERON_PIN, PI_OUTPUT) != 0) {
		printf("Error at pin %d\n", LEFT_AILERON_PIN);
		return false;
	}

	if (gpioSetMode(RIGHT_AILERON_PIN, PI_OUTPUT) != 0) {
		printf("Error at pin %d\n", RIGHT_AILERON_PIN);
		return false;
	}

	if (gpioSetMode(MOTOR_PIN, PI_OUTPUT) != 0) {
		printf("Error at pin %d\n", MOTOR_PIN);
		return false;
	}

	//Everything was ok:
	return true;
}

/*
*	FUNCTION			: setPins
*	DESCRIPTION			:
*		This function takes a Littleroot object and sets the pin number fields accordingly
*
*	PARAMETERS			:
*		Littleroot* ltr : Object to set pin numbers
*
*	RETURNS				:
*		void 			: void
*/
void setPins(Littleroot* ltr) {
	ltr->leftAileron.pinNumber = LEFT_AILERON_PIN;
	ltr->rightAileron.pinNumber = RIGHT_AILERON_PIN;
	ltr->mainMotor.pinNumber = MOTOR_PIN;
}
