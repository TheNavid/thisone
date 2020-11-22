#include "Game.hpp"


Game::Game()
{
	Window *window = new Window(WINDOW_WIDTH, WINDOW_LENGHT, "Soccer Stars");
	gamefield.buildGamefield(window);
	ball.putInitialBall(window);
	intitialTawsPosition(window);
	startGame(window);
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

bool Game::areTheseSmashed(Taw taw1, Taw taw2)
{
	float tawsDistance = caclulateDistanceBetweenTwoTaws(taw1, taw2);
	if (tawsDistance <= 2 * TAW_RADIUS)
		return true;
	return false;
}

vector <vector <Taw*> > Game::findSmashedTaws()
{
	vector <vector <Taw*> > smashedTaws;
	for (int i = 0; i < TAWS_NUMBER; i++)
	{
		for (int j = 0; j < TAWS_NUMBER; j++)
		{
			if (areTheseSmashed(taws[i], taws[j]))
			{
				vector <Taw*> pairOfSmashedTaws;
				pairOfSmashedTaws.push_back(&taws[i]);
				pairOfSmashedTaws.push_back(&taws[j]);
				smashedTaws.push_back(pairOfSmashedTaws);
			}
		}
	}
	return smashedTaws;
}

float Game::findDistanceBetweenTawAndBall(Taw taw)
{
	return sqrt(pow(taw.getX() - ball.getX(), 2) + pow(taw.getY() - ball.getY(), 2));
}

bool Game::isSmashedToBall(Taw taw)
{
	float distanceBetweenTawAndBall = findDistanceBetweenTawAndBall(taw);
	if (distanceBetweenTawAndBall <= TAW_RADIUS + BALL_RADIUS)
		return true;
	return false;
}

Taw* Game::findSmashedTawToBall()
{
	for (int i = 0; i < TAWS_NUMBER; i++)
		if (isSmashedToBall(taws[i]))
			return &taws[i];
}

void Game::updateAllTawsPosotions()
{
	for (int i = 0; i < TAWS_NUMBER; i++)
		taws[i].updatePosition();
}

void Game::update()
{
	while(true)
	{
		chosenTaw->updatePosition();
		vector <vector <Taw*> > smashedTaws = findSmashedTaws();
		Taw* smashedToBall = findSmashedTawToBall();
		handleSmashedTaw(smashedTaws);
		handleSmashedBall(smashedToBall);
		updateAllTawsPosotions();
		ball.updatePosition();
	}

}

void Game::draw(Window *window)
{
	window->clear();
	gamefield.buildGamefield(window);
	ball.drawBall(window);
	for (int i = 0; i < TAWS_NUMBER; i++)
		taws[i].drawTaw(window);
	window->update_screen();
}

void Game::startGame(Window *window)
{
	while(true)
	{
		handleEvents(window);
		if (goodPosition == true)
			update();
		draw(window);
		delay(40);
	}
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