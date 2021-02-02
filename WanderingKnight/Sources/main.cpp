#include<iostream>
#include "../Includes/MainMenu.hpp"
#include "../Includes/Util.hpp"
#include "../Includes/Game.hpp"

using namespace std;

int menu();

int main() {
	Util::init();
	while (1) {
		if (menu() == 2) return 0;
	}
}

int menu() {
	switch (MainMenu::drawMenu()) {
	case 0:	// game start
		return 0;
	case 1:	// game info
		Game::gameInfo();
		return 1;
	case 2:	// game quit
		return 2;
	}
}