#ifndef BLAST_H
#define BLAST_H
#include "Sprite.h"

namespace game
{
	class Blast : public Sprite
	{
	public:
		static Blast* get_instance(int x, int y, int w, int h);
		void draw();
		void tick();
		virtual SDL_Texture* get_texture();
		virtual SDL_Rect& get_rect();
	protected:
		Blast(int x, int y, int w, int h);
	private:
		SDL_Texture* texture;
		SDL_Rect rect;
	};
}
#endif
