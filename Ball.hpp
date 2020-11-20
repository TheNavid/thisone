#ifndef Ball_H
#define Ball_H

#include "libanddif.hpp"

class Ball
{
public:
	void putInitialBall(Window *window);
private:
	int xPosition;
	int yPosition;
	int acceleration;
	int initialVelocityX;
	int initialVelocityY;
	bool movingStatus;
};

#endif
