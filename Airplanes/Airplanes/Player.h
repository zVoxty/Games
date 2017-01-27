#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>
#include <QDebug>
#include "Bullets.h"
#include "Enemy.h"
#include <QMouseEvent>

class Player :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT;
public:
	Player(QGraphicsItem * parent = 0);
	~Player();

	void keyPressEvent(QKeyEvent * event);
	void mouseMoveEvent(QMouseEvent * event);

public slots:
	void spawn();
};

#endif // !Player_H



