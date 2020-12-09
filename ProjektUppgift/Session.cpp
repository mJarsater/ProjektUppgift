#include <SDL.h>
#include "Blast.h"
#include "Invader.h"
#include "Session.h"
#include "System.h"
#include "Shooter.h"
#include <iostream>
#include "Label.h"
#include "PointsLabel.h"
#include "LevelLabel.h"
#define FPS 60
/* SDL - Loop */
/* Skapa nya Invaders */
namespace game {

	std::vector<Sprite*>& Session::get_sprites() {
		return sprites;
	}

	void Session::add(Sprite* sprite) {
		added.push_back(sprite);
	}

	void Session::remove(Sprite* sprite) {
		removed.push_back(sprite);
	}

	void Session::next_level() {
		levelHandler.inc_level();
		levelHandler.handleLevel();
		levelHandler.decr_tickNumber();
		for(Sprite* shooter: sprites)
			if (dynamic_cast<Shooter*>(shooter)) {
				shooter->clear_points();
				for (Sprite* label : sprites) {
					if (dynamic_cast<PointsLabel*>(label))
						label->set_text(shooter->get_points());
					if (dynamic_cast<LevelLabel*>(label))
						label->set_text(levelHandler.get_level());
				}
			}
	}

	void Session::check_collision() {
		for (Sprite* blast : sprites) {
			if (dynamic_cast<Blast*>(blast)) {
				for (Sprite* invader : sprites) {
					if (dynamic_cast<Invader*>(invader)) {
						if ((blast->get_rect().y <= invader->get_rect().y + (invader->get_rect().h) / 2) &&
							(blast->get_rect().x >= invader->get_rect().x &&
								blast->get_rect().x < invader->get_rect().x + (invader->get_rect().w) / 2)) {
							for (Sprite* shooter : sprites)
								if (dynamic_cast<Shooter*>(shooter)) {
									shooter->set_points(invader->get_points());
									for (Sprite* label : sprites) {
										if (dynamic_cast<PointsLabel*>(label))
											label->set_text(shooter->get_points());
										if (dynamic_cast<LevelLabel*>(label))
											label->set_text(levelHandler.get_level());
									}
								}
							remove(blast);
							remove(invader);
						}
					}
				}
			}
		}
	}

	void Session::check_attack() {
		for (Sprite* shooter : sprites) {
			if (dynamic_cast<Shooter*>(shooter)) {
				for (Sprite* invader : sprites) {
					if (dynamic_cast<Invader*>(invader)) {
						if (invader->get_rect().y == shooter->get_rect().y + (shooter->get_rect().w / 2) &&
							(invader->get_rect().x >= shooter->get_rect().x &&
								invader->get_rect().x < shooter->get_rect().x + (invader->get_rect().w) / 2)) {
							shooter->drop_life();
							remove(invader);
						}
					}
				}
			}
		}
	}

	void Session::run() {
		bool quit = false;
		Uint32 tickInterval = 500 / FPS;
		int counter = 0;
		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYDOWN:
					for (Sprite* sprite : sprites)
						sprite->handleEvent(eve);
				}
			}

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
						delete c;
					}
					else {
						i++;
					}
				}
			}

			added.clear();
			removed.clear();

			check_collision();
			check_attack();

			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			SDL_RenderCopy(sys.get_ren(), sys.get_tex(), NULL, NULL);

			for (Sprite* s : sprites) {
				s->draw();
			}

			SDL_RenderPresent(sys.get_ren());

			for (Sprite* shooter : sprites)
				if (dynamic_cast<Shooter*>(shooter)) {
					if (shooter->get_points() == 1000) {
						next_level();
					}
				}


			int delay = nextTick - SDL_GetTicks();
			if (delay > 0) {
				SDL_Delay(delay);
			}



			if (levelHandler.get_level() != 0) {
				if (counter % levelHandler.get_tickNumber() == 0) {
					levelHandler.spawn_invader();
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