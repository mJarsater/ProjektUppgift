//Elias Klinth
//Martin Jarsäter
//grupp 70

#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Sprite.h"
#include "LevelHandler.h"

namespace game {

	class Session {
	public: 
		void run();
		~Session();
		void add(Sprite*);
		void remove(Sprite*);
		void delete_all();
		void next_level();
		void check_collision();
		void check_attack();
		std::vector<Sprite*>& get_sprites();
	private:
		std::vector<Sprite* > sprites;
		std::vector<Sprite* > added;
		std::vector<Sprite* > removed;
	};
	
	//extern Session ses;
}

#endif

