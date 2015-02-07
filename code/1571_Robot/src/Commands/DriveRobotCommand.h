/*
 * DriveRobotCommand.h
 *
 *  Created on: Feb 7, 2015
 *      Author: acohen
 */

#ifndef SRC_COMMANDS_DRIVEROBOTCOMMAND_H_
#define SRC_COMMANDS_DRIVEROBOTCOMMAND_H_

#include <CommandBase.h>

class DriveRobotCommand: public CommandBase {
private:
	double robotSpeed = 0;
	double robotRotation = 0;
public:
	DriveRobotCommand();

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	void Drive(double speed, double rotation);
};

#endif /* SRC_COMMANDS_DRIVEROBOTCOMMAND_H_ */
