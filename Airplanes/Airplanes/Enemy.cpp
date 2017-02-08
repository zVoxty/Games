#include "Enemy.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <stdlib.h>
#include "Game.h"
#include <QDebug>

extern Game * game;

Enemy::Enemy()
{
	//set random position
	int random_number = rand() % game->windowWidth - 100;
	if (random_number < 100)
		random_number += 100;
	setPos(random_number, 0);

	//draw the rect
	QPixmap image(":/Images/Enemy.png");
	setPixmap(image.scaled(QSize(70, 70)));
	setTransformOriginPoint(50, 50);
	setRotation(180);

	//connect
	QTimer * timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

	timer->start(50);
}


Enemy::~Enemy()
{
}

void Enemy::move() {
	//if enemy collides with player
	QList<QGraphicsItem *> colliding_items = collidingItems();
	for (int i = 0, n = colliding_items.size(); i < n; ++i) {
		if (typeid(*(colliding_items[i])) == typeid(Player)) {
			//decrease player health
			game->health->decrease();
			//remove enemy;
			scene()->removeItem(this);
			//delete them both
			delete this;
			return;
		}
	}

	//move enemy down
	setPos(x(), y() + 5);

	//Destroy enemy when it goes out of the screen
	if (pos().y() > game->windowHeight - 70) {
		game->health->decrease();
		scene()->removeItem(this);
		delete this;
	}
}

