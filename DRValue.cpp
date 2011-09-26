#include "DRValue.h"

void DeadReckoningValue::Reset()
{
	currentPos = stepPos = posAtUpdate = prevPos = oldPos = oldSpeed = nextPos = averageUpdateInterval = 0;
	lastUpdate = currentStep = timeDeltaIndex = numDeltas = 0;
	smoothing = speedOverride = 0;
	extrapolationMode = 0;
	doSpeedOverride = false;
	useAcceleration = false;
	wrapMode = WRAP_LINEAR;
	wrapValue = 0;
	for(int i=0; i<AVERAGEWINDOW; i++)
		timeDeltas[i]=0;
}

void DeadReckoningValue::UpdateValue(float newValue, long time)
{
	float speed;
	long timeDelta = time - lastUpdate;
	if(timeDelta == 0)
		return;

	//If the value is circular, map it down into a linear value
	if(wrapMode == WRAP_CIRCULAR)
	{
		diffAtUpdate = CircularDifference(newValue, oldPos, wrapValue);
		newValue = oldPos + diffAtUpdate;
	}
	else
		diffAtUpdate = newValue-oldPos;

	UpdateAverageInterval(timeDelta);

	if(!doSpeedOverride)
		speed = diffAtUpdate/timeDelta;
	else
	{
		speed = oldSpeed = speedOverride;
		doSpeedOverride = false;
	}
	
	//If the object changes direction
	if((speed>0 && oldSpeed<0) || (speed<0 && oldSpeed>0))
		oldSpeed = 0;

	if(useAcceleration)
	{
		float acceleration = speed - oldSpeed;

		float increaseFactor = 1.0f;
		//The increasefactor can kinda be seen as the acceleration of the acceleration.
		if(oldSpeed != 0)
			increaseFactor = CLAMP(speed/oldSpeed, 0.0f, 1.0f);
		else
			increaseFactor = 0;

		//Predict the next position
		nextPos = newValue + (speed + acceleration*increaseFactor) * averageUpdateInterval;
	}
	else
		nextPos = newValue + speed * averageUpdateInterval;
	
	//Store values for next update
	currentStep = 0;
	
	prevPos = oldPos;
	oldPos = newValue;
	
	lastUpdate = time;
	oldSpeed = speed;
	posAtUpdate = currentPos;
	timeDeltaIndex = (timeDeltaIndex+1) % AVERAGEWINDOW;
}

void DeadReckoningValue::SetValue(float value)
{
	currentPos = prevPos = posAtUpdate = stepPos = nextPos = oldPos = value;
}

void DeadReckoningValue::SetSpeed(float speed)
{
	//Recalculate movement
	doSpeedOverride = true;
	speedOverride = speed;
	oldPos = currentPos;
	nextPos = currentPos + speed * averageUpdateInterval;
}

void DeadReckoningValue::DoStep()
{
	long timespan = (long)averageUpdateInterval;
	if(currentStep >= timespan)
		return;

	currentStep++;

	float mu = 1.0f/averageUpdateInterval * currentStep;
	float secondGuess = nextPos + (nextPos-oldPos);

	switch(extrapolationMode)
	{
	case INTERPOLATION_CUBIC:
		stepPos = CubicInterpolation(prevPos, posAtUpdate, nextPos, secondGuess, mu);
		break;
	case INTERPOLATION_LINEAR:
		stepPos = posAtUpdate+(nextPos-posAtUpdate)*mu;
		break;
	}
	
	//Movement smoothing
	if(smoothing > 1)
		currentPos = currentPos + (stepPos-currentPos)/smoothing;
	else
		currentPos = stepPos;
}

float DeadReckoningValue::CubicInterpolation(float y0, float y1, float y2, float y3, float mu)
{
	float a0,a1,a2,a3,mu2;
	mu2 = mu*mu;
	a0 = y3 - y2 - y0 + y1;
	a1 = y0 - y1 - a0;
	a2 = y2 - y0;
	a3 = y1;
	return a0*mu*mu2+a1*mu2+a2*mu+a3;
}

void DeadReckoningValue::UpdateAverageInterval(long timeDelta)
{
	timeDeltas[timeDeltaIndex] = timeDelta;
	if(numDeltas < AVERAGEWINDOW)
		numDeltas++;

	averageUpdateInterval = 0;
	int maxLoop = MIN(AVERAGEWINDOW, numDeltas);
	for(int i=0; i<maxLoop; i++)
		averageUpdateInterval += timeDeltas[i];
	averageUpdateInterval /= maxLoop;
}

float DeadReckoningValue::CircularDifference(float angleA, float angleB, float wrapValue)
{
	float ret = fmod(angleA - angleB, wrapValue);
	float halfWrap = wrapValue / 2.0f;

	if(ret >= halfWrap)
		return ret-wrapValue;
	else if(ret < -halfWrap)
		return ret+wrapValue;
	else
		return ret;
}


	
void DRObj::Reset()
{
	fixedValue = 0;
	previousAngle = 0.0f;
	oldX = oldY = 0;
	xPosition.Reset();
	yPosition.Reset();
	direction.Reset();
	angle.Reset();
}
