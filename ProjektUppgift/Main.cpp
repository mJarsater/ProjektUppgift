// Uppbyggnad av "spelet"
#include <iostream>
#include <SDL.h>
#include "Session.h"
#include "System.h"
#include "Shooter.h"
#include "Blast.h"
#include "Invader.h"
#include "Label.h"

using namespace std;
using namespace game;


int main(int argc, char** argv)
{
	//Session ses = *sys.get_session();
	Shooter* shooter = Shooter::get_instance(0, 650, 100, 100);
	Label* label = Label::get_instance(350, 720, 100, 50, "Points: " + shooter->get_points());
	ses.add(label);
	ses.add(shooter);
	ses.run();



	return 0;
}