#ifndef INVADER_H
#define INVADER_H
#include "Sprite.h"
#include <SDL.h>

namespace game
{
	class Invader : public Sprite
	{
	public: 

		// Virtual om vi vill ha subklasser till invader
		virtual void attack();
	
		static Invader* get_instance();
		
		Invader();
	private:
	// Poäng för 
		int point;
		bool isAlive = true;
		SDL_Texture* texture;
	};

}
#endif