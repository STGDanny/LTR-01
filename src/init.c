/*
*	FILE			: init.c
*	PROJECT			: Littleroot - LTR-01
*	PROGRAMMER		: Daniel Pieczewski
*	FIRST VERSION	: 2020-02-08
*	DESCRIPTION		:
*		The function(s) in this file set up and initialise pins on a raspberry pi for use with the project
*/

#include "littleroot.h"

//Local prototypes
int8_t setPins(Littleroot*);

/*
*	FUNCTION			: init
*	DESCRIPTION			:
*		This function takes a Littleroot object and initialises all needed GPIO pins / performs mode setting
*
*	PARAMETERS			:
*		Littleroot* ltr : Object to initialise / set the modes of
*
*	RETURNS				:
*		int 			: Integer value representing a status code
*/
int8_t init(Littleroot* ltr) {
	//Initialize the GPIO library
	if (gpioInitialise() < 0) {
		printf("Failure at gpioInitialise()!");
		return false;
	}

	//Set all the pin numbers
	if (!setPins(ltr)) {
		return false;
	}

	//Set the pin modes
	if (gpioSetMode(ltr->leftAileron.pinNumber, PI_OUTPUT) != 0) {
		printf("Error at pin %d\n", LEFT_AILERON_PIN);
		return false;
	}

	if (gpioSetMode(ltr->rightAileron.pinNumber, PI_OUTPUT) != 0) {
		printf("Error at pin %d\n", RIGHT_AILERON_PIN);
		return false;
	}

	if (gpioSetMode(ltr->mainMotor.pinNumber, PI_OUTPUT) != 0) {
		printf("Error at pin %d\n", MOTOR_PIN);
		return false;
	}

	//Everything was ok:
	return true;
}

/*
*	FUNCTION			: setPins
*	DESCRIPTION			:
*		This function takes a Littleroot object and sets the pin number fields accordingly
*
*	PARAMETERS			:
*		Littleroot* ltr : Object to set pin numbers
*
*	RETURNS				:
*		void 			: void
*/
int8_t setPins(Littleroot* ltr) {
	//Set up file pointer and required variables
	FILE* configFile = NULL;
	char currentLine[LINE_MAX] = {0};

	//TODO: Figure out how to use fopen_s()
	//Open file
	//IF fopen fails:
	if (fopen("../config.txt", "r") == NULL) {
		printf("File I/O issue");
		return false;
	}

	//Get lines of text from the file
	while (fgets(currentLine, LINE_MAX, configFile) != NULL) {
		//Create temp variables
		char* key = (char*)calloc(strlen(currentLine), sizeof(char));
		int8_t value = 0;

		//sscanf_s the values in the file into the above variables
		sscanf_s(LINE_MAX, "%s %d", &key, &value);

		//IF the text in the file matches a valid key:
		//Set the object values accordingly
		if (strcmp(key, "LEFT_AILERON_PIN") == 0) {
			ltr->leftAileron.pinNumber = value;
		} else if (strcmp(key, "RIGHT_AILERON_PIN") == 0) {
			ltr->rightAileron.pinNumber = value;
		} else if (strcmp(key, "MOTOR_AILERON_PIN") == 0) {
			ltr->mainMotor.pinNumber = value;
		}
		free(key);
	}
	//Close the file and return true
	fclose(configFile);
	return true;
}
