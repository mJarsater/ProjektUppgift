//Elias Klinth
//Martin Jarsäter
//grupp 70

#ifndef LEVELLABEL_H
#define LEVELLABEL_H
#include "Label.h"

namespace game {

	class LevelLabel : public Label {
	public:
		static LevelLabel* get_instance(int x, int y, int w, int h, std::string txt);
		void set_text(int);
	protected:
		LevelLabel(int x, int y, int w, int h, std::string txt);
	private:
		std::string text;
	};

}
#endif

