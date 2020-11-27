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
		SDL_Surface* bgSurface = IMG_Load("C:/Users/elias/Documents/CPROG/ProjektUppgift_media/bg.png");
		bgTex = SDL_CreateTextureFromSurface(ren, bgSurface);
		SDL_RenderCopy(ren, bgTex, NULL, NULL);
		SDL_FreeSurface(bgSurface);
		SDL_RenderPresent(ren);
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