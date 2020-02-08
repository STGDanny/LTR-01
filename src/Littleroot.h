#include <pigpio.h>
#include <stdint.h>
#include <stdio.h>

//Constants

//Data types
typedef struct Motor {
	uint8_t pinNumber;

} Motor;

typedef struct Aileron {
	uint8_t pinNumber;
	uint16_t maxValue;
	uint16_t minValue;
} Aileron;

typedef struct Littleroot {
	Aileron leftAileron;
	Aileron rightAileron;
	Motor mainMotor;
} Littleroot;

//Prototypes