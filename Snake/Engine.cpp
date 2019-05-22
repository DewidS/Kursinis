#include "Engine.h"
#include "Point.h"

#include <iostream>

// Constructors:
Engine::Engine(){
	// Snake:
	snake[0] = new Point(10, 10);
	snake[0]->setCharacter('S');
	size = 1;
	dir = UP;
	score = 0;

	// Fruit:
	fruit.randomPossition();
	fruit.setCharacter('f');
	// Game
	gameRun = true;
}

// Menu organization
void Engine::menu() {
	std::cout << "	Snake game	" << std::endl;
	std::cout << "	1. Start Game	" << std::endl;
	std::cout << "	2. Exit			" << std::endl;
	if (_kbhit) {
		char key = _getch();
		switch (key) {
		case '1': runGame(); break;
		case '2': gameRun = false; break;
		default: break;
		}
	}
}

// snake logic elements:
void Engine::addBodyPart(int x, int y) {
	snake[size] = new Point(x, y);
	snake[size]->setCharacter('*');
	size++;
}

void Engine::updateSnake() {
	for(int i = size-1; i > 0; i--)
		snake[i - 1]->copyPos(snake[i]);
}

void Engine::snakeMovement() {
	switch (dir) {
	case UP: snake[0]->up(); break;
	case DOWN: snake[0]->down(); break;
	case LEFT: snake[0]->left(); break;
	case RIGHT: snake[0]->right(); break;
	}
}

void Engine::snakeSeflCollision() {
	for (int i = 1; i < size; i++) {
		if (snake[0]->getx() == snake[i]->getx() &&
			snake[0]->gety() == snake[i]->gety()) {
			gameRun = false;
			gameOver();
		}
	}
}

void Engine::gameOver() {

	system("cls");
	std::cout << "game over" << std::endl;
	std::cout << "Your score: " << score << std::endl;
}

// Game logic:
void Engine::collisions() {
	if (snake[0]->getx() == fruit.getx() && snake[0]->gety() == fruit.gety()) {
		fruit.randomPossition();
		addBodyPart(0, 0);
		score += 10;
	}
}

// Game base:
void Engine::controls() {
	if (_kbhit()) {
		char keyPressed = _getch();
		switch (keyPressed) {
		case 'w': if (dir != DOWN) dir = UP; break;
		case 's': if (dir != UP) dir = DOWN; break;
		case 'a': if (dir != RIGHT) dir = LEFT; break;
		case 'd': if (dir != LEFT) dir = RIGHT; break;
		case 'e': gameRun = false;
		}
	}
}

void Engine::runGame() {
	while (gameRun) {
		system("cls");

		snakeSeflCollision();
		updateSnake();
		controls();
		snakeMovement();

		collisions();

		for (int i = 0; i < size; i++) {
			snake[i]->drawPoint();
		}
		fruit.drawPoint();
		scorePlace.gotoxy(0, 26);
		std::cout << "Score: " << score << std::endl;
		std::cout << "w/s/d/a - controls, e - exit game ";
		Sleep(50);
	}
}