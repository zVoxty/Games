#ifndef BULLETS_T
#define BULLETS_T
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
class Bullets : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	Bullets(QGraphicsItem * parent = 0);
	~Bullets();

public slots:
	void move();

private:
	QMediaPlayer * bulletSound;
};


#endif // ! BULLET_T


