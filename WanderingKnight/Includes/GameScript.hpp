#ifndef __GAME_SCRIPT_H__
#define __GAME_SCRIPT_H__

#include<string>
#include<vector>

namespace GameScript {
	class Script {
	private:
		int scriptCode;
		std::string region;
		std::string text;
	public:
		void setScriptCode(int);
		void setRegion(std::string);
		void setText(std::string);

		int getScriptCode();
		std::string getRegion();
		std::string getText();

		std::vector<std::string> getWord(std::string);
	};
}

#endif // !__GAME_SCRIPT_H__
