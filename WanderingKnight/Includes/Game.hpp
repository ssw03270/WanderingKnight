#pragma once

#ifndef __GAME_H__
#define __GAME_H__

#include<string>
#include<vector>

namespace Game {
	void gameStart();
	int gameSelection(std::vector<std::string>);
	void gameInfo();
	void drawUI();
}

#endif // !__GAME_H__
