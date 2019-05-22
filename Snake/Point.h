#include <Windows.h>

#pragma once
const int Width = 50;
const int Height = 25;

class Point{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursor;
	int x; 
	int y;
	char character;
	int value;
public:
	// Constructors
	Point();
	Point(int x, int y);

	// returning value functions
	int getx() { return x; }
	int gety() { return y; }

	// Changing value  functions:
	void copyPos(Point* p);
	void setCharacter(char character);
	void setPossition(int x, int y);
	void randomPossition();

	// moving functions:
	void up();
	void down();
	void left();
	void right();

	// Drawing cell functions:
	void gotoxy(int x, int y);
	void drawPoint();

	// Debug functions:
	void debug();

};

