#ifndef SHOOTER_H
#define SHOOTER_H
#include "Sprite.h"

namespace game
{
	class Shooter : public Sprite
	{
	public:
		static Shooter* get_instance(int x, int y, int w, int h);
		void draw()const;
		void shoot(const SDL_Event&);
		void moveRight(const SDL_Event&);
		void moveLeft(const SDL_Event&);
	protected:
		Shooter(int x, int y, int w, int h);
	private:
		SDL_Texture* texture;
		SDL_Rect shooterRect;
	
	};
}
#endif
