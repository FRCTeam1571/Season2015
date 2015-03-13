/*
 * EncoderMotorSubsystem.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: acohen
 */

#include <Subsystems/EncoderMotorSubsystem.h>

#include <cmath>

#include "../RobotMap.h"

EncoderMotorSubsystem::EncoderMotorSubsystem():
Subsystem("EncoderMotorSubsystem")
{
	builtin = new Encoder(EncoderMotorEncoderPortA, EncoderMotorEncoderPortB);
	motor = new Talon(EncoderMotorTalonPort);
	resetSwitch = new DigitalInput(EncoderMotorResetSwitchPort);

	zero();
}

void EncoderMotorSubsystem::update()
{
	double newDistance = builtin->Get() / GearRatio / DistancePerRevolution;

	distanceSinceLastUpdate = newDistance - distanceFromZero;
	distanceFromZero = -1 * newDistance * 4;
	SmartDashboard::PutNumber("Lift distance", distanceFromZero);
}

double EncoderMotorSubsystem::getDistance()
{
	return distanceFromZero;
}

EncoderMotorLiftPosition EncoderMotorSubsystem::nextPosition()
{
	EncoderMotorLiftPosition next;
	switch(position)
	{
	case ZERO:
		next = HALF_TOTE;
		break;
	case HALF_TOTE:
		next = FULL_TOTE;
		break;
	}

	return next;
}

EncoderMotorLiftPosition EncoderMotorSubsystem::lastPosition()
{
	EncoderMotorLiftPosition last;
	switch(position)
	{
	case ZERO:
		last = ZERO;
		break;
	case HALF_TOTE:
		last = ZERO;
		break;
	case FULL_TOTE:
		last = HALF_TOTE;
		break;
	}

	return last;
}

void EncoderMotorSubsystem::setDirection(int dir)
{
	if(fabs(dir) != 1 && dir != 0) {
		dir = fabs(dir) / dir;
	}
	motor->Set((RevolutionsPerMinute / MaxRevolutionsPerMinute) * dir);
}

void EncoderMotorSubsystem::zero()
{
	builtin->Reset();
	distanceFromZero = 0;
	position = ZERO;
}
