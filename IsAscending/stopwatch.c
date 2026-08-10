/**
 * Simple stopwatch object that can 
 * be used to measure the elapsed
 * time for parts of a program's 
 * execution.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stopwatch.h"


// Macro to get a time stamp for timespec value x
#define TIME_STAMP(x) if (timespec_get(x, TIME_UTC) != TIME_UTC) { \
    fprintf(stderr, "Error getting start time.\n"); \
    exit(EXIT_FAILURE); \
}
    

// Resets the stopwatch object in preparation for a new timing.
void sw_reset(struct stopwatch *sw) {
	sw->is_running = 0;
    sw->elapsed_time = 0.0;
}

/** Starts the stopwatch running. */
void sw_start(struct stopwatch *sw) {
	if (!sw->is_running) {
		sw->is_running = 1;
        TIME_STAMP(&sw->start_time);
	}
}

/** 
 * Stops the stopwatch; the stopwatch later may be resumed, 
 * but the time while stopped is not counted.
 */
void sw_stop(struct stopwatch *sw) {
	if (sw->is_running) {
        TIME_STAMP(&sw->stop_time);
        double elapsed = (double)(sw->stop_time.tv_sec - sw->start_time.tv_sec) +
                         (double)(sw->stop_time.tv_nsec - sw->start_time.tv_nsec) / 1000000000.0;
		sw->elapsed_time += elapsed;
		sw->is_running = 0;
	}
}

/** Returns the stopwatch's elapsed time in seconds. */
double sw_elapsed(const struct stopwatch *sw) {
	if (!sw->is_running)
		return sw->elapsed_time;
	else
		return -1.0;  // Stop the timer before reading it
}

