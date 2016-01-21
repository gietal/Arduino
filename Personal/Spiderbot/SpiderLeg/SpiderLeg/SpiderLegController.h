// SpiderLegController.h

#ifndef _SPIDERLEGCONTROLLER_h
#define _SPIDERLEGCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Servo.h>

class Servo;

class SpiderLegController
{
public:
	static int ALL_JOINTS;

	SpiderLegController();

	void Attach(int horizontalJointPin, int verticalJoint1Pin, int verticalJoint2Pin);
	//void SetPin(int index, int pin);

	void Init();

	// setters
	void SetDownDegree(int index, int degree);
	void SetNeutralDegree(int index, int degree);
	void SetUpDegree(int index, int degree);

	// movers
	void GoNeutral(int index = ALL_JOINTS);
	void GoUp(int index = ALL_JOINTS);
	void GoDown(int index = ALL_JOINTS);
	void GotoAngle(int index, int target);
private:
	
	struct Joint
	{
		Servo servo;
		int pin;
		int current = 0;
		int down = 0;
		int neutral = 90;
		int up = 180;
	};

	Joint joints[3];

	
};

#endif

