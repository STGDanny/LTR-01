#include "Littleroot.h"

int main(void) {
	//Initialize the Littleroot object
	Littleroot *ltr = {NULL};

	//Initialize the GPIO library
	if (init(ltr) == false) {
		return GENERAL_ERROR_CODE;
	}

	turnRight(ltr);
	printf("Everything worked!\n");

	//Kill the library and exit the program:
	gpioTerminate();
	return 0;
}