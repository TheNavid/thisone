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
	void findSmashedTaws();
	bool isSmashedToBall(Taw taw);
	void findSmashedTawToBall();
	float findDistanceBetweenTawAndBall(Taw taw);
	float findDistanceBetweenTawAndBall2(Taw* taw);
	void updateAllTawsPosotions();
	float calculateDotProduct(float n1, float n2, float n3, float n4);
	void calculateTawSpeedAfterSmash(Taw* taw);
	void handleSmashedBall(Taw* taw);
	void calculateBallSpeedAfterSmash(Taw* taw);
	bool areAllTawsStopped();
	void calculateFirstTawSpeedAfterSmash(Taw* taw1, Taw* taw2);
	void calculateSecondTawSpeedAfterSmash(Taw* taw1, Taw* taw2);
	void handleSmashedTaw(Taw* taw1, Taw* taw2);
	float caclulateDistanceBetweenTwoTaws2(Taw* taw1, Taw* taw2);

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