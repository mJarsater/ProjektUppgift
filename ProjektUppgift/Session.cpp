#include "Session.h"
#include <SDL.h>
/* SDL - Loop */
/* Skapa nya Invaders */
namespace game {

	void Session::run() {
		bool quit = false;

		while (!quit) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDLK_SPACE:
					// Loopa över sprites
					
					break;

				case SDLK_RIGHT:
					// Loopa över sprites
					
					break;

				case SDLK_LEFT:
					// Loopa över sprites
					
					break;
				}
			} // Inre while
		}  // Yttre while
		
	}

	Session::~Session()
	{
	}
}