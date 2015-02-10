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
	controller = new Talon(EncoderMotorTalonPort);
}

void EncoderMotorSubsystem::update()
{
	double newDistance = builtin->Get() / GearRatio / DistancePerRevolution;

	if(newDistance < 0) {
		setSpeed(0.0);
		zero();
	}

	distanceSinceLastUpdate = newDistance - distanceFromZero;
	distanceFromZero = newDistance;
}

double EncoderMotorSubsystem::getDistance()
{
	return distanceFromZero;
}

void EncoderMotorSubsystem::setSpeed(double newSpeed, bool isNormalized)
{
	if(!isNormalized) {
		newSpeed = fmin((newSpeed * 60) / DistancePerRevolution / RevolutionsPerMinute, 1.0);
	}

	controller->Set(newSpeed * (RevolutionsPerMinute / MaxRevolutionsPerMinute));
}

void EncoderMotorSubsystem::zero()
{
	builtin->Reset();
	distanceFromZero = 0;
}
