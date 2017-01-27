#include "Health.h"
#include <QFont>
#include "Game.h"
extern Game * game;
Health::Health()
{
	//initialize the health to 3
	health = 3;

	//draw the text
	setPlainText(QString("Health: ") + QString::number(health));
	setDefaultTextColor(Qt::red);
	setFont(QFont("times", 16));
}


Health::~Health()
{
}

void Health::decrease() {
	health--;
	setPlainText(QString("Health: ") + QString::number(health));
	if (health == 0)
		game->close();
}

int Health::getHealth()
{
	return health;
}

