#ifndef __GAME_SCRIPT_H__
#define __GAME_SCRIPT_H__

#include<string>
#include<vector>

namespace GameScript {
	class Script {
	private:
		int scriptCode;
		int nextCode;
		std::string region;
		std::string text;
		std::vector<std::string> selection;
	public:
		void setScriptCode(int);
		void setNextCode(int);
		void setRegion(std::string);
		void setText(std::string);
		void setSelection(std::vector<std::string>);

		int getScriptCode();
		int getNextCode();
		std::string getRegion();
		std::string getText();
		std::vector<std::string> getSelection();

		std::vector<std::string> getWord(std::string);
	};
}

#endif // !__GAME_SCRIPT_H__
