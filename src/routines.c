#include "Littleroot.h"

void cycleMotors(Littleroot *ltr) {
	centre(&ltr);
	turnRight(&ltr);
	turnLeft(&ltr);
	centre(&ltr);
}