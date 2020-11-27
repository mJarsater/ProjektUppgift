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

	private:
		std::vector<Sprite* > sprites;
	};
}

#endif

