#include <SDL.h>
#include "Blast.h"
#include "Invader.h"
#include "Session.h"
#include "System.h"
#include "Shooter.h"
#include <iostream>
#define FPS 60
/* SDL - Loop */
/* Skapa nya Invaders */
namespace game {

	void Session::add(Sprite* sprite) {
		added.push_back(sprite);
	}

	void Session::remove(Sprite* sprite) {
		removed.push_back(sprite);
	}

	void Session::run() {
		bool quit = false;
		Uint32 tickInterval = 1000 / FPS;
		int counter = 0;
		level = 200;
		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
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
							sprite->shoot(eve);
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
				sprites.push_back(c);
			}

			for (Sprite* c : sprites) {
				c->tick();
			}

			for (Sprite* c : removed) {
				for (std::vector<Sprite*>::iterator i = sprites.begin();
					i != sprites.end();) {
					if (*i == c) {
						i = sprites.erase(i);
					}
					else {
						i++;
					}
				}
			}

			added.clear();
			removed.clear();

			for (Sprite* blast : sprites) {
				if (dynamic_cast<Blast*>(blast)) {
					for (Sprite* invader : sprites) {
						if (dynamic_cast<Invader*>(invader)) {
							if ((blast->get_rect().y <= invader->get_rect().y + (invader->get_rect().h) / 2) &&
								(blast->get_rect().x >= invader->get_rect().x &&
									blast->get_rect().x < invader->get_rect().x + (invader->get_rect().w) / 2)) {
								for (Sprite* shooter : sprites)
									if (dynamic_cast<Shooter*>(shooter)) {
										std::cout << "Invader:" << invader->get_points() << std::endl;
										shooter->set_points(invader->get_points());
										std::cout << "Shooter:" << shooter->get_points() << std::endl;
									}
								remove(blast);
								remove(invader);
							}
						}
					}
				}
			}

			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			SDL_RenderCopy(sys.get_ren(), sys.get_tex(), NULL, NULL);

			for (Sprite* s : sprites) {
				s->draw();
			}

			SDL_RenderPresent(sys.get_ren());

			for (Sprite* shooter : sprites)
				if (dynamic_cast<Shooter*>(shooter)) {
					if (shooter->get_points() >= 1000) {
						std::cout << "NEXT LEVEL" << std::endl;
						shooter->next_level();
						level -= 20;
					}
				}


			int delay = nextTick - SDL_GetTicks();
			if (delay > 0) {
				SDL_Delay(delay);
			}

			if (level != 0) {
				if (counter % level == 0) {
					Invader* invader = Invader::get_instance();
					ses.add(invader);
				}
			}
			else {
				exit(-1);
			}

			counter++;

		}  // Yttre while

	}

	Session::~Session()
	{
	}
}