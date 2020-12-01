#include "Shooter.h"
#include "System.h"
#include <SDL.h>
#include <SDL_image.h>

namespace game
{

	Shooter::Shooter(int x, int y, int w, int h): Sprite ( x,  y,  w,  h) {
		SDL_Surface* shooterSurf = IMG_Load("Images/shooter.png");
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), shooterSurf);
		SDL_Rect shooterRect = { x, y, w, h };
		SDL_FreeSurface(shooterSurf);
	}



	Shooter* Shooter::get_instance(int x, int y, int w, int h) {
		return new Shooter(x, y, w, h);
	}

	void Shooter::draw()const {
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &get_rect());
	}


	void game::Shooter::shoot(const SDL_Event&)
	{
		// Skapa nytt Blast
		// Skicka Blast från rätt y-kordinat
	}

	void game::Shooter::moveRight(const SDL_Event&)
	{
		shooterRect.y++;
	}

	void game::Shooter::moveLeft(const SDL_Event&)
	{
		shooterRect.y--;
	}

}