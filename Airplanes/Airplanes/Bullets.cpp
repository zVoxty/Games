#include "Bullets.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game *game; //  there is an external global object

Bullets::Bullets(QGraphicsItem * parent) :  QObject(), QGraphicsPixmapItem(parent){
	// Draw graphics
	QPixmap image(":/Images/Bullet.png");
	setPixmap(image.scaled(QSize(5, 15)));

	//connect
	QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

	bulletSound = new QMediaPlayer;
	bulletSound->setMedia(QUrl("qrc:/Sounds/BulletShoot.wav"));
	bulletSound->play();

	timer->start(10);
}


Bullets::~Bullets(){

}

void Bullets::move() {
	//if bullet collides with enemy, destroy both
	QList<QGraphicsItem *> colliding_items = collidingItems();
	for (int i = 0, n = colliding_items.size(); i < n; ++i) {
		if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
			//increase the score
			game->score->increase();
			//remove them both;
			scene()->removeItem(colliding_items[i]);
			scene()->removeItem(this);
			//delete them both
			delete colliding_items[i];
			delete this;
			return;
		}
	}

	//move bullet up
	setPos(x(), y() - 5);
	if (pos().y() < 0) {
		scene()->removeItem(this);
		delete this;
	}
}