#include "LevelHandler.h"
#include "System.h"

namespace game {
	int& LevelHandler::get_level() {
		return level;
	}

	int& LevelHandler::get_tickNumber() {
		return tickNumber;
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
			sys.set_background("Images/bg2.jpg");
			break;
		case 3:
			sys.set_background("Images/bg3.jpg");
			break;
		case 4:
			sys.set_background("Images/bg4.jpg");
			break;
		case 5:
			sys.set_background("Images/bg5.jpg");
			break;
		case 6:
			sys.set_background("Images/bg6.jpg");
			break;
		}
	}

	void LevelHandler::inc_level() {
		level++;
	}

	void LevelHandler::decr_tickNumber() {
		tickNumber -= 40;
	}

	LevelHandler::LevelHandler() : level(1), tickNumber(400) {}
}