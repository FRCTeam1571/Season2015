/*
 * MoveToteHolderCommand.h
 *
 *  Created on: Feb 16, 2015
 *      Author: acohen
 */

#ifndef SRC_COMMANDS_MOVETOTEHOLDERCOMMAND_H_
#define SRC_COMMANDS_MOVETOTEHOLDERCOMMAND_H_

#include <CommandBase.h>

class MoveToteHolderCommand: public CommandBase {
private:
	int direction = 0;
public:
	MoveToteHolderCommand();

	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();

	void Open();
	void Close();
};

#endif /* SRC_COMMANDS_MOVETOTEHOLDERCOMMAND_H_ */
