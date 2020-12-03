#include "Shooter.h"
#include "System.h"
#include "Blast.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

namespace game
{
	Shooter::Shooter(int x, int y, int w, int h): Sprite ( x,  y,  w,  h) {
		SDL_Surface* shooterSurf = IMG_Load("Images/greenshooter.png");
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), shooterSurf);
		rect = { x, y, w, h };
		SDL_FreeSurface(shooterSurf);
	}

	Shooter* Shooter::get_instance(int x, int y, int w, int h) {
		return new Shooter(x, y, w, h);
	}

	void Shooter::draw()  {
		SDL_RenderCopy(sys.get_ren(), texture , NULL, &rect);
	}


	Sprite* Shooter::shoot(const SDL_Event&)
	{	
		std::cout << "SKJUTER" << std::endl;
		// Skapa nytt Blast
		Blast* b = Blast::get_instance(100, 250, 50, 50);
		return b;
		// Skicka Blast från rätt y-kordinat
	}

	void Shooter::moveRight(const SDL_Event&)
	{
		rect.x+=10;
	}

	void Shooter::moveLeft(const SDL_Event&)
	{
		rect.x-=10;
	}

	SDL_Texture* Shooter::get_texture() {
		return texture;
	}

	SDL_Rect& Shooter::get_rect() {
		return rect;
	}

}