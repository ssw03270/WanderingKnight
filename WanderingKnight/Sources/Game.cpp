#include "../Includes/Game.hpp"
#include "../Includes/Util.hpp"
#include "../Includes/MainMenu.hpp"

void Game::gameInfo() {
    // set text pos
	int x = DISPLAY_WIDTH / 2 - 25, y = DISPLAY_HEIGHT / 2;

    // draw title
    MainMenu::drawTitle();

    // print game info
    Util::gotoxy(x, y);
    std::cout << "버전 : v0.1";
    Util::gotoxy(x, y + 1);
    std::cout << "제작자 : 나무둥지";
    Util::gotoxy(x, y + 2);
    std::cout << "오픈소스 : https://github.com/ssw03270/WanderingKnight";
    Util::gotoxy(x, y + 4);
    std::cout << "메뉴로 돌아가라면 '스페이스 바' 를 누르세요";

    while (true) {
        auto input = Util::keyControl();
        // if press space key
        if (input == SPACE) {
            return;
        }
    }
}