#ifndef LEVELHANDLER_H
#define LEVELHANDLER_H

namespace game {

	class LevelHandler
	{
	public:
		LevelHandler(int, int);
		void set_tickNumber(int n);
		int& get_level();
		int& get_tickNumber();
		void next_level();
		void handleLevel();
		~LevelHandler(){}
	private:
		int level;
		int tickNumber;
	};

}
#endif
