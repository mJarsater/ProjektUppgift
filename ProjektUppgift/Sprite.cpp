//Elias Klinth
//Martin Jarsäter
//grupp 70

#include "Sprite.h"
#include <iostream>

namespace game {

	Sprite::Sprite(int x, int y, int w, int h)
		:rect{ x, y, w, h } {}

	Sprite::Sprite(){}

	Sprite::~Sprite() {
		SDL_DestroyTexture(texture);
	}

}
