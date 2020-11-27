#include "System.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

namespace game
{
	System::System()
	{
		std::cout << "Hej" << std::endl;
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 650, 800, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		SDL_Surface* bgSurface = SDL_LoadBMP("C:/Users/elias/Documents/CPROG/ProjektUppgift_media/bg.bmp");
		bgTex = SDL_CreateTextureFromSurface(ren, bgSurface);
		SDL_FreeSurface(bgSurface);
	}

	System::~System()
	{
		std::cout << "Hej då" << std::endl;
		SDL_DestroyTexture(bgTex);
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
	}

	SDL_Renderer* System::get_ren() const
	{
		return ren;
	}

	System sys;

}