#ifndef LABEL_H
#define LABEL_H
#include <string>
#include "Sprite.h"

namespace game {
	class Label : public Sprite
	{
	public:

		static Label* get_instance(int x, int y, int w, int h, std::string txt);
		void draw();
		void set_text(int);
		~Label();
	protected:
		Label(int x, int y, int w, int h, std::string txt);
	public:
		std::string text;
		SDL_Texture* texture;
	};

}
#endif 
