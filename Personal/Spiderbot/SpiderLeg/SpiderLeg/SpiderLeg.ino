/*
 Name:		SpiderLeg.ino
 Created:	1/4/2016 9:13:27 PM
 Author:	GIETA
*/

#include "SpiderLegController.h"
#include <Servo.h>

//Servo joint0;
//int joint0Pin = 9;
//int joint0Down = 180;
//int joint0Neutral = 90;
//int joint0Up = 45;
//
//Servo joint1;
//int joint1Pin = 10;
//int joint1Down = 0;
//int joint1Neutral = 30;
//int joint1Up = 140;

SpiderLegController leg;

// the setup function runs once when you press reset or power the board
void setup() 
{
	leg.Attach(3, 9, 10);

	leg.SetDownDegree(1, 180);
	leg.SetNeutralDegree(1, 90);
	leg.SetUpDegree(1, 40);

	leg.SetDownDegree(2, 20);
	leg.SetNeutralDegree(2, 40);
	leg.SetUpDegree(2, 140);

	//leg.GoNeutral();
	//delay(1000);
	//
	//leg.GoUp(1);
	//leg.GoDown(2);
	//delay(1000);
	//delay(1000);
	//leg.GoDown();

	leg.Init();
	delay(500);
	leg.GoUp();
	delay(500);
	leg.GoNeutral(2);
	leg.GoNeutral(1);
}

void Logic()
{
	leg.GoNeutral();
	delay(1000);

	leg.GoUp(1);
	leg.GoDown(2);
	delay(500);

	leg.GoUp(2);
	delay(500);
	leg.GoNeutral(2);
	delay(500);

	leg.GoNeutral();
	delay(1000);
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	
}
