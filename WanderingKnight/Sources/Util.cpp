#include "../Includes/Util.hpp"

void Util::init() {
	system("mode con cols=86 lines=40 | title WanderingKnight");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

}

void Util::gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int Util::keyControl() {
	char temp = _getch();

	switch (temp) {
	case ' ':	// press space key
		return SPACE;
	case '\r':	// press enter key
		return ENTER;
	}
}