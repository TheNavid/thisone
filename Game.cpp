#include "Game.hpp"


Game::Game()
{

	initVariables();

	Window *window = new Window(WINDOW_WIDTH, WINDOW_LENGHT, "Soccer Stars");
	gamefield.buildGamefield(window);
	ball.putInitialBall(window);
	intitialTawsPosition(window);
	startGame(window);
}


void Game::initVariables()
{
	blueScores =0;
	redScores = 0;
	currentTeam = RED;
}


void Game::newTaw(Taw taw)
{
	taws.push_back(taw);
}

void Game::intitialTawsPosition(Window *window)
{
	newTaw(Taw(300, 290, "R0", window)); 
	newTaw(Taw(350, 140, "R1", window));
	newTaw(Taw(350, 440, "R2", window));
	newTaw(Taw(100, 290, "R3", window));
	newTaw(Taw(200, 290, "R4", window));
	newTaw(Taw(600, 290, "G0", window));
	newTaw(Taw(550, 140, "G1", window));
	newTaw(Taw(550, 440, "G2", window));
	newTaw(Taw(800, 290, "G3", window));
	newTaw(Taw(700, 290, "G4", window));
}

bool Game::isGoodPosition(Point mousePosition)
{
	for (int taw = 0; taw < TAWS_NUMBER; taw++)
	{
		if (taws[taw].isChosenTaw(mousePosition))
		{
			return true;
		}
	}
	return false;
}

//void shootingTaw()
//{
//}

int Game::getTeam(Taw taw)
{

}



void Game::switchTurn()
{
	currentTeam = (currentTeam +1) %2;
}

void Game::addScore()
{
	if(currentTeam == RED)
	{
		redScores++;
	}
	else
	{
		blueScores++;
	}
}


void Game::resetWindow()
{
	for(int i=0; i<taws.size(); i++)
	{
		taws[i].setX(DEFAULT_X[i]);
		taws[i].setY(DEFAULT_Y[i]);
	}
}


bool Game::isGoal(float ballX, float ballY)
{
	return ( ballX < GOAL_LEFT_X || ballX > GOAL_RIGHT_X) && 
		(ballY < GOAL_Y_UPPER_BOUND && ballY > GOAL_Y_LOWER_BOUND);
}



Taw* Game::findTaw(Point mousePosition)
{
	for (int taw = 0; taw < TAWS_NUMBER; taw++)
		if (taws[taw].isChosenTaw(mousePosition))
			return &taws[taw];	
}

float Game::caclulateDistanceBetweenTwoTaws(Taw taw1, Taw taw2)
{
	return sqrt(pow(taw1.getX() - taw2.getX(), 2) + pow(taw1.getY() - taw2.getY(), 2));
}

float Game::caclulateDistanceBetweenTwoTaws2(Taw* taw1, Taw* taw2)
{
	return sqrt(pow(taw1->getX() - taw2->getX(), 2) + pow(taw1->getY() - taw2->getY(), 2));
}

bool Game::areTheseSmashed(Taw taw1, Taw taw2)
{
	float tawsDistance = caclulateDistanceBetweenTwoTaws(taw1, taw2);
	if (tawsDistance <= 2 * TAW_RADIUS)
	{
		cout<<"khord be mohre"<<endl;
		return true;
	}
	return false;
}

void Game::findSmashedTaws()
{
	for (int i = 0; i < TAWS_NUMBER; i++)
	{
		for (int j = 0; j < TAWS_NUMBER; j++)
		{
			if (i != j)
			{
				if (areTheseSmashed(taws[i], taws[j]))
					handleSmashedTaw(&taws[i], &taws[j]);
			}
		}
	}
}

float Game::findDistanceBetweenTawAndBall(Taw taw)
{
	return sqrt(pow(taw.getX() - ball.getX(), 2) + pow(taw.getY() - ball.getY(), 2));
}

float Game::findDistanceBetweenTawAndBall2(Taw* taw)
{
	return sqrt(pow((taw->getX()) - (ball.getX()), 2) + pow((taw->getY()) - (ball.getY()), 2));
}

