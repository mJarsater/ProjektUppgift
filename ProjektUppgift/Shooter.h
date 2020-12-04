#ifndef SHOOTER_H
#define SHOOTER_H
#include "Sprite.h"

namespace game
{
	class Shooter : public Sprite
	{
	public:
		static Shooter* get_instance(int x, int y, int w, int h);
		void handleEvent(const SDL_Event&);
		void draw();
		void shoot(const SDL_Event&);
		void moveRight(const SDL_Event&);
		void moveLeft(const SDL_Event&);
		void set_points(int);
		int get_points();
		void clear_points();
		virtual SDL_Texture* get_texture();
		virtual SDL_Rect& get_rect();
	protected:
		Shooter(int x, int y, int w, int h);
	private:
		int points_acquired;
		SDL_Texture* texture;
		SDL_Rect rect;
	
	};
}
#endif
