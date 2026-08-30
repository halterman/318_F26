#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include <time.h>

// Simple stopwatch object that can be used to measure 
// the elapsed time for parts of a program's  execution.
struct stopwatch {
	// The time the stopwatch started.
	struct timespec start_time;
	// The time the stopwatch stopped.
	struct timespec stop_time;
	// The elapsed time that the stopwatch has been running.
	double elapsed_time;
	// Indicates the stopwatch's current running state.
	bool is_running;
};


// Stopwatch interface

// Resets the stopwatch object in preparation for a new timing.
void sw_reset(struct stopwatch *sw);

// Starts the stopwatch running.
void sw_start(struct stopwatch *sw);

 // Stops the stopwatch; the stopwatch later may be resumed, 
 // but the time while stopped is not counted.
void sw_stop(struct stopwatch *sw);

// Returns the stopwatch's elapsed time in seconds.
double sw_elapsed(const struct stopwatch *sw);

#endif

