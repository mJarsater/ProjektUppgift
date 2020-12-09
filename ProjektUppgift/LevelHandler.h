#ifndef LEVELHANDLER_H
#define LEVELHANDLER_H

namespace game {

	class LevelHandler
	{
	public:
		LevelHandler();
		void set_tickNumber(int n);
		int& get_level();
		int& get_tickNumber();
		void handleLevel();
		void inc_level();
		void spawn_invader();
		void decr_tickNumber();
		~LevelHandler(){}
	private:
		int level = 1;
		int tickNumber;
	};

}
#endif
