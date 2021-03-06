#pragma once

#ifndef __UTIL_H__
#define __UTIL_H__

#include<Windows.h>
#include<conio.h>
#include<cstring>
#include <fstream>
#include <iostream>
#include <atlconv.h>
#include <json/json.hpp>

#include <GameScript.hpp>
#include <PlayerInfo.hpp>

#define DISPLAY_WIDTH 86
#define DISPLAY_HEIGHT 40

#define SPACE 0
#define ENTER 1

namespace Util
{
	void init();
	void gotoxy(int, int);
	int keyControl();
	std::string getResourcesPath();
	GameScript::Script* readScript(std::string);
	PlayerInfo::Player readPlayer(std::string);
}

#endif

