#include "Littleroot.h"

void turnRight(Littleroot *ltr) {
	gpioServo(ltr->leftAileron.pinNumber, 500);
	gpioServo(ltr->rightAileron.pinNumber, 2500);

	time_sleep(1.5);
}

void turnLeft(Littleroot *ltr) {
	gpioServo(ltr->rightAileron.pinNumber, 500);
	gpioServo(ltr->leftAileron.pinNumber, 2500);

	time_sleep(1.5);
}