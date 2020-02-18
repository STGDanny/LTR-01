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
	Littleroot ltr = {0};

	//Initialize the GPIO library
	//IF init returns false:
	if (init(&ltr) == false) {
		//Return error code and exit program
		return GENERAL_ERROR_CODE;
	}

	//Test all motors before running any further routines
	systemTest(&ltr);

	//Run routines below

	//Kill the library and exit the program:
	gpioTerminate();
	printf("Exiting Gracefully!\n");
	return 0;
}
