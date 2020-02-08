/*
*	FILE			: LTR_01.c
*	PROJECT			: Littleroot - LTR-01
*	PROGRAMMER		: Daniel Pieczewski
*	FIRST VERSION	: 2020-02-08
*	DESCRIPTION		:
*		The function(s) in this file act as a testing platform for the project including main()
*/

#include "littleroot.h"

int main(void) {
	//Initialize the Littleroot object
	Littleroot ltr = {NULL};

	//Initialize the GPIO library
	//IF init returns false:
	if (init(&ltr) == false) {
		//Return error code and exit program
		return GENERAL_ERROR_CODE;
	}

	//Test all motors
	cycleMotors(&ltr);

	//Kill the library and exit the program:
	gpioTerminate();
	printf("Exiting Gracefully!\n");
	return 0;
}
