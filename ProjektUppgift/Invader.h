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
		virtual SDL_Texture* get_texture();
		virtual SDL_Rect& get_rect();
	protected:
		Invader(int x, int y, int w, int h);
		Invader();
	private:
	// Poäng för 
		int point;
		bool isAlive = true;
		SDL_Texture* texture;
		SDL_Rect rect;
	};

}
#endif