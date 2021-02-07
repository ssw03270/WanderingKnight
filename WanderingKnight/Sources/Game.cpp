#include <Game.hpp>
#include <Util.hpp>
#include <MainMenu.hpp>
#include <GameScript.hpp>

void Game::drawLine() {
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
    GameScript::Script* script = Util::readScript("/Adventure/GameScript.json");

    // playing game
    int code = 0;
    while (true) {
        // set text pos
        int x = DISPLAY_WIDTH / 4, y = DISPLAY_HEIGHT / 2;

        // draw title
        MainMenu::drawTitle();
        // draw ui
        Game::drawLine();
        // draw player stat
        Game::playerStat();

        // set script value;
        int scriptCode = script[code].getScriptCode();
        int nextCode = script[code].getNextCode();
        std::string region = script[code].getRegion();
        std::string text = script[code].getText();
        std::vector<std::string> selection = script[code].getSelection();
        std::vector<int> selectionCode = script[code].getSelectionCode();

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

        // more than one selection
        if (selection.size() > 0) {
            int choice = Game::gameSelection(selection);
            code = selectionCode[choice];
        }
        // there is no selection
        else {
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
    
}

void Game::playerStat() {
    // get script
    PlayerInfo::Player player = Util::readPlayer("/Player/PlayerInfo.json");

    // set text pos
    int x = DISPLAY_WIDTH - DISPLAY_WIDTH / 4, y = DISPLAY_HEIGHT / 2 + 1;

    // set script value;
    std::string playerName = player.getPlayerName();
    int playerLevel = player.getPlayerLevel();
    int playerExp = player.getPlayerExp();
    int playerMaxExp = player.getPlayerMaxEXP();
    int playerHP = player.getPlayerHP();
    int playerMaxHP = player.getPlayerMaxHP();
    int playerSTR = player.getPlayerSTR();
    int playerLUK = player.getPlayerLUK();
    int playerINT = player.getPlayerINT();
    int playerFame = player.getPlayerFame();
    std::vector<int> maxExp = player.getMaxEXP();

    playerMaxExp = maxExp[playerLevel];

    Util::gotoxy(x - 8, y + 2);
    std::cout << "플레이어 능력치";
    Util::gotoxy(x - 15, y + 4);
    std::cout << "이름 : " << playerName;
    Util::gotoxy(x - 15, y + 6);
    std::cout << "레벨 : " << playerLevel;
    Util::gotoxy(x - 15, y + 8);
    std::cout << "경험치 : ";
    Game::drawPercentage((float)playerExp / (float)playerMaxExp, 8);
    Util::gotoxy(x - 15, y + 10);
    std::cout << "체력 : ";
    Game::drawPercentage((float)playerHP / (float)playerMaxHP, 10);
    Util::gotoxy(x - 15, y + 12);
    std::cout << "근력 : " << playerSTR;
    Util::gotoxy(x - 5, y + 12);
    std::cout << "명예 : " << playerFame;
    Util::gotoxy(x - 15, y + 14);
    std::cout << "지능 : " << playerINT;
    Util::gotoxy(x - 5, y + 14);
    std::cout << "운 : " << playerLUK;
}

void Game::drawPercentage(float percentage, int plusY) {
    // set text pos
    int x = DISPLAY_WIDTH - DISPLAY_WIDTH / 4, y = DISPLAY_HEIGHT / 2 + 1;

    Util::gotoxy(x - 8, y + plusY);
    float stand = 0.1f;
    for (int i = 1; i <= 10; i++) {
        stand = 0.1f * i;
        if (percentage >= stand) {
            std::cout << "■";
        }
        else {
            std::cout << "□";
        }
    }
}

int Game::gameSelection(std::vector<std::string> selection) {
    int x = 5, y = DISPLAY_HEIGHT - DISPLAY_HEIGHT / 8 ;
    int curPos = 0;

    // print selection
    for (int i = 0; i < selection.size(); i++) {
        Util::gotoxy(x, y + i);
        std::cout << selection[i];
    }

    while (true) {
        for (int i = 0; i < selection.size(); i++) {
            Util::gotoxy(x, y + i);
            (i == curPos) ? std::cout << ">" : std::cout << " ";
        }
        auto input = Util::keyControl();
        // If input SPACE key, curPos increase
        input == SPACE ? (curPos = (curPos >= selection.size() - 1) ? 0 : curPos + 1) : false;
        // If input ENTER key, something start
        if (input == ENTER) return curPos;
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