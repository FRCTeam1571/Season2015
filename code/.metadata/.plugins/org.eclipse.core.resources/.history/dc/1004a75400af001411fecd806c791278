/*
 * DriveTrainSystem.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: acohen
 */

#include <Subsystems/DriveTrainSystem.h>

#include "../RobotMap.h"

DriveTrainSystem::DriveTrainSystem():
left(DriveTrainLeftVictorPort),
right(DriveTrainRightVictorPort),
drive(left, right),
gyro(0)
{

}

void DriveTrainSystem::setSpeed(double leftSpeed, double rightSpeed)
{

}

void DriveTrainSystem::setSpeed(Joystick* stick)
{
	drive->ArcadeDrive(stick);
}
