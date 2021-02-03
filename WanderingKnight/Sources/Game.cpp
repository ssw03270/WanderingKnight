#include <Game.hpp>
#include <Util.hpp>
#include <MainMenu.hpp>
#include <GameScript.hpp>

void Game::drawUI() {
    // set text pos
    int x = 0, y = DISPLAY_HEIGHT / 2;

    // print ui
    Util::gotoxy(x, y);
    std::cout << "######################################################################################";
    x = DISPLAY_WIDTH / 2;
    for (int i = 0; y + i < DISPLAY_HEIGHT; i++) {
        Util::gotoxy(x, y + i);
        std::cout << "#";
    }
}

void Game::gameStart() {
    // set text pos
    int x = DISPLAY_WIDTH / 4, y = DISPLAY_HEIGHT / 2;

    // draw title
    MainMenu::drawTitle();
    // draw ui
    Game::drawUI();

    GameScript::Script script = Util::readJson();

    // set script value;
    std::string region = script.getRegion();
    std::string text = script.getText();
    std::vector<std::string> wordList = script.getWord(text);

    // print region
    Util::gotoxy(x - region.size() / 2 + 1, y + 3);
    std::cout << region;

    // print tex
    x = 5, y += 6;
    std::string textOutput = "";
    int line = 0;
    for (int i = 0; i < wordList.size(); i++) {
        Util::gotoxy(x, y);
        textOutput += wordList[i] + ' ';
        std::cout << textOutput;

        if (textOutput.size() / (DISPLAY_WIDTH / 2 + 5) > line) {
            line += 1;
            textOutput += "\n\n    ";
        }

        Sleep(150);
    }

    
    while (true) {
        auto input = Util::keyControl();
        // if press space key
        if (input == SPACE) {
            return;
        }
    }
}

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