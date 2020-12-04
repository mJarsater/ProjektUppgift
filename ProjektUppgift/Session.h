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
	private:
		std::vector<Sprite* > sprites;
		std::vector<Sprite* > added;
		std::vector<Sprite* > removed;
		int level;
	};

	//extern Session ses;
}

#endif

