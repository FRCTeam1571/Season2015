/*
 * SetEncoderMotorPositionCommand.h
 *
 *  Created on: Feb 2, 2015
 *      Author: acohen
 */

#ifndef SRC_COMMANDS_SETENCODERMOTORPOSITIONCOMMAND_H_
#define SRC_COMMANDS_SETENCODERMOTORPOSITIONCOMMAND_H_

#include <CommandBase.h>

class SetEncoderMotorPositionCommand: public CommandBase {
private:
	double distanceToGo, distanceGone;
	double goal;
public:
	SetEncoderMotorPositionCommand();

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	void Set(double position);
};

#endif /* SRC_COMMANDS_SETENCODERMOTORPOSITIONCOMMAND_H_ */
