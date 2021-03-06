#include <GameScript.hpp>

void GameScript::Script::setScriptCode(int scriptCode) { GameScript::Script::scriptCode = scriptCode; }
void GameScript::Script::setNextCode(int nextCode) { GameScript::Script::nextCode = nextCode; }
void GameScript::Script::setRegion(std::string region) { GameScript::Script::region = region; }
void GameScript::Script::setText(std::string text) { GameScript::Script::text = text; }
void GameScript::Script::setSelection(std::vector<std::string> selection) { GameScript::Script::selection = selection; }
void GameScript::Script::setSelectionCode(std::vector<int> selectionCode) { GameScript::Script::selectionCode = selectionCode; }

int GameScript::Script::getScriptCode() { return GameScript::Script::scriptCode; }
int GameScript::Script::getNextCode() { return GameScript::Script::nextCode; }
std::string GameScript::Script::getRegion() { return GameScript::Script::region; }
std::string GameScript::Script::getText() { return GameScript::Script::text; }
std::vector<std::string> GameScript::Script::getSelection() { return GameScript::Script::selection; }
std::vector<int> GameScript::Script::getSelectionCode() { return GameScript::Script::selectionCode; }

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