bool Game::isSmashedToBall(Taw taw)
{
	float distanceBetweenTawAndBall = findDistanceBetweenTawAndBall(taw);
	if (distanceBetweenTawAndBall <= TAW_RADIUS + BALL_RADIUS)
		return true;
	return false;
}

void Game::findSmashedTawToBall()
{
	for (int i = 0; i < TAWS_NUMBER; i++)
		if (isSmashedToBall(taws[i]))
		{
			cout<<"khord be toop"<<endl;
			handleSmashedBall(&taws[i]);
		}
}

void Game::updateAllTawsPosotions()
{
	for (int i = 0; i < TAWS_NUMBER; i++)
		taws[i].updatePosition();
}

bool Game::areAllTawsStopped()
{
	int numberOfStppedTaws = 0;
	for (int i = 0; i < TAWS_NUMBER; i++)
		if(taws[i].isStopped())
			numberOfStppedTaws++;
	if ((numberOfStppedTaws == TAWS_NUMBER) && (ball.isStopped()))
		return true;
	else
		return false;
}

float Game::calculateDotProduct(float n1, float n2, float n3, float n4)
{
	return (n1 * n3) + (n2 * n4);
}

void Game::calculateTawSpeedAfterSmash(Taw* taw)
{

	float M = 3 / 3;
	float dotProduct = ((taw->getVx() * taw->getX()) + (ball.getVx() * ball.getX())
					  + (taw->getVy() * taw->getY()) + (ball.getVy() * ball.getY()))
					  -
					   ((taw->getVx() * ball.getX()) + (ball.getVx() * taw->getX())
					  + (taw->getVy() * ball.getY()) + (ball.getVy() * taw->getY()));


	float squareDistance = pow(findDistanceBetweenTawAndBall2(taw), 2);


	float temp = dotProduct / squareDistance;
	float XDistance = (ball.getX() - taw->getX());
	float YDistance = (ball.getY() - taw->getY());

	float newVx = taw->getVx() + (M * temp * XDistance);
	float newVy = taw->getVy() + (M * temp * YDistance);

	cout << "New ball speed: " << newVx << " " << newVy << endl;
	taw->setNewSpeed(newVx, newVy);
	taw->updatePosition();
}

void Game::calculateBallSpeedAfterSmash(Taw* taw)
{
	float M = 5 / 3;
	float dotProduct = ((taw->getVx() * taw->getX()) + (ball.getVx() * ball.getX())
					  + (taw->getVy() * taw->getY()) + (ball.getVy() * ball.getY()))
					  -
					   ((taw->getVx() * ball.getX()) + (ball.getVx() * taw->getX())
					  + (taw->getVy() * ball.getY()) + (ball.getVy() * taw->getY()));


	float squareDistance = pow(findDistanceBetweenTawAndBall2(taw), 2);


	float temp = dotProduct / squareDistance;
	float XDistance = (ball.getX() - taw->getX());
	float YDistance = (ball.getY() - taw->getY());

	float newVx = ball.getVx() - (M * temp * XDistance);
	float newVy = ball.getVy() - (M * temp * YDistance);

	cout <<newVx<<","<<newVy<<","<<squareDistance<<","<<dotProduct<<","<<temp<<endl;
	ball.setNewSpeed(newVx, newVy);
	ball.updatePosition();
}


void Game::handleSmashedBall(Taw* taw)
{
	calculateTawSpeedAfterSmash(taw);
	calculateBallSpeedAfterSmash(taw);
}

void Game::calculateFirstTawSpeedAfterSmash(Taw* taw1, Taw* taw2)
{
	float dotProduct = ((taw1->getVx() * taw1->getX()) + (taw2->getVx() * taw2->getX())
					  + (taw1->getVy() * taw1->getY()) + (taw2->getVy() * taw2->getY()))
					  -
					   ((taw1->getVx() * taw2->getX()) + (taw2->getVx() * taw1->getX())
					  + (taw1->getVy() * taw2->getY()) + (taw2->getVy() * taw1->getY()));

	float squareDistance = pow(caclulateDistanceBetweenTwoTaws2(taw1, taw2), 2);

	float XDistance = taw2->getX() - taw1->getX();
	float YDistance = taw2->getY() - taw1->getY();

	float newVx = taw1->getVx() + (dotProduct * XDistance / squareDistance);
	float newVy = taw1->getVy() + (dotProduct * YDistance / squareDistance);
	taw1->setNewSpeed(newVx, newVy);
	taw1->updatePosition();	
}

