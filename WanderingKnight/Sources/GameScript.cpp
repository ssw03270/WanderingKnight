#include <GameScript.hpp>

void GameScript::Script::setScriptCode(int scriptCode) { GameScript::Script::scriptCode = scriptCode; }
void GameScript::Script::setRegion(std::string region) { GameScript::Script::region = region; }
void GameScript::Script::setText(std::string text) { GameScript::Script::text = text; }

int GameScript::Script::getScriptCode() { return GameScript::Script::scriptCode; }
std::string GameScript::Script::getRegion() { return GameScript::Script::region; }
std::string GameScript::Script::getText() { return GameScript::Script::text; }

std::vector<std::string> GameScript::Script::getWord(std::string text) {
	std::vector<std::string> v;
	std::string s = "";
	for (const auto& x : text) {
		if (x == ' ') {
			v.push_back(s);
			s = "";
		}
		else {
			s += x;
		}
	}
	return v;
}