// SpideQuadLegs.h

#ifndef _SPIDERQUADLEGS_h
#define _SPIDERQUADLEGS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "SpiderLegController.h"
class SpiderQuadLegs
{
public:
	enum LegIndex
	{
		FrontLeft = 0,
		BackRight,
		BackLeft,
		FrontRight,
		LegIndexCount
	};

	void Attach(LegIndex leg, int joint0, int joint1, int joint2);
	void Init();

	// step once
	void Step();

	void GoNeutral();

	SpiderLegController* GetLeg(LegIndex leg);

private:
	void Step(LegIndex leg);
	void StepOtherLegsBackward(LegIndex currentSteppingLeg);

	LegIndex GetNextLegIndex(LegIndex currentLeg);

	LegIndex nextLegToStep;

	SpiderLegController legs[LegIndexCount];

	
};

#endif

