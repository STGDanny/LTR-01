#include <pigpio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

//Constants
#define LEFT_AILERON_PIN 6
#define RIGHT_AILERON_PIN 12
#define MOTOR_PIN 21

#define GENERAL_ERROR_CODE -1

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
int init(Littleroot *);
void turnRight(Littleroot *);
void turnLeft(Littleroot *);