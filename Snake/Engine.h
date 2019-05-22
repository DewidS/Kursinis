#pragma once

#include <conio.h>
#include <Windows.h>
#include "Point.h"

class Engine{
	// Snake:
	Point* snake[100];
	enum Direction {UP, DOWN, LEFT, RIGHT} dir;
	int size;
	int score;
	Point scorePlace;
	// Fruit:
	Point fruit;
	// Game:  
	bool gameRun;
public:
	// Constructors:
	Engine();

	// Menu organization
	void menu();
	// Snake logic elemetns:
	void addBodyPart(int x, int y);
	void updateSnake();
	void snakeMovement();
	void snakeSeflCollision();
	void gameOver();
	// Game logic:
	void collisions();

	// Game base:
	void controls();
	void runGame();
};

