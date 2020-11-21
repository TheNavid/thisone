#ifndef Taw_H
#define Taw_H

#include "libanddif.hpp"

class Taw
{
public:
	Taw(int x, int y, string Id, Window* window);
	bool isChosenTaw(Point mousePosition);
	void calculateInitialVelocity(Point mousePosition);
private:
	bool isXInRange(int x);
	bool isYInRange(int y);
	float measureAbsolute(Point mousePosition);
	float measureInitialVelocityX (int mouseXPosition, float distanceAbsolute);
	float measureInitialVelocityY (int mouseYPosition, float distanceAbsolute);

	int xPosition;
	int yPosition;
	float acceleration;
	float initialVelocityX;
	float initialVelocityY;
	string ID;
	int movingStatus;
};

#endif