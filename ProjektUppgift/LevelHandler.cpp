#include "LevelHandler.h"
#include "System.h"

namespace game {
	int& LevelHandler::get_level() {
		return level;
	}

	int& LevelHandler::get_tickNumber() {
		return tickNumber;
	}

	void LevelHandler::next_level() {
		level++;
		sys.set_background("Images/bg_level2.jpg");
	}

	void LevelHandler::set_tickNumber(int n) {
		tickNumber = n;
	}

	void LevelHandler::handleLevel() {
		switch (level) {
		case 1:
			sys.set_background("Images/bg.jpg");
			break;
		case 2:
			sys.set_background("Images/bg_level2.jpg");
			break;
		}
	}

	LevelHandler::LevelHandler(int level, int tickNumber) : level(level), tickNumber(tickNumber) {}
}