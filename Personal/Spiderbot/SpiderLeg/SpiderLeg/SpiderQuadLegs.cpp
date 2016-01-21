// 
// 
// 

#include "SpiderQuadLegs.h"

void SpiderQuadLegs::Attach(LegIndex leg, int joint0, int joint1, int joint2)
{

}

void SpiderQuadLegs::Init()
{
	// init all legs
	for (int i = 0; i < LegIndexCount; ++i)
	{
		legs[i].Init(); // they already goes to neutral
	}
	nextLegToStep = FrontLeft;
}

void SpiderQuadLegs::Step()
{
	// step one leg
	SpiderLegController* leg = &legs[nextLegToStep];

	// move the other 3 backward, except this one
	StepOtherLegsBackward(nextLegToStep);

	// change the next leg to move
	nextLegToStep = GetNextLegIndex(nextLegToStep);
}

void SpiderQuadLegs::Step(LegIndex leg)
{
	int waitTime = 50;

	SpiderLegController *pLeg = &legs[leg];

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

void SpiderQuadLegs::GoNeutral()
{
	nextLegToStep = FrontLeft;
	for (int i = 0; i < LegIndexCount; ++i)
	{
		legs[i].GoNeutral();
	}
}

SpiderLegController* SpiderQuadLegs::GetLeg(LegIndex leg)
{
	return &legs[leg];
}

void SpiderQuadLegs::StepOtherLegsBackward(LegIndex currentSteppingLeg)
{
}

SpiderQuadLegs::LegIndex SpiderQuadLegs::GetNextLegIndex(LegIndex currentLeg)
{
	LegIndex nextLeg = (LegIndex)(1 + (int)currentLeg);
	if (nextLeg == LegIndexCount)
	{
		// reset to the first leg
		nextLeg = FrontLeft;
	}
	return nextLeg;
}