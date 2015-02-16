/*
 * DriveTrainSystem.h
 *
 *  Created on: Feb 2, 2015
 *      Author: acohen
 */

#ifndef SRC_SUBSYSTEMS_DRIVETRAINSUBSYSTEM_H_
#define SRC_SUBSYSTEMS_DRIVETRAINSUBSYSTEM_H_

#include <Commands/Subsystem.h>
#include <Victor.h>
#include <RobotDrive.h>

class DriveTrainSubsystem: public Subsystem {
private:
	Victor* LeftTop,* LeftBottom,* RightTop,* RightBottom;
	RobotDrive* drive;
public:
	DriveTrainSubsystem();
	void setSpeed(double speed, double rotation);
};

#endif /* SRC_SUBSYSTEMS_DRIVETRAINSUBSYSTEM_H_ */
