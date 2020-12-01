#include "Shooter.h"
#include "System.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

namespace game
{
	Shooter::Shooter(int x, int y, int w, int h): Sprite ( x,  y,  w,  h) {
		SDL_Surface* shooterSurf = IMG_Load("Images/shooter.png");
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


	void Shooter::shoot(const SDL_Event&)
	{
		// Skapa nytt Blast
		// Skicka Blast från rätt y-kordinat
	}

	void Shooter::moveRight(const SDL_Event&)
	{
		rect.x+=10;
		std::cout << rect.x << std::endl;
		std::cout << "Höger" << std::endl;
	}

	void Shooter::moveLeft(const SDL_Event&)
	{
		rect.x-=10;
		std::cout << rect.x << std::endl;
		std::cout << "Vänster" << std::endl;
	}

	SDL_Texture* Shooter::get_texture() {
		return texture;
	}

	SDL_Rect& Shooter::get_rect() {
		return rect;
	}

}