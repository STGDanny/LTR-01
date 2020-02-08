#include "Littleroot.h"

int main(void) {
	//Initialize the Littleroot object
	Littleroot ltr_01 = {NULL};

	//Initialize the GPIO library
	if (init(&ltr_01) == false) {
		return GENERAL_ERROR_CODE;
	}

	printf("Everything worked!\n");

	//Kill the library and exit the program:
	gpioTerminate();
	return 0;
}