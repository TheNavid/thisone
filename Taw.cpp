#include "Taw.hpp"


Taw::Taw(int x, int y, string Id, Window* window)
	{
		xPosition = x;
		yPosition = y;
		ID = Id;
		Vx = 0;
		Vy = 0;
		if (Id.erase(1) == "R")
			window->draw_img("Player2.png", Rectangle(xPosition - 15, yPosition - 15, 30, 30));
		if (Id.erase(1) == "G")
			window->draw_img("Player1.png", Rectangle(xPosition - 15, yPosition - 15, 30, 30));
		int movingStatus = NO_MOVING;
	}

void Taw::drawTaw(Window* window)
{
	string id = ID;
	if (id.erase(1) == "R")
		window->draw_img(RED_PLAYER_IMAGE, Rectangle(xPosition - 15, yPosition - 15, 30, 30));
	if (id.erase(1) == "G")
		window->draw_img(GREEN_PLAYER_IMAGE, Rectangle(xPosition - 15, yPosition - 15, 30, 30));
}

void Taw::printInfo()
{
	cout << "(" << Vx <<","<< Vy <<")"<< endl;
}

bool Taw::isChosenTaw(Point mousePosition)
{
	if (isXInRange(mousePosition.x, mousePosition.y) && isYInRange(mousePosition.x, mousePosition.y))
		return true;
	return false;
}

bool Taw::isXInRange(int x, int y)
{
	return (x - xPosition <= sqrt(pow(TAW_RADIUS, 2) - pow(y - yPosition, 2))) && (x - xPosition >= sqrt(pow(TAW_RADIUS, 2) - pow(y - yPosition, 2))*(-1));
}

bool Taw::isYInRange(int x, int y)
{
	return (y - yPosition <= sqrt(pow(TAW_RADIUS, 2) - pow(x - xPosition, 2))) && (y - yPosition >= sqrt(pow(TAW_RADIUS, 2) - pow(x - xPosition, 2))*(-1));
}

float Taw::measureAbsolute(Point mousePosition)
{
	return sqrt(pow(mousePosition.x - xPosition, 2) + pow(mousePosition.y - yPosition, 2));
}

float Taw::measureInitialVelocityX (int mouseXPosition, float distanceAbsolute)
{
	float deltaX = mouseXPosition - xPosition;
	if (distanceAbsolute < THROW_RADIUS)
		return (-1 * MAX_INITIAL_SPEED *(deltaX / THROW_RADIUS));
	if (distanceAbsolute >= THROW_RADIUS)
		return (-1 * MAX_INITIAL_SPEED *(deltaX / distanceAbsolute));
}

float Taw::measureInitialVelocityY (int mouseYPosition, float distanceAbsolute)
{
	float deltaY = (mouseYPosition - yPosition);
	if (distanceAbsolute < THROW_RADIUS)
	{
		return (-1 * MAX_INITIAL_SPEED *(deltaY / THROW_RADIUS));
	}
	if (distanceAbsolute >= THROW_RADIUS)
		return (-1 * MAX_INITIAL_SPEED *(deltaY/ distanceAbsolute));	
}

void Taw::calculateInitialVelocity(Point mousePosition)
{
	float distanceAbsolute = measureAbsolute(mousePosition);
	//cout << "fasele = " << distanceAbsolute << "shoa = " << THROW_RADIUS <<endl;
	Vx = measureInitialVelocityX(mousePosition.x, distanceAbsolute);
	Vy = measureInitialVelocityY(mousePosition.y, distanceAbsolute);
}

string Taw::getID()
{
	return ID;
}


void Taw::smashingToTopWall()
{
	//while (yPosition - TAW_RADIUS <= GAEMFIELD_INITIAL_Y || yPosition + TAW_RADIUS >= GAEMFIELD_INITIAL_Y + GAEMFIELD_LENGHT || xPosition - TAW_RADIUS <= GAEMFIELD_INITIAL_X || xPosition + TAW_RADIUS >= GAEMFIELD_INITIAL_X + GAMEFIELD_WIDTH)
		if (yPosition < GAEMFIELD_INITIAL_Y)
		{
			Vy = -Vy;
			yPosition = 2 * GAEMFIELD_INITIAL_Y - yPosition;
		}
		else if (yPosition > GAEMFIELD_INITIAL_Y + GAEMFIELD_LENGHT)
		{
			Vy = -Vy;
			yPosition = 2 * (GAEMFIELD_INITIAL_Y + GAEMFIELD_LENGHT) - yPosition;
		}
		else if (xPosition < GAEMFIELD_INITIAL_X)
		{
			Vx = -Vx;
			xPosition = 2 * GAEMFIELD_INITIAL_X - xPosition;
		}
		else if (xPosition > GAEMFIELD_INITIAL_X + GAMEFIELD_WIDTH)
		{
			Vx = -Vx;
			xPosition = 2 * (GAEMFIELD_INITIAL_X + GAMEFIELD_WIDTH) - xPosition;
		}
		else
		{
			Vy = Vy;
			Vx = Vx;
		}	
}
void Taw::updatePosition()
{
	//printInfo();
	xPosition = xPosition + Vx;
	yPosition = yPosition + Vy;
	smashingToTopWall();
	calculateNewVelocity();
}

bool Taw::isStopped()
{
	return (Vx == 0) && (Vy == 0);
}

void Taw::calculateNewVelocity()
{
	float VCur = absoluteVelocity();
	float Vtemp = VCur;
	float VNew = VCur - ACCELERATION;
	//cout << "VCur = " << VCur << "VNew = " << VNew << "a = " << ACCELERATION << endl;
	if (VNew < 0)
	{
		Vx = 0;
		Vy = 0;
	}
	if (Vx != 0)
	{	
		float Vcos = abs(Vx/Vtemp);
		Vx = Vcos * VNew * (Vx/abs(Vx));
	}
	if (Vy != 0)
	{
		float Vsin = abs(Vy/Vtemp);
		Vy = Vsin * VNew * (Vy/abs(Vy));
	}
}

float Taw::absoluteVelocity()
{
	return sqrt(pow(Vx, 2) + pow(Vy, 2));
}

int Taw::getX()
{
	return xPosition;
}

int Taw::getY()
{
	return yPosition;
}