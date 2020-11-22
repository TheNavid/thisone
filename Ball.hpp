#ifndef Ball_H
#define Ball_H

#include "libanddif.hpp"

class Ball
{
public:
	void putInitialBall(Window *window);
	void drawBall(Window *window);
	int getX();
	int getY();
private:
	int xPosition;
	int yPosition;
	int acceleration;
	int VelocityX;
	int VelocityY;
	bool movingStatus;
};

#endif
