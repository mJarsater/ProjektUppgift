//Elias Klinth
//Martin Jarsäter
//grupp 70

#include "LevelHandler.h"
#include "System.h"
#include "Invader.h"

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

	void LevelHandler::spawn_invader() {
		switch (level) {
		case 1: {
			Invader* invader = Invader::get_instance("Images/invader.png");
			ses.add(invader);
			break;
		}
		case 2: {
			Invader* invader = Invader::get_instance("Images/invader2.png");
			ses.add(invader);
			break;
		}
		case 3: {
			Invader* invader = Invader::get_instance("Images/invader3.png");
			ses.add(invader);
			break;
		}
		case 4: {
			Invader* invader = Invader::get_instance("Images/invader4.png");
			ses.add(invader);
			break;
		}
		case 5: {
			Invader* invader = Invader::get_instance("Images/invader5.png");
			ses.add(invader);
			break;
		}
		default:
			Invader* invader = Invader::get_instance("Images/invader.png");
			ses.add(invader);
			break;
		}
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