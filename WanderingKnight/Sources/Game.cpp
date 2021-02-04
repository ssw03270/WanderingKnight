#include <Game.hpp>
#include <Util.hpp>
#include <MainMenu.hpp>
#include <GameScript.hpp>

void Game::drawUI() {
    // set text pos
    int x = 0, y = DISPLAY_HEIGHT / 2;

    // print ui
    Util::gotoxy(x, y);
    // horizontal
    std::cout << "######################################################################################";
    //vertical
    x = DISPLAY_WIDTH / 2;
    for (int i = 0; y + i < DISPLAY_HEIGHT; i++) {
        Util::gotoxy(x, y + i);
        std::cout << "#";
    }
}

void Game::gameStart() {
    // get script
    GameScript::Script* script = Util::readJson("GameScript.json");


    int code = 0;
    while (true) {
        // set text pos
        int x = DISPLAY_WIDTH / 4, y = DISPLAY_HEIGHT / 2;

        // draw title
        MainMenu::drawTitle();
        // draw ui
        Game::drawUI();

        // set script value;
        int scriptCode = script[code].getScriptCode();
        int nextCode = script[code].getNextCode();
        std::string region = script[code].getRegion();
        std::string text = script[code].getText();
        std::vector<std::string> selection = script[code].getSelection();

        std::vector<std::string> wordList = script[code].getWord(text);

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

            if (textOutput.size() / ((DISPLAY_WIDTH - 5) / 2) > line) {
                line += 1;
                int alpha = textOutput.size();
                textOutput += "\n\n    ";
            }

             Sleep(100);
        }

        while (true) {
            auto input = Util::keyControl();
            // if press space key
            if (input == SPACE) {
                code = nextCode;
                if (code == -1) {
                    delete[] script;
                    return;
                }
                else {
                    break;
                }
            }
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