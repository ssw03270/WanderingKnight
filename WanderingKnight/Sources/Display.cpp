#include "../Includes/Display.hpp"
#include "../Includes/Util.hpp"

// Draw title in consol
void Display::drawTitle() {
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "    ##   ##    ##     ##  ##   ####     ######   #####    ######   ##  ##    #####  " << std::endl;
    std::cout << "    ##   ##   ####    ### ##   ## ##    ##       ##  ##     ##     ### ##   ##      " << std::endl;
    std::cout << "    ## # ##  ##  ##   ######   ##  ##   #####    ##  ##     ##     ######   ##      " << std::endl;
    std::cout << "    #######  ##  ##   ######   ##  ##   ##       #####      ##     ######   ## ###  " << std::endl;
    std::cout << "    ### ###  ######   ## ###   ## ##    ##       ## ##      ##     ## ###   ##  ##  " << std::endl;
    std::cout << "    ##   ##  ##  ##   ##  ##   ####     ######   ##  ##   ######   ##  ##    #####  " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "                ##  ##   ##  ##   ######    #####   ##  ##   ######                 " << std::endl;
    std::cout << "                ## ##    ### ##     ##     ##       ##  ##     ##                   " << std::endl;
    std::cout << "                ####     ######     ##     ##       ######     ##                   " << std::endl;
    std::cout << "                ####     ######     ##     ## ###   ##  ##     ##                   " << std::endl;
    std::cout << "                ## ##    ## ###     ##     ##  ##   ##  ##     ##                   " << std::endl;
    std::cout << "                ##  ##   ##  ##   ######    #####   ##  ##     ##                   " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
}

// Draw menu in consol
void Display::drawMenu() {
    int x = DISPLAY_WIDTH / 2 - 10, y = DISPLAY_HEIGHT / 2;
    int curPos = 0;

    // print menu
    Util::gotoxy(x, y);
    std::cout << "  GAME START";
    Util::gotoxy(x, y + 1);
    std::cout << "  GAME INFO";
    Util::gotoxy(x, y + 2);
    std::cout << "  GAME QUIT";

    // If input ENTER key, move curser
    while (true) {
        for (int i = 0; i <= 2; i++) {
            Util::gotoxy(x, y + i);
            (i == curPos) ? std::cout << ">" : std::cout << " ";
        }
        
        // If input ENTER key, curPos increase
        curPos = (Util::keyControl() == SPACE) ? curPos + 1 : curPos;
        curPos = (curPos > 2) ? 0 : curPos;
    }
}