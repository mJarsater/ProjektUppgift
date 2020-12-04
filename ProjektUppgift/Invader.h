#ifndef INVADER_H
#define INVADER_H
#include "Sprite.h"
#include <SDL.h>

namespace game
{
	class Invader : public Sprite
	{
	public: 	
		static Invader* get_instance(int x, int y, int w, int h);
		static Invader* get_instance();
		void attack();
		void draw();
		void tick();
		void set_points(int n);
		int get_points();
		virtual SDL_Texture* get_texture();
		virtual SDL_Rect& get_rect();
	protected:
		Invader(int x, int y, int w, int h);
		Invader();
	private:
		int points = 100;
		SDL_Texture* texture;
		SDL_Rect rect;
	};

}
#endif