#include "Invader.h"
#include "System.h"
#include "Shooter.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <iostream>

namespace game {

	Invader::Invader(int x, int y, int w, int h) : Sprite(x, y, w, h) {
		SDL_Surface* invaderSurf = IMG_Load("Images/invader.png");
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), invaderSurf);
		rect = { x, y, w, h };
		SDL_FreeSurface(invaderSurf);
	}

	Invader::Invader(){
		SDL_Surface* invaderSurf = IMG_Load("Images/invader.png");
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), invaderSurf);
		int x = std::rand() % 590 + 10;
		rect = { x, -100, 100, 100 };
		SDL_FreeSurface(invaderSurf);
	}

	Invader* Invader::get_instance(int x, int y, int w, int h) {
		return new Invader(x, y, w, h);
	}

	Invader* Invader::get_instance()
	{
		return new Invader();
	}

	void Invader::draw() {
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
	}

	void Invader::tick() {
		if (rect.y >= 800) {
			ses.remove(this);
			take_life();
		}
		else {
			rect.y++;
		}
	}

	void Invader::take_life() {
		for (Sprite* shooter : ses.get_sprites())
			if (dynamic_cast<Shooter*>(shooter)){
				shooter->drop_life();
				std::cout << "ALIEN PASSED" << std::endl;
			}
	}

	void Invader::set_points(int n) {
		points += n;
	}

	int Invader::get_points() {
		return points;
	}

	SDL_Texture* Invader::get_texture() {
		return texture;
	}

	SDL_Rect& Invader::get_rect() {
		return rect;
	}
}