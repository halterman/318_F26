#ifndef RANDRANGE_H_DEFINED
#define RANDRANGE_H_DEFINED

// Initializes the random number genertor
void init_rand(unsigned long long seed);

// Initializes the random number genertor from system time
void randomize(void);

// Returns a pseudorandom integer in the range 
// begin...end - 1, inclusive
int randrange(int begin, int end);

#endif


