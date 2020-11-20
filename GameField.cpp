#include "libanddif.hpp"
#include "GameField.hpp"


void GameField::buildGamefield(Window *window)
{
	window->draw_img("field.jpg", Rectangle(GAEMFIELD_INITIAL_X, GAEMFIELD_INITIAL_Y, width, lenght));
}