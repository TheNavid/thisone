#include "Ball.hpp"


void Ball::putInitialBall(Window *window)
{
	window->draw_img("ball.png",Rectangle(BALL_INITIAL_X, BALL_INITIAL_Y, 2 * BALL_RADIUS, 2 * BALL_RADIUS));
	xPosition = BALL_INITIAL_X;
	yPosition = BALL_INITIAL_Y;
	Vx = 0;
	Vy = 0;
	movingStatus = NO_MOVING;
}

void Ball::drawBall(Window *window)
{
	window->draw_img("ball.png",Rectangle(xPosition, yPosition, 2 * BALL_RADIUS, 2 * BALL_RADIUS));
}

int Ball::getX()
{
	return xPosition;
}

int Ball::getY()
{
	return yPosition;
}

int Ball::getVx()
{
	return Vx;
}

int Ball::getVy()
{
	return Vy;
}

void Ball::smashingToWall()
{
	//while (yPosition <= GAEMFIELD_INITIAL_Y || yPosition >= GAEMFIELD_INITIAL_Y + GAEMFIELD_LENGHT || xPosition <= GAEMFIELD_INITIAL_X || xPosition >= GAEMFIELD_INITIAL_X + GAMEFIELD_WIDTH)
	//{
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
		//}
}
void Ball::updatePosition()
{
	xPosition = xPosition + Vx;
	yPosition = yPosition + Vy;
	smashingToWall();
	calculateNewVelocity();
}
void Ball::calculateNewVelocity()
{
	float VCur = absoluteVelocity();
	float Vtemp = VCur;
	float VNew = VCur - ACCELERATION;
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

float Ball::absoluteVelocity()
{
	return sqrt(pow(Vx, 2) + pow(Vy, 2));
}

bool Ball::isStopped()
{
	return (Vx == 0) && (Vy == 0);
}

void Ball::setNewSpeed(float newVx, float newVy)
{
	Vx = Vx - newVx;
	Vy = Vy - newVy;
}