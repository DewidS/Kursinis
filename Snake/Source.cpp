
#include "Point.h"
#include "Engine.h"


int main() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 450, 500, TRUE); // 800 width, 100 height
	Engine game;
	game.menu();
	return 0;
}