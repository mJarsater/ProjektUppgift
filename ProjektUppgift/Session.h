#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Sprite.h"

namespace game
{
	class Session
	{
	public: 
		void run();
		~Session();
		void add(Sprite*);
		void remove(Sprite*);
		void next_level();
		void check_collision();
		void check_attack();
		std::vector<Sprite*>& get_sprites();
	private:
		std::vector<Sprite* > sprites;
		std::vector<Sprite* > added;
		std::vector<Sprite* > removed;
		int level;
	};

	//extern Session ses;
}

#endif

