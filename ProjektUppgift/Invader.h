#ifndef INVADER_H
#define INVADER_H
#include "Sprite.h"
#include <SDL.h>

namespace game
{
	class Invader : public Sprite
	{
	public: 	
		static Invader* get_instance(std::string);
		void take_life();
		void draw();
		void tick();
		void set_points(int n);
		int get_points();
		virtual SDL_Texture* get_texture();
		virtual SDL_Rect& get_rect();
	protected:
		Invader(std::string);
	private:
		int points = 100;
		SDL_Texture* texture;
		SDL_Rect rect;
	};

}
#endif