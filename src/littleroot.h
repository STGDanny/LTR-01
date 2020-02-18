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
#include <stdlib.h>
#include <string.h>

//Constants
#define LINE_MAX 81

#define GENERAL_ERROR_CODE -1

#define SERVO_MAX_CLOCKWISE   2500
#define SERVO_MIDDLE	      1500
#define SERVO_MAX_C_CLOCKWISE 500

//Data Structures
typedef struct Motor {
	uint8_t	 pinNumber;
	uint16_t maxValue;
	uint16_t minValue;
} Motor;

//Struct for the BMP-180 board
typedef struct BMP {
	uint8_t pinNumber;
} BMP;

typedef struct Aileron {
	uint8_t	 pinNumber;
	uint16_t maxValue;
	uint16_t minValue;
} Aileron;

typedef struct Buzzer {
	uint8_t pinNumber;
} Buzzer;

typedef struct Littleroot {
	Aileron leftAileron;
	Aileron rightAileron;
	Motor	mainMotor;
	Buzzer	buzzer;
	BMP	bmp;
} Littleroot;

//Shared Prototypes
int8_t init(Littleroot*);

//Sub-Routines
void turnRight(Littleroot*);
void turnLeft(Littleroot*);
void centre(Littleroot*);
void goUp(Littleroot*);
void goDown(Littleroot*);
void beepSpeaker(Littleroot*);
void twitchEngine(Littleroot*);

//Routines
void systemTest(Littleroot*);
