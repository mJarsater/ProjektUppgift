#ifndef SHOOTER_H
#define SHOOTER_H
#include "Sprite.h"

namespace game
{
	class Shooter : public Sprite
	{
	public:
		void shoot(const SDL_Event&);
		void moveRight(const SDL_Event&);
		void moveLeft(const SDL_Event&);
	};
}
#endif
