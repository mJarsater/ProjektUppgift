//Elias Klinth
//Martin Jarsäter
//grupp 70

#include "Label.h"
#include "System.h"
#include "Sprite.h"
#include <SDL_ttf.h>
#include <string>
#include <iostream>


namespace game {

	Label::Label(int x, int y, int w, int h): Sprite(x,y,w,h) {}

	Label::Label(int x, int y, int w, int h, std::string text) : Sprite(x,y,w,h), text(text) {
		SDL_Surface* txtSurf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), { 255, 255, 255 });
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), txtSurf);
		SDL_FreeSurface(txtSurf);
	}

	Label* Label::get_instance(int x, int y, int w, int h, std::string text) {
		return new Label(x, y, w, h, text);
	}

	void Label::draw() {
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &get_rect());
	}

	Label::~Label() {
		SDL_DestroyTexture(texture);

	}

}