#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include "Player.h"
#include "Enemy.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QMediaPlayer>
#include "Score.h"
#include "Health.h"
#include <QMouseEvent>

class Game : public QGraphicsView
{
public: // Public Functions
	Game();
	~Game();

	void mouseMoveEvent(QMouseEvent * event);

public: // Public Variables
	QGraphicsScene * scene;
	int windowHeight;
	int windowWidth;
	QMediaPlayer * backgroundMusic;
	Player * player;
	Score * score;
	Health * health;
};

#endif // !GAME_H

