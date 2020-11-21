#include "Game.hpp"


Game::Game()
{
	Window *window = new Window(WINDOW_WIDTH, WINDOW_LENGHT, "Soccer Stars");
	gamefield.buildGamefield(window);
	ball.putInitialBall(window);
	intitialTawsPosition(window);
	startGame(window);

}

void Game::newRedTaw(Taw taw)
{
	redTaws.push_back(taw);
}
void Game::intitialRedTawsPosition(Window *window)
{
	newRedTaw(Taw(300, 290, "R0", window));
	newRedTaw(Taw(350, 140, "R1", window));
	newRedTaw(Taw(350, 440, "R2", window));
	newRedTaw(Taw(100, 290, "R3", window));
	newRedTaw(Taw(200, 290, "R4", window));
}

void Game::newGreenTaw(Taw taw)
{
	greenTaws.push_back(taw);
}

void Game::intitialGreenTawsPosition(Window *window)
{
	newGreenTaw(Taw(600, 290, "G0", window));
	newGreenTaw(Taw(550, 140, "G1", window));
	newGreenTaw(Taw(550, 440, "G2", window));
	newGreenTaw(Taw(800, 290, "G3", window));
	newGreenTaw(Taw(700, 290, "G4", window));
}

void Game::intitialTawsPosition(Window *window)
{
	intitialGreenTawsPosition(window);
	intitialRedTawsPosition(window);
}

bool Game::isGoodPosition(Point mousePosition)
{
	for (int taw = 0; taw < TAWS_NUMBER; taw++)
		if (redTaws[taw].isChosenTaw(mousePosition))
			return true;
	return false;
}

//void shootingTaw()
//{
//}

Taw* Game::findTaw(Point mousePosition)
{
	for (int taw = 0; taw < TAWS_NUMBER; taw++)
		if (redTaws[taw].isChosenTaw(mousePosition))
			return &redTaws[taw];
	for (int taw = 0; taw < TAWS_NUMBER; taw++)
		if (greenTaws[taw].isChosenTaw(mousePosition))
			return &greenTaws[taw];		
}

void Game::startShootingProccess(Point mousePosition, Taw* chosenTaw)
{
	chosenTaw->calculateInitialVelocity(mousePosition);
	//shootingTaw(mousePosition, chosenTaw);
}

void Game::startGame(Window *window)
{
	while(true)
	{
		update(window);
		window->update_screen();
	}
}
void Game::update(Window *window)
{
	while (window->has_pending_event())
	{
		Event event = window->poll_for_event();
		switch (event.get_type())
		{
			case Event::EventType::QUIT:
				exit(0);
				break;
			case Event::EventType::LCLICK:
				Point mousePosition = event.get_mouse_position();
				bool goodPosition = false;
				if(isGoodPosition(mousePosition))
				{
					goodPosition = true;
					//Taw* chosenTaw = findTaw(mousePosition);
				}
				break;
		//	case Event::EventType::RCLICK:
		//		Point mousePosition = event.get_mouse_position();
		//		if (goodPosition == true)
		//			startShootingProccess(mousePosition, chosenTaw);
		}
	}
}