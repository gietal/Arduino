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

SpiderLegController legs[4];

// the setup function runs once when you press reset or power the board

void SetFrontRight(SpiderLegController *pLeg)
{
	// right leg 
	pLeg->SetDownDegree(0, 130);
	pLeg->SetNeutralDegree(0, 90);
	pLeg->SetUpDegree(0, 50);

	pLeg->SetDownDegree(1, 180);
	pLeg->SetNeutralDegree(1, 90);
	pLeg->SetUpDegree(1, 40);

	pLeg->SetDownDegree(2, 20);
	pLeg->SetNeutralDegree(2, 50);
	pLeg->SetUpDegree(2, 140);
}

void SetBackRight(SpiderLegController *pLeg)
{
	// right leg 
	pLeg->SetDownDegree(0, 30);
	pLeg->SetNeutralDegree(0, 80);
	pLeg->SetUpDegree(0, 120);

	pLeg->SetDownDegree(1, 180);
	pLeg->SetNeutralDegree(1, 60);
	pLeg->SetUpDegree(1, 40);

	pLeg->SetDownDegree(2, 20);
	pLeg->SetNeutralDegree(2, 50);
	pLeg->SetUpDegree(2, 140);
}

void SetFrontLeft(SpiderLegController *pLeg)
{
	pLeg->SetDownDegree(0, 120);
	pLeg->SetNeutralDegree(0, 80);
	pLeg->SetUpDegree(0, 50);

	pLeg->SetDownDegree(1, 80);
	pLeg->SetNeutralDegree(1, 100);
	pLeg->SetUpDegree(1, 150);

	pLeg->SetDownDegree(2, 90);
	pLeg->SetNeutralDegree(2, 50);
	pLeg->SetUpDegree(2, 0);
}

void SetBackLeft(SpiderLegController *pLeg)
{
	pLeg->SetDownDegree(0, 120);
	pLeg->SetNeutralDegree(0, 70);
	pLeg->SetUpDegree(0, 50);

	pLeg->SetDownDegree(1, 80);
	pLeg->SetNeutralDegree(1, 90);
	pLeg->SetUpDegree(1, 150);

	pLeg->SetDownDegree(2, 100);
	pLeg->SetNeutralDegree(2, 90);
	pLeg->SetUpDegree(2, 0);
}
void setup() 
{
	legs[0].Attach(2, 3, 4); // front left
	legs[1].Attach(5, 6, 7); // back left
	legs[2].Attach(8, 9, 10); // back right 
	legs[3].Attach(11, 12, 13); // front right

	SetFrontLeft(legs + 0);
	SetBackLeft(legs + 1);
	SetBackRight(legs + 2);
	SetFrontRight(legs + 3);

	//leg.GoNeutral();
	//delay(1000);
	//
	//leg.GoUp(1);
	//leg.GoDown(2);
	//delay(1000);
	//delay(1000);
	//leg.GoDown();

	for (int i = 0; i < 4; ++i)
		legs[i].Init();
	delay(500);

	

	//// opening
	//leg.GotoAngle(0, 30);
	//delay(500);
	//leg.GotoAngle(1, 0);
	//delay(500);
	//for (int i = 0; i < 2; ++i)
	//{
	//	leg.GotoAngle(2, 150);
	//	delay(100);
	//	leg.GotoAngle(2, 20);
	//	delay(100);
	//}
	//leg.GoNeutral(2);
	//leg.GoNeutral();
	//delay(1000);
	//WalkCycle();
	//leg.Init();
	//delay(500);
	//leg.GoUp();
	//delay(500);
	//leg.GoNeutral(2);
	//leg.GoNeutral(1);
	
	for (int i = 0; i < 4; ++i)
	{
		WalkCycle(legs + i);
		delay(100);
	}
}
// the loop function runs over and over again until power down or reset
void loop()
{
	//for (int i = 0; i < 4; ++i)
	//{
	//	WalkCycle(legs + i);
	//	delay(100);
	//}
}

// blocking synchronous walk cycle
void WalkCycle(SpiderLegController *pLeg)
{
	int waitTime = 50;

	// horizonta axis go back
	pLeg->GoDown(0);
	delay(waitTime);

	// vertical axis go up
	pLeg->GoUp(1);
	delay(waitTime);

	// horizontal axis go forward
	pLeg->GoUp(0);
	delay(waitTime);

	// vertical axis go down
	pLeg->GoNeutral(1);
	delay(waitTime);
}


