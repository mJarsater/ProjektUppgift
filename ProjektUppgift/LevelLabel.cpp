//Elias Klinth
//Martin Jarsäter
//grupp 70

#include "LevelLabel.h"
#include "System.h"
#include <SDL_ttf.h>


namespace game {

	LevelLabel::LevelLabel(int x, int y, int w, int h, std::string text) : Label(x, y, w, h), text(text) {
		SDL_Surface* txtSurf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), { 255, 255, 255 });
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), txtSurf);
		SDL_FreeSurface(txtSurf);
	}

	LevelLabel* LevelLabel::get_instance(int x, int y, int w, int h, std::string text) {
		return new LevelLabel(x, y, w, h, text);
	}

	void LevelLabel::set_text(int num) {
		text = "Level: " + std::to_string(num);
		SDL_DestroyTexture(texture);
		SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), { 255,255,255 });
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		SDL_FreeSurface(surf);
		draw();
	}

}