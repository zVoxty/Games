#include "Player.h"
#include "Game.h"
#include <QGraphicsItem>
extern Game * game;

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
	QPixmap image(":/Images/plane.png");
	setPixmap(image.scaled(QSize(70,70)));
}


Player::~Player()
{
}

void Player::keyPressEvent(QKeyEvent * event){
	
	if (event->key() == Qt::Key_Left) {
		if(pos().x() > 0)
			setPos(x() - 10, y());
		qDebug() << pos().x() << pos().y();
	}
	else if (event->key() == Qt::Key_Right) {
		if(pos().x() < game->windowWidth - 70)
			setPos(x() + 10, y());
		qDebug() << pos().x() << pos().y();
	}
	/*else if (event->key() == Qt::Key_Up) {

		setPos(x(), y()+10);
		qDebug() << pos().x() << pos().y();
	}
	else if (event->key() == Qt::Key_Down) {
		setPos(x(), y() - 10);
		qDebug() << pos().x() << pos().y();
	}*/
	else if (event->key() == Qt::Key_Space) {	
		Bullets * bullet = new Bullets();
		bullet->setPos(x() + 32, y());
		scene()->addItem(bullet);
	}
}

void Player::spawn() {
	//create an enemy
	Enemy * enemy = new Enemy();
	scene()->addItem(enemy);
}
