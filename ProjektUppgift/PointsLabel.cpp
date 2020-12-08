#include "PointsLabel.h"
#include "System.h"
#include <SDL_ttf.h>


namespace game {

	PointsLabel::PointsLabel(int x, int y, int w, int h, std::string text) : Label(x, y, w, h), text(text) {
		SDL_Surface* txtSurf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), { 255, 255, 255 });
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), txtSurf);
		SDL_FreeSurface(txtSurf);
	}

	PointsLabel* PointsLabel::get_instance(int x, int y, int w, int h, std::string text) {
		return new PointsLabel(x, y, w, h, text);
	}

	void PointsLabel::set_text(int num) {
		text = "Points: " + std::to_string(num);
		SDL_DestroyTexture(texture);
		SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), { 255,255,255 });
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		SDL_FreeSurface(surf);
		draw();
	}
}