#include <PlayerInfo.hpp>

void PlayerInfo::Player::setPlayerName(std::string playerName) { PlayerInfo::Player::playerName = playerName; }
void PlayerInfo::Player::setPlayerLevel(int playerLevel) { PlayerInfo::Player::playerLevel = playerLevel; }
void PlayerInfo::Player::setPlayerExp(int playerExp) { PlayerInfo::Player::playerExp = playerExp; }
void PlayerInfo::Player::setPlayerMaxEXP(int playerMaxExp) { PlayerInfo::Player::playerMaxExp = playerMaxExp; }
void PlayerInfo::Player::setPlayerHP(int playerHP) { PlayerInfo::Player::playerHP = playerHP; }
void PlayerInfo::Player::setPlayerMaxHP(int playerMaxHP) { PlayerInfo::Player::playerMaxHP = playerMaxHP; }
void PlayerInfo::Player::setPlayerSTR(int playerSTR) { PlayerInfo::Player::playerSTR = playerSTR; }
void PlayerInfo::Player::setPlayerLUK(int playerLUK) { PlayerInfo::Player::playerLUK = playerLUK; }
void PlayerInfo::Player::setPlayerINT(int playerINT) { PlayerInfo::Player::playerINT = playerINT; }
void PlayerInfo::Player::setPlayerFame(int playerFame) { PlayerInfo::Player::playerFame = playerFame; }
void PlayerInfo::Player::setMaxEXP(std::vector<int> maxExp) { PlayerInfo::Player::maxExp = maxExp; }

std::string PlayerInfo::Player::getPlayerName() { return PlayerInfo::Player::playerName; }
int PlayerInfo::Player::getPlayerLevel(){ return PlayerInfo::Player::playerLevel; }
int PlayerInfo::Player::getPlayerExp() { return PlayerInfo::Player::playerExp; }
int PlayerInfo::Player::getPlayerMaxEXP() { return PlayerInfo::Player::playerMaxExp; }
int PlayerInfo::Player::getPlayerHP() { return PlayerInfo::Player::playerHP; }
int PlayerInfo::Player::getPlayerMaxHP() { return PlayerInfo::Player::playerMaxHP; }
int PlayerInfo::Player::getPlayerSTR() { return PlayerInfo::Player::playerSTR; }
int PlayerInfo::Player::getPlayerLUK() { return PlayerInfo::Player::playerLUK; }
int PlayerInfo::Player::getPlayerINT() { return PlayerInfo::Player::playerINT; }
int PlayerInfo::Player::getPlayerFame() { return PlayerInfo::Player::playerFame; }
std::vector<int> PlayerInfo::Player::getMaxEXP() { return PlayerInfo::Player::maxExp; }