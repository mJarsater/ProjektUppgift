// Uppbyggnad av "spelet"
#include <iostream>
#include <SDL.h>
#include "Session.h"
#include "System.h"
#include "Shooter.h"
#include "Blast.h"
#include "Invader.h"
#include "PointsLabel.h"
#include "LevelLabel.h"
using namespace std;
using namespace game;


int main(int argc, char** argv)
{
	//Session ses = *sys.get_session();
	Shooter* shooter = Shooter::get_instance(0, 650, 100, 100);
	LevelLabel* levelLabel = LevelLabel::get_instance(100,100,200,70, "Level: " + levelHandler.get_level());
	PointsLabel* pointsLabel = PointsLabel::get_instance(350, 720, 100, 50, "Points: " + shooter->get_points());
	ses.add(pointsLabel);
	ses.add(levelLabel);
	ses.add(shooter);
	shooter->set_lifes(3);

	
	ses.run();



	return 0;
}