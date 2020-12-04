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

	void Shooter::handleEvent(const SDL_Event& eve) {
		switch (eve.key.keysym.sym) {
		case SDLK_SPACE:
			// Loopa över sprites
			shoot(eve);
			break;
		case SDLK_RIGHT:
			moveRight(eve);
			break;
		case SDLK_LEFT:
			moveLeft(eve);
			break;
		}
	}

	void Shooter::draw()  {
		SDL_RenderCopy(sys.get_ren(), texture , NULL, &rect);
	}


	void Shooter::shoot(const SDL_Event&)
	{	
		Blast* b = Blast::get_instance(rect.x + (rect.w / 4), 600, 50, 50);
		ses.add(b);
	}

	void Shooter::moveRight(const SDL_Event&)
	{
		if (rect.x <= 540) {
			rect.x += 10;
		}
	}

	void Shooter::moveLeft(const SDL_Event&)
	{
		if (rect.x > 0) {
			rect.x -= 10;
		}
	}

	int Shooter::get_points() {
		return points_acquired;
	}

	void Shooter::set_points(int n) {
		points_acquired += n;
	}

	void Shooter::next_level() {
		points_acquired = 0; 
	}

	SDL_Texture* Shooter::get_texture() {
		return texture;
	}

	SDL_Rect& Shooter::get_rect() {
		return rect;
	}



}