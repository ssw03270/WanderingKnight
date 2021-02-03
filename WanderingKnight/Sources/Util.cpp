#include "Util.hpp"
#pragma execution_character_set( "utf-8" )
void Util::readJson() {
	using json = nlohmann::json;
	std::ifstream stream( "C:/Users/ttd85/Documents/GitHub/WanderingKnight/WanderingKnight/Resources/Adventure/GameScript.json" );
	json data;
	try {
		data = json::parse(stream);
		while(true)
			std::cout << data["region"].get<std::string>();
	}
	catch (json::parse_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Util::init() {

	system("mode con cols=86 lines=40 | title WanderingKnight");
	SetConsoleOutputCP(65001);

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

	int input = 0;
	switch (temp) {
	case ' ':	// press space key
		input = SPACE;
		break;
	case '\r':	// press enter key
		input = ENTER;
		break;
	}
	return input;
}