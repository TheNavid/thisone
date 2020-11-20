#ifndef Game_H
#define Game_H
#include "Taw.hpp"
#include "Ball.hpp"
#include "GameField.hpp"
#include "Goal.hpp"
#include "Player.hpp"


class Game
{
public:
	Game();
private:

	void newRedTaw(Taw taw);
	void intitialRedTawsPosition(Window *window);
	void newGreenTaw(Taw taw);
	void intitialGreenTawsPosition(Window *window);
	void intitialTawsPosition(Window *window);
	bool isGoodPosition(Point mousePosition);
	Taw* findTaw(Point mousePosition);
	void startShootingProccess(Point mousePosition, Taw* chosenTaw);
	void startGame(Window *window);
	void update(Window *window);

	GameField gamefield;
	Goal redsGoal;
	Goal bluesGoal;
	Ball ball;
	Player *redPlayer;
	Player *bluePlayer;
	vector <Taw> redTaws;
	vector <Taw> greenTaws;
};

#endif