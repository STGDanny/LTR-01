#include "Littleroot.h"

void turnRight(Littleroot *ltr) {
	gpioServo(ltr->rightAileron.pinNumber, 2500);
	gpioServo(ltr->leftAileron.pinNumber, 500);

	time_sleep(1);
}

void turnLeft(Littleroot *ltr) {
	gpioServo(ltr->rightAileron.pinNumber, 500);
	gpioServo(ltr->leftAileron.pinNumber, 2500);

	time_sleep(1);
}

void centre(Littleroot *ltr) {
	gpioServo(ltr->rightAileron.pinNumber, 1500);
	gpioServo(ltr->leftAileron.pinNumber, 1500);

	time_sleep(0.25);
}

