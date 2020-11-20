#ifndef GameField_H
#define GameField_H

#include "libanddif.hpp"

class GameField
{
public:
	void buildGamefield(Window *window);
private:
	int width = GAMEFIELD_WIDTH;
	int lenght = GAEMFIELD_LENGHT;
};

#endif