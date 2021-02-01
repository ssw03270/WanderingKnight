#include<iostream>
#include "../Includes/Display.hpp"
#include "../Includes/Util.hpp"

using namespace std;

int main() {
	Util::init();
	Display::drawTitle();
	Display::drawMenu();
}