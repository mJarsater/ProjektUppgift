//Elias Klinth
//Martin Jarsäter
//grupp 70

#ifndef POINTSLABEL_H
#define POINTSLABEL_H
#include "Label.h"

namespace game {

	class PointsLabel : public Label
	{
	public:
		void set_text(int);
		static PointsLabel* get_instance(int x, int y, int w, int h, std::string txt);
	protected:
		PointsLabel(int x, int y, int w, int h, std::string txt);
		
	private:
		std::string text;
	};
}
#endif

