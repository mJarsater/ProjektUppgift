#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>

namespace game
{
	class Sprite
	{
	public:
		virtual ~Sprite();
		virtual void shoot(const SDL_Event&){}
		virtual void moveRight(const SDL_Event&){}
		virtual void moveLeft(const SDL_Event&){}
	protected:
		Sprite(int x, int y, int w, int h);
	private:
		SDL_Rect rect;
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;
	};

}
#endif
