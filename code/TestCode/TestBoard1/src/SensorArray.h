/*
 * SensorArray.h
 *
 *  Created on: Jan 12, 2015
 *      Author: acohen
 */

#include <cstdarg>
#include <vector>

#include <SensorBase.h>

#ifndef SRC_SENSORARRAY_H_
#define SRC_SENSORARRAY_H_

class SensorArray {
public:
	SensorArray(const char* label, int count...);
	virtual ~SensorArray();

	std::string name;
	std::vector<SensorBase>* sensors;
};

#endif /* SRC_SENSORARRAY_H_ */
