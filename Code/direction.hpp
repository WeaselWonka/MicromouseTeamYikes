
#ifndef DIRECTION
#define DIRECTION

// Defines the various directions one can have as integers
#define Up 0
#define Down 2
#define Left 3
#define Right 1

// Takes in <direction> and returns the direction 90 degrees to the right
short shiftClockwise(short direction);

// Takes in <direction> and returns the direction 90 degrees to the left
short shiftCounterClockwise(short direction);

#endif