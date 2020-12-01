#include <SDL.h>
#include "Session.h"
#include "System.h"
#include "Shooter.h"
#include <iostream>
/* SDL - Loop */
/* Skapa nya Invaders */
namespace game {


	void Session::add(Sprite* sprite) {
		sprites.push_back(sprite);
		std::cout << sprites.size()<< std::endl;
		for (int i = 0; i < sprites.size(); i++)
			std::cout << sprites.at(i) << std::endl;
	}


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
					for (Sprite* sprite : sprites)
						sprite->shoot(eve);
					break;

				case SDLK_RIGHT:
					// Loopa över sprites
					for (Sprite* sprite : sprites)
						sprite->moveRight(eve);
					break;

				case SDLK_LEFT:
					// Loopa över sprites
					for (Sprite* sprite : sprites)
						sprite->moveLeft(eve);
					break;
				}
			} // Inre while

			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			for (Sprite* s : sprites)
				s->draw();
			SDL_RenderPresent(sys.get_ren());
		}  // Yttre while
		
	}

	Session::~Session()
	{
	}
}