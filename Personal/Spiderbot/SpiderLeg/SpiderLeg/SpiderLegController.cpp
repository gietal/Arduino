// 
// 
// 
#include "SpiderLegController.h"
#include <Servo.h>

int SpiderLegController::ALL_JOINTS = -1;

SpiderLegController::SpiderLegController()
{
	// set default values
	for (int i = 0; i < 3; ++i)
	{
		SetDownDegree(i, 0);
		SetNeutralDegree(i, 90);
		SetUpDegree(i, 180);
	}
}

void SpiderLegController::Attach(int horizontalJointPin, int verticalJoint1Pin, int verticalJoint2Pin)
{
	joints[0].pin = horizontalJointPin;
	joints[1].pin = verticalJoint1Pin;
	joints[2].pin = verticalJoint2Pin;

	// attach all servos
	for (int i = 0; i < 3; ++i)
	{
		joints[i].servo.attach(joints[i].pin);
	}
}

void SpiderLegController::Init()
{
	for (int i = 0; i < 3; ++i)
	{
		joints[i].current = joints[i].neutral;
		joints[i].servo.write(joints[i].current);
	}
}

void SpiderLegController::SetDownDegree(int index, int degree)
{
	if (index < 0 || index > 2)
		return;
	joints[index].down = degree;
}

void SpiderLegController::SetNeutralDegree(int index, int degree)
{
	if (index < 0 || index > 2)
		return;
	joints[index].neutral = degree;
}

void SpiderLegController::SetUpDegree(int index, int degree)
{
	if (index < 0 || index > 2)
		return;
	joints[index].up = degree;
}

void SpiderLegController::GoNeutral(int index )
{
	if (index == ALL_JOINTS)
	{
		for (int i = 0; i < 3; ++i)
		{
			GotoAngle(i, joints[i].neutral);
		}
		return;
	}
	if (index < 0 || index > 2)
		return;


	GotoAngle(index, joints[index].neutral);

}

void SpiderLegController::GoUp(int index)
{
	if (index == ALL_JOINTS)
	{
		for (int i = 0; i < 3; ++i)
		{
			GotoAngle(i, joints[i].up);
		}
	}
	if (index < 0 || index > 2)
		return;

	GotoAngle(index, joints[index].up);
}

void SpiderLegController::GoDown(int index)
{
	if (index == ALL_JOINTS)
	{
		for (int i = 0; i < 3; ++i)
		{
			GotoAngle(i, joints[i].down);
		}
	}
	if (index < 0 || index > 2)
		return;

	GotoAngle(index, joints[index].down);
}

void SpiderLegController::GotoAngle(int index, int target)
{
	// directly go to angle
	if (index < 0 || index > 2)
		return;

	Joint *j = &joints[index];
	// save current angle
	//j->current = angle;

	// write angle directly
	//j->servo.write(angle);
	

	// go step by step (blocking)
	int stepAngle = 5;
	int waitTime = 20;
	bool flip = target - j->current < 0;
	if (!flip)
	{
		while (j->current < target)
		{
			j->current += stepAngle;
			j->servo.write(j->current);
			delay(waitTime);
		}
		j->current = target;
		j->servo.write(target);
	}
	else
	{
		while (j->current > target)
		{
			j->current -= stepAngle;
			j->servo.write(j->current);
			delay(waitTime);
		}
		j->current = target;
		j->servo.write(target);
	}


	
}


