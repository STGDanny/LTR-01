/*
*	FILE			: routines.c
*	PROJECT			: Littleroot - LTR-01
*	PROGRAMMER		: Daniel Pieczewski
*	FIRST VERSION	: 2020-02-08
*	DESCRIPTION		:
*		The function(s) in this file define over-arching routines to be called during flight 
*/

#include "../littleroot.h"

/*
*	FUNCTION			: cycleMotors
*	DESCRIPTION			:
*		This function takes a Littleroot object and calls sub-routines to perform a sequence 
*       of aileron movements.
*
*	PARAMETERS			:
*		Littleroot* ltr : Object to perform action upon
*
*	RETURNS				:
*		void 			: void
*/
void cycleMotors(Littleroot* ltr) {
	twitchEngine(ltr);
	centre(ltr);
	turnRight(ltr);
	turnLeft(ltr);
	centre(ltr);
	for (int i = 0; i < 5; i++) {
		beepSpeaker(ltr);
	}
}
