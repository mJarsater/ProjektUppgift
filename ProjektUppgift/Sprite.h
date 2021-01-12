//Elias Klinth
//Martin Jarsäter
//grupp 70

#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <string>
namespace game {

	class Sprite {
	public:
		virtual ~Sprite();
		virtual void drop_life(){}
		virtual void handleEvent(const SDL_Event&){}
		virtual void shoot(const SDL_Event&){}
		virtual void moveRight(const SDL_Event&){}
		virtual void moveLeft(const SDL_Event&){}
		virtual void draw() = 0;
		virtual void tick() {}
		virtual void set_text(int){}
		virtual void set_points(int n) {}
		virtual int get_points() { return NULL; }
		virtual void clear_points() {}
		virtual SDL_Texture* get_texture() { return texture; }
		virtual SDL_Rect& get_rect() { return rect; }
		//bool operator==(const Sprite& other);
	protected:
		Sprite(int x, int y, int w, int h);
		Sprite();
	private:
		SDL_Texture* texture;
		SDL_Rect rect;
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;
	};

}
#endif
