#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <SDL_ttf.h>
#include "Session.h"
#include "LevelHandler.h"

namespace game
{
	class System
	{
	public:
		System();
		~System();
		void set_background(std::string);
		SDL_Texture* get_tex() const;
		SDL_Renderer* get_ren() const;
		TTF_Font* get_font() const;
		Session* get_session();
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		SDL_Texture* bgTex;
		TTF_Font* font;
	};

	extern System sys;
	extern Session ses;
	extern LevelHandler levelHandler;
}

#endif
