#include "../Includes/Display.hpp"
#include "../Includes/Util.hpp"

void drawTitle() {
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
    std::cout << "                ##  ##   ##  ##   ######    #####   ##  ##   ######  " << std::endl;
    std::cout << "                ## ##    ### ##     ##     ##       ##  ##     ##    " << std::endl;
    std::cout << "                ####     ######     ##     ##       ######     ##    " << std::endl;
    std::cout << "                ####     ######     ##     ## ###   ##  ##     ##    " << std::endl;
    std::cout << "                ## ##    ## ###     ##     ##  ##   ##  ##     ##    " << std::endl;
    std::cout << "                ##  ##   ##  ##   ######    #####   ##  ##     ##    " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
}

void drawMenu() {
    int x = DISPLAY_WIDTH / 2 - 10, y = DISPLAY_HEIGHT / 2;
    int curPos = 0;

    gotoxy(x, y);
    std::cout << "  GAME START";
    gotoxy(x, y + 1);
    std::cout << "  GAME INFO";
    gotoxy(x, y + 2);
    std::cout << "  GAME QUIT";

    while (true) {
        for (int i = 0; i <= 2; i++) {
            gotoxy(x, y + i);
            (i == curPos) ? std::cout << ">" : std::cout << " ";
        }
        
        curPos = (keyControl() == SPACE) ? curPos + 1 : curPos;
        curPos = (curPos > 2) ? 0 : curPos;

    }
    
}