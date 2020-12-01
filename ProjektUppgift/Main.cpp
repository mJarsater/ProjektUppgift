// Uppbyggnad av "spelet"
#include <iostream>
#include <SDL.h>
#include "Session.h"
#include "System.h"
#include "Shooter.h"

using namespace std;
using namespace game;


int main(int argc, char** argv)
{
	Session ses;
	Shooter* shooter = Shooter::get_instance(100, 100, 100, 100);
	
	
	ses.add(shooter);
	ses.run();



	return 0;
}