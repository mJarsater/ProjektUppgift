#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>

namespace game
{
	class Sprite
	{
	public:
		virtual ~Sprite();
		virtual Sprite* shoot(const SDL_Event&) { return NULL; }
		virtual void moveRight(const SDL_Event&){}
		virtual void moveLeft(const SDL_Event&){}
		virtual void draw() = 0;
		virtual SDL_Texture* get_texture() = 0;
		virtual SDL_Rect& get_rect() = 0;
	protected:
		Sprite(int x, int y, int w, int h);
	private:
		SDL_Texture* texture;
		SDL_Rect rect;
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;
	};

}
#endif
