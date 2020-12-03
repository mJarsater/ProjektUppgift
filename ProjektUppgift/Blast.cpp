#include "Blast.h"
#include "System.h"
#include <SDL.h>
#include <SDL_image.h>

namespace game {

	Blast::Blast(int x, int y, int w, int h) : Sprite(x, y, w, h) {
		SDL_Surface* blastSurf = IMG_Load("Images/blast.png");
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), blastSurf);
		rect = { x,y,w,h };
		SDL_FreeSurface(blastSurf);
	}

	Blast* Blast::get_instance(int x, int y, int w, int h) {
		return new Blast(x, y, w, h);
	}

	void Blast::draw() {
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
	}

	void Blast::tick() {
		if (rect.y <= -50) {
			ses.remove(this);
		} else {
			rect.y-=10;
		}
	}

	SDL_Texture* Blast::get_texture() {
		return texture;
	}

	SDL_Rect& Blast::get_rect() {
		return rect;
	}
}
