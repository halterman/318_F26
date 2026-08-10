#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include <time.h>

// Simple stopwatch object that can be used to measure 
// the elapsed time for parts of a program's  execution.
typedef struct stopwatch {
	// The time the stopwatch started.
	struct timespec start_time;
	// The time the stopwatch stopped.
	struct timespec stop_time;
	// The elapsed time that the stopwatch has been running.
	double elapsed_time;
	// Indicates the stopwatch's current running state.
	int is_running;
} Stopwatch;


// Stopwatch interface

// Resets the stopwatch object in preparation for a new timing.
void sw_reset(Stopwatch *sw);

// Starts the stopwatch running.
void sw_start(Stopwatch *sw);

 // Stops the stopwatch; the stopwatch later may be resumed, 
 // but the time while stopped is not counted.
void sw_stop(Stopwatch *sw);

// Returns the stopwatch's elapsed time in seconds.
double sw_elapsed(const Stopwatch *sw);

#endif

