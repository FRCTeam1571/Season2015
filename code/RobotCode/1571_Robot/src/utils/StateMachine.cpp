/*
 * StateMachine.cpp
 *
 *  Created on: Jan 17, 2015
 *      Author: acohen
 */

#include <cassert>
#include "utils/StateMachine.h"

StateMachine::StateMachine(int maxStates):
	currentState(0),

	_maxStates(maxStates),
	_eventGenerated(false),
	_pEventData(NULL)
	{};

StateMachine::~StateMachine() {
	// TODO Auto-generated destructor stub
}

