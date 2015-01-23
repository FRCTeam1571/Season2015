/*
 * QuadEncoder.h
 *
 *  Created on: Jan 22, 2015
 *      Author: acohen
 */

#ifndef SRC_UTILS_QUADENCODER_H_
#define SRC_UTILS_QUADENCODER_H_

#include <cstdint>
#include <sys/time.h>
#include <thread>
#include <future>

#include <DigitalInput.h>

namespace robot {

typedef enum { FORWARD, BACK } Direction;

class QuadEncoder {
public:
	QuadEncoder();
	virtual ~QuadEncoder();

	Direction getDirection();
	double getDistance();
private:
	timespec* ts;
	timespec* last_ts;

	DigitalInput A, B;
	std::thread run_thread;

	std::promise<Direction> directionPromise = std::promise<Direction>();
	auto directionFuture = directionPromise.get_future();

	std::promise<double> distancePromise = std::promise<double>();
	auto distanceFuture = distancePromise.get_future();

	void reset();

	void run();
	uint64_t GetElapsedTimeNanos();
};

} /* namespace robot */

#endif /* SRC_UTILS_QUADENCODER_H_ */
