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

	void newTaw(Taw taw);
	void intitialTawsPosition(Window *window);
	bool isGoodPosition(Point mousePosition);
	Taw* findTaw(Point mousePosition);
	void update();
	void startGame(Window *window);
	void handleEvents(Window *window);
	void draw(Window *window);
	float caclulateDistanceBetweenTwoTaws(Taw taw1, Taw taw2);
	bool areTheseSmashed(Taw taw1, Taw taw2);
	vector <vector <Taw*> > findSmashedTaws();
	bool isSmashedToBall(Taw taw);
	Taw* findSmashedTawToBall();
	float findDistanceBetweenTawAndBall(Taw taw);

	GameField gamefield;
	Goal redsGoal;
	Goal bluesGoal;
	Ball ball;
	Player redPlayer;
	Player bluePlayer;
	vector <Taw> taws;
	Taw* chosenTaw;
	bool goodPosition = false;
};

#endif