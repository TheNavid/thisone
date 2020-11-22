#ifndef Taw_H
#define Taw_H

#include "libanddif.hpp"

class Taw
{
public:
	Taw(int x, int y, string Id, Window* window);
	bool isChosenTaw(Point mousePosition);
	void calculateInitialVelocity(Point mousePosition);
	string getID();
	void printInfo();
	void drawTaw(Window* window);
	void updatePosition();
	int getX();
	int getY();
private:
	bool isXInRange(int x, int y);
	bool isYInRange(int x, int y);
	float measureAbsolute(Point mousePosition);
	float measureInitialVelocityX (int mouseXPosition, float distanceAbsolute);
	float measureInitialVelocityY (int mouseYPosition, float distanceAbsolute);
	void calculateNewVelocity();
	float absoluteVelocity();
	bool isStopped();
	void smashingToTopWall();

	int xPosition;
	int yPosition;
	float Vx;
	float Vy;
	string ID;
	int movingStatus;
};

#endif