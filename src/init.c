#include "Littleroot.h"

//Local prototypes
void setPins(Littleroot *);

int init(Littleroot *ltr) {
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

void setPins(Littleroot *ltr) {
	ltr->leftAileron.pinNumber = LEFT_AILERON_PIN;
	ltr->rightAileron.pinNumber = RIGHT_AILERON_PIN;
	ltr->mainMotor.pinNumber = MOTOR_PIN;
}
