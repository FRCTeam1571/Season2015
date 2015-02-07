/*
 * DriveTrainSystem.h
 *
 *  Created on: Feb 2, 2015
 *      Author: acohen
 */

#ifndef SRC_SUBSYSTEMS_DRIVETRAINSYSTEM_H_
#define SRC_SUBSYSTEMS_DRIVETRAINSYSTEM_H_

#include <Commands/Subsystem.h>

#include <Gyro.h>
#include <RobotDrive.h>
#include <Victor.h>

class DriveTrainSystem: public Subsystem {
private:
	Talon* left,* right;
	RobotDrive* drive;
	Gyro* gyro;

	const double MaxSpeed = 5.0; //Temp
public:
	DriveTrainSystem();

	void setSpeed(double leftSpeed, double rightSpeed);
	void setSpeed(Joystick* stick);
};

#endif /* SRC_SUBSYSTEMS_DRIVETRAINSYSTEM_H_ */