void Game::calculateSecondTawSpeedAfterSmash(Taw* taw1, Taw* taw2)
{
	float dotProduct = ((taw1->getVx() * taw1->getX()) + (taw2->getVx() * taw2->getX())
					  + (taw1->getVy() * taw1->getY()) + (taw2->getVy() * taw2->getY()))
					  -
					   ((taw1->getVx() * taw2->getX()) + (taw2->getVx() * taw1->getX())
					  + (taw1->getVy() * taw2->getY()) + (taw2->getVy() * taw1->getY()));

	float squareDistance = pow(caclulateDistanceBetweenTwoTaws2(taw1, taw2), 2);

	float temp = dotProduct / squareDistance;

	float XDistance = taw2->getX() - taw1->getX();
	float YDistance = taw2->getY() - taw1->getY();

	float newVx = taw2->getVx() - (temp * XDistance);
	float newVy = taw2->getVy() - (temp * YDistance);
	taw2->setNewSpeed(newVx, newVy);
	taw2->updatePosition();
}


void Game::handleSmashedTaw(Taw* taw1, Taw* taw2)
{
	calculateFirstTawSpeedAfterSmash(taw1, taw2);
	calculateSecondTawSpeedAfterSmash(taw1, taw2);
}

void Game::update()
{
	//cout << "(" << ball.getX() << "," << ball.getY() << ")" <<"*******"<<"("<<ball.getVx()<<","<<ball.getVy()<<")"<<endl;
	chosenTaw->updatePosition();
	if (!areAllTawsStopped())
	{
		findSmashedTaws();
		findSmashedTawToBall();

		// maybe should be moved
		if(isGoal(ball.getX(), ball.getY()))
		{
			cout << ball.getX() << "  " << ball.getY() << endl;
			cout << "Goal!" << endl;
			addScore();
			resetWindow();
		}
	}

}

void Game::draw(Window *window)
{
	window->clear();
	gamefield.buildGamefield(window);
	ball.drawBall(window);
	for (int i = 0; i < TAWS_NUMBER; i++)
		taws[i].drawTaw(window);
	showScores(window);
	window->update_screen();
}

void Game::startGame(Window *window)
{
	while(true)
	{
		handleEvents(window);
		if (goodPosition)
			update();
		draw(window);
		delay(40);
	}
}

void Game::showScores(Window* window)
{
	window->show_text("SoccerStars", Point(370, 10), WHITE, "FreeSans.ttf", 30);
	string GreenScore = "*GreenScores : " + to_string(blueScores) + "*";
	string RedScore = "*" + to_string(redScores) + " : RedScores*" ;
	window->show_text(GreenScore, Point(200, 540), WHITE, "FreeSans.ttf", 20);
	window->show_text(RedScore, Point(550, 540), WHITE, "FreeSans.ttf", 20);
}

void Game::handleEvents(Window *window)
{
	while (window->has_pending_event())
	{
		Event event = window->poll_for_event();
		switch (event.get_type())
		{
			case Event::QUIT:
			{
				exit(0);
				break;
			}
			case Event::LCLICK:
			{
				goodPosition = false;	
				Point mousePosition = event.get_mouse_position();
				if(isGoodPosition(mousePosition))
				{
					goodPosition = true;
					chosenTaw = findTaw(mousePosition);
				}
				break;
			}
			case Event::LRELEASE:
			{
				Point releaseMousePosition = event.get_mouse_position();
				if (goodPosition == true)
					chosenTaw->calculateInitialVelocity(releaseMousePosition);
				break;
			}
		}
	}
}