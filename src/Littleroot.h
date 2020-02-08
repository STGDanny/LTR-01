/*
*	FILE			: littleroot.h
*	PROJECT			: Littleroot - LTR-01
*	PROGRAMMER		: Daniel Pieczewski
*	FIRST VERSION	: 2020-02-08
*	DESCRIPTION		:
*		This header file defines the data types to model the plane along with containing constants and 
*       shared function prototypes
*/

#include <pigpio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

//Constants
#define LEFT_AILERON_PIN 6
#define RIGHT_AILERON_PIN 12
#define MOTOR_PIN 21

#define GENERAL_ERROR_CODE -1

#define SERVO_MAX_CLOCKWISE 2500
#define SERVO_MIDDLE 1500
#define SERVO_MAX_COUNTER_CLOCKWISE 500

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

//Shared Prototypes
int init(Littleroot *);

//Sub-Routines
void turnRight(Littleroot *);
void turnLeft(Littleroot *);
void centre(Littleroot *);

//Routines
void cycleMotors(Littleroot *);