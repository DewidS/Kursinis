#include "Point.h"
#include <iostream>
#include <Windows.h>
#include <time.h>

// Constructors
Point::Point(){
	x = y = 10;
	cursor.X = cursor.Y = 0;
	character = '?';
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
	cursor.X = x;
	cursor.Y = y;
	character = '?';
}

// Changing value functions:
void Point::copyPos(Point* p) {
	p->x = x;
	p->y = y;

	/*
	function, passes own coordinates to a pointer p
	*/
}

void Point::setCharacter(char character) {
	this->character = character;
}

void Point::setPossition(int x, int y) {
	this->x = x;
	this->y = y;
}

void Point::randomPossition() {
	srand((unsigned)time(NULL));
	x = rand() % Width;
	y = rand() % Height;
}

// moving functions
void Point::up() {
	if (y < 0) y = Height;
	else y--;
}

void Point::down() {
	if (y > Height)y = 0;
	else y++;
}

void Point::left() {
	if (x < 0)x = Width;
	else x--;
}

void Point::right() {
	if (x > Width) x = 0;
	else x++;
}

// Drawing cell functions:
void Point::gotoxy(int x, int y){
	cursor.X = x;
	cursor.Y = y;
	SetConsoleCursorPosition(console, cursor);
}

void Point::drawPoint(){
	gotoxy(x, y);
	std::cout << character;
}

// Debug functions
void Point::debug() {
	std::cout << "Coordinates (" << x << ";" << y << ")" << std::endl;
}