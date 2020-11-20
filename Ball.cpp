#include "Ball.hpp"


void Ball::putInitialBall(Window *window)
{
	window->draw_img("ball.png",Rectangle(BALL_INITIAL_X, BALL_INITIAL_Y, 2 * BALL_RADIUS, 2 * BALL_RADIUS));
	xPosition = BALL_INITIAL_X;
	yPosition = BALL_INITIAL_Y;
	acceleration = 0;
	initialVelocityX = 0;
	initialVelocityY = 0;
	movingStatus = NO_MOVING;
}
