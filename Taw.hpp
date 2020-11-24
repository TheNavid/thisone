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
	bool isStopped();
	float getVx();
	float getVy();

	void setX(int newX);
	void setY(int newY);


	void setNewSpeed(float newVx, float newVy);
private:
	bool isXInRange(int x, int y);
	bool isYInRange(int x, int y);
	float measureAbsolute(Point mousePosition);
	float measureInitialVelocityX (int mouseXPosition, float distanceAbsolute);
	float measureInitialVelocityY (int mouseYPosition, float distanceAbsolute);
	void calculateNewVelocity();
	float absoluteVelocity();
	void smashingToWall();

	float xPosition;
	float yPosition;
	float Vx;
	float Vy;
	string ID;
	int movingStatus;
};

#endif




