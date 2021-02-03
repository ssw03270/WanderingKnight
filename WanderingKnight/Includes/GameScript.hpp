#ifndef __GAME_SCRIPT_H__
#define __GAME_SCRIPT_H__

#include<string>

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
	};
}

#endif // !__GAME_SCRIPT_H__
