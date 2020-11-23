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
	int getVx();
	int getVy();
	void updatePosition();
	bool isStopped();
	void setNewSpeed(float newVx, float newVy);
private:
	void smashingToWall();
	void calculateNewVelocity();
	float absoluteVelocity();

	int xPosition;
	int yPosition;
	int Vx;
	int Vy;
	bool movingStatus;
};

#endif
