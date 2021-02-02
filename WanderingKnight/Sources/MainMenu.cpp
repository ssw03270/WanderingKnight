#include "../Includes/MainMenu.hpp"
#include "../Includes/Util.hpp"

// Draw title in consol
void MainMenu::drawTitle() {
    // clear consol
    system("cls");

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
int MainMenu::drawMenu() {
    // set text pos
    int x = DISPLAY_WIDTH / 2 - 10, y = DISPLAY_HEIGHT / 2;
    int curPos = 0;

    // draw title
    MainMenu::drawTitle();

    // print menu
    Util::gotoxy(x, y);
    std::cout << "  게임 시작";
    Util::gotoxy(x, y + 1);
    std::cout << "  게임 정보";
    Util::gotoxy(x, y + 2);
    std::cout << "  게임 종료";

    // If input ENTER key, move curser
    while (true) {
        for (int i = 0; i <= 2; i++) {
            Util::gotoxy(x, y + i);
            (i == curPos) ? std::cout << ">" : std::cout << " ";
        }
        
        auto input = Util::keyControl();
        // If input SPACE key, curPos increase
        input == SPACE ? (curPos = (curPos >= 2) ? 0 : curPos + 1) : false;
        // If input ENTER key, something start
        if (input == ENTER) return curPos;
    }
}