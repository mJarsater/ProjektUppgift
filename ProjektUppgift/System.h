#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include "Session.h"

namespace game
{
	class System
	{
	public:
		System();
		~System();
		SDL_Texture* get_tex() const;
		SDL_Renderer* get_ren() const;
		Session* get_session();
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		SDL_Texture* bgTex;
	};

	extern System sys;
	extern Session ses;
}

#endif
