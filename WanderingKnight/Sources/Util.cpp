#include <Util.hpp>

#pragma execution_character_set( "utf-8" )

GameScript::Script* Util::readScript(std::string fileName) {
	std::string fullPath = Util::getResourcesPath();
	using json = nlohmann::json;
	std::ifstream stream(fullPath + fileName);
	json data;
	data = json::parse(stream);
	GameScript::Script* script = new GameScript::Script[data.size()];
	int i = 0;
	for (const auto& datum : data) {
		script[i].setScriptCode(datum["scriptCode"].get<int>());
		script[i].setNextCode(datum["nextCode"].get<int>());
		script[i].setRegion(datum["region"].get<std::string>());
		script[i].setText(datum["text"].get<std::string>());
		script[i].setSelection(datum["selection"].get<std::vector<std::string>>());
		script[i].setSelectionCode(datum["selectionCode"].get<std::vector<int>>());
		++i;
	}
	

	return script;
}

PlayerInfo::Player Util::readPlayer(std::string fileName) {
	std::string fullPath = Util::getResourcesPath();
	using json = nlohmann::json;
	std::ifstream stream(fullPath + fileName);
	json data;
	data = json::parse(stream);
	PlayerInfo::Player player;

	player.setPlayerName(data["playerName"].get<std::string>());
	player.setPlayerLevel(data["playerLevel"].get<int>());
	player.setPlayerExp(data["playerExp"].get<int>());
	player.setPlayerMaxEXP(data["playerMaxExp"].get<int>());
	player.setPlayerHP(data["playerHP"].get<int>());
	player.setPlayerMaxHP(data["playerMaxHP"].get<int>());
	player.setPlayerSTR(data["playerSTR"].get<int>());
	player.setPlayerLUK(data["playerLUK"].get<int>());
	player.setPlayerINT(data["playerINT"].get<int>());
	player.setPlayerFame(data["playerFame"].get<int>());
	player.setMaxEXP(data["maxExp"].get<std::vector<int>>());

	return player;
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

// return resource path
std::string Util::getResourcesPath() {
	wchar_t path[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, path, MAX_PATH);

	USES_CONVERSION;
	std::string str = W2A(path);
	str = str.substr(0, str.find_last_of("\\/"));
	str.replace(str.find("x64\\Debug"), 9, "");
	str += "Resources";

	return str;
}