#pragma once

#ifndef __UTIL_H__
#define __UTIL_H__

#include<iostream>
#include<Windows.h>
#include<conio.h>

#define DISPLAY_WIDTH 86
#define DISPLAY_HEIGHT 40

#define SPACE 0
#define ENTER 1

namespace Util
{
	void init();
	void gotoxy(int, int);
	int keyControl();
}

#endif

