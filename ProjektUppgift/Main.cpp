// Uppbyggnad av "spelet"
#include <iostream>
#include <SDL.h>
#include "Session.h"
#include "System.h"
#include "Shooter.h"
#include "Blast.h"

using namespace std;
using namespace game;


int main(int argc, char** argv)
{
	Session ses;
	Shooter* shooter = Shooter::get_instance(0, 650, 100, 100);
	Blast* blast = Blast::get_instance(100, 100, 100, 100);
	
	ses.add(shooter);
	ses.add(blast);
	ses.run();



	return 0;
}