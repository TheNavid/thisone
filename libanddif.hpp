#ifndef libanddif_H
#define libanddif_H


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "RSDL/src/rsdl.hpp"

using namespace std;

#define FIELD_IMAGE "field.jpg"
#define GREEN_PLAYER_IMAGE "Player1.png"
#define RED_PLAYER_IMAGE "Player2.png"
#define BALL_IMAGE "ball.png"

#define GAMEFIELD_WIDTH 800
#define GAEMFIELD_LENGHT 480
#define WINDOW_WIDTH 900
#define WINDOW_LENGHT 580
#define BALL_RADIUS 10
#define BALL_INITIAL_X 440
#define BALL_INITIAL_Y 280
#define GAEMFIELD_INITIAL_X 50
#define GAEMFIELD_INITIAL_Y 50
#define TAW_RADIUS 15
#define TAWS_NUMBER 10

#define NO_MOVING 0
#define MOVING 1
#define MAX_INITIAL_SPEED 50
#define THROW_RADIUS 60
#define ACCELERATION 2


#define GOAL_LEFT_X 50
#define GOAL_RIGHT_X 850

#define GOAL_Y_UPPER_BOUND 370 
#define GOAL_Y_LOWER_BOUND 210


#define RED 1
#define BLUE 2


const int DEFAULT_X[] = {300,350,350,100,200,600,550,550,800,700};
const int DEFAULT_Y[] = {290,140,440,290,290,290,140,440,290,290};

#endif
