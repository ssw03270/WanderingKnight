#ifndef __PLAYER_INFO_H__
#define __PLAYER_INFO_H__

#include<string>
#include<vector>

namespace PlayerInfo {
	class Player {
	private:
		std::string playerName;
		int playerLevel;
		int playerExp;
		int playerMaxExp;
		int playerHP;
		int playerMaxHP;
		int playerSTR;
		int playerLUK;
		int playerINT;
		int playerFame;
		std::vector<int> maxExp;

	public:
		void setPlayerName(std::string);
		void setPlayerLevel(int);
		void setPlayerExp(int);
		void setPlayerMaxEXP(int);
		void setPlayerHP(int);
		void setPlayerMaxHP(int);
		void setPlayerSTR(int);
		void setPlayerLUK(int);
		void setPlayerINT(int);
		void setPlayerFame(int);
		void setMaxEXP(std::vector<int>);

		std::string getPlayerName();
		int getPlayerLevel();
		int getPlayerExp();
		int getPlayerMaxEXP();
		int getPlayerHP();
		int getPlayerMaxHP();
		int getPlayerSTR();
		int getPlayerLUK();
		int getPlayerINT();
		int getPlayerFame();
		std::vector<int> getMaxEXP();
	};
}

#endif // !__PLAYER_INFO_H__
