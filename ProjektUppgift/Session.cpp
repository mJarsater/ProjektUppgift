#include <SDL.h>
#include "Session.h"
#include "System.h"
#include "Shooter.h"
#include <iostream>
/* SDL - Loop */
/* Skapa nya Invaders */
namespace game {

	void Session::add(Sprite* sprite) {
		added.push_back(sprite);
		for (Sprite* sprite : added) {
			std::cout << "ADD: ";
			std::cout << sprite << std::endl;
		}
	}

	void Session::remove(Sprite* sprite) {
		removed.push_back(sprite);
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
				case SDL_KEYDOWN:
					switch (eve.key.keysym.sym) {
					case SDLK_SPACE:
						// Loopa över sprites
						for (Sprite* sprite : sprites) {
							Sprite* b = sprite->shoot(eve);
							add(b);
						}
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
					}// Inre Switch
				}// Yttre switch
			} // Inre while

			
			for (Sprite* c : added) {
				std::cout << "I LOOPEN";
				sprites.push_back(c);
			}
			added.clear();
			

			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			SDL_RenderCopy(sys.get_ren(), sys.get_tex(), NULL, NULL);
			for (Sprite* s : sprites)
				s->draw();
			SDL_RenderPresent(sys.get_ren());

			
		}  // Yttre while
		
	}

	Session::~Session()
	{
	}
}