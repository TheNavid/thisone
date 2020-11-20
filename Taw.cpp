#include "Taw.hpp"


Taw::Taw(int x, int y, string Id, Window* window)
	{
		xPosition = x;
		yPosition = y;
		ID = Id;
		initialVelocityX = 0;
		initialVelocityY = 0;
		acceleration = 0;
		if (ID.erase(1) == "R")
			window->draw_img("Player2.png", Rectangle(xPosition - 15, yPosition - 15, 30, 30));
		if (ID.erase(1) == "G")
			window->draw_img("Player1.png", Rectangle(xPosition - 15, yPosition - 15, 30, 30));
		int movingStatus = NO_MOVING;
	}

bool Taw::isChosenTaw(Point mousePosition)
{
	if (isXInRange(mousePosition.x) && isYInRange(mousePosition.y))
		return true;
	return false;
}

bool Taw::isXInRange(int x)
{
	return (x <= (pow(TAW_RADIUS, 2) - pow(yPosition, 2))) && (x >= (pow(yPosition, 2) - pow(TAW_RADIUS, 2)));
}

bool Taw::isYInRange(int y)
{
	return (y <= (pow(TAW_RADIUS, 2) - pow(xPosition, 2))) && (y >= (pow(xPosition, 2) - pow(TAW_RADIUS, 2)));
}