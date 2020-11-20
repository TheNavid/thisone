#ifndef Taw_H
#define Taw_H

#include "libanddif.hpp"

class Taw
{
public:
	Taw(int x, int y, string Id, Window* window);
	bool isChosenTaw(Point mousePosition);
private:
	bool isXInRange(int x);
	bool isYInRange(int y);

	int xPosition;
	int yPosition;
	int acceleration;
	int initialVelocityX;
	int initialVelocityY;
	string ID;
	int movingStatus;
};

#endif