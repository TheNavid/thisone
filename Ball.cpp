#include "Ball.hpp"


void Ball::putInitialBall(Window *window)
{
	window->draw_img("ball.png",Rectangle(BALL_INITIAL_X, BALL_INITIAL_Y, 2 * BALL_RADIUS, 2 * BALL_RADIUS));
	xPosition = BALL_INITIAL_X;
	yPosition = BALL_INITIAL_Y;
	acceleration = 0;
	VelocityX = 0;
	VelocityY = 0;
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