/*
 * UpdateEncoderMotorCommand.h
 *
 *  Created on: Feb 2, 2015
 *      Author: acohen
 */

#ifndef SRC_COMMANDS_UPDATEENCODERMOTORCOMMAND_H_
#define SRC_COMMANDS_UPDATEENCODERMOTORCOMMAND_H_

#include <CommandBase.h>

class UpdateEncoderMotorCommand: public CommandBase {
public:
	UpdateEncoderMotorCommand();

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_UPDATEENCODERMOTORCOMMAND_H_ */
