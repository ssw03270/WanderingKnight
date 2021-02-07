#pragma once

#ifndef __GAME_H__
#define __GAME_H__

#include<string>
#include<vector>

namespace Game {
	void gameStart();
	void playerStat();
	void drawPercentage(float, int);
	int gameSelection(std::vector<std::string>);
	void gameInfo();
	void drawLine();
}

#endif // !__GAME_H__
