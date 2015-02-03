/*
 * StateMachine.h
 *
 *  Created on: Jan 17, 2015
 *      Author: acohen
 */

#ifndef SRC_UTILS_STATEMACHINE_H_
#define SRC_UTILS_STATEMACHINE_H_

#include <cstdio>
#include "EventData.h"

struct StateStruct;

class StateMachine {
public:
	StateMachine(int maxStates);
	virtual ~StateMachine();
protected:
	enum{ EVENT_IGNORED = 0xfe, CANNOT_HAPPEN };
	unsigned char currentState;

	void ExternalEvent(unsigned char, EventData* = NULL);
	void InternalEvent(unsigned char, EventData* = NULL);
	virtual const StateStruct* GetStateMap() = 0;
private:
	const int _maxStates;
	bool _eventGenerated;
	EventData* _pEventData;

	void StateEngine(void);
};

#endif /* SRC_UTILS_STATEMACHINE_H_ */
