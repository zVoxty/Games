#include "Game.h"

Game::Game()
{	
	//Set window size
	windowHeight = 600;
	windowWidth = 800;

	//Create the screen
	scene = new QGraphicsScene();
	scene->setSceneRect(QRectF(0, 0, windowWidth, windowHeight));
	setScene(scene);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(QSize(windowWidth, windowHeight));

	//Set background
	setBackgroundBrush(QBrush(QImage(":/Images/bg.png")));

	//Set the player
	player = new Player;
	player->setPos(QPointF(windowWidth/2 - 50, windowHeight - 70));
	player->setFlag(QGraphicsItem::ItemIsFocusable); //Make player focusable
	player->setFocus(); //Make player focusable

	//Add the player to the scene
	scene->addItem(player);

	//Create the score;
	score = new Score;
	scene->addItem(score);

	//Create the health;
	health = new Health;
	health->setPos(health->x(), health->y() + 25);
	scene->addItem(health);

	//Create the background music
	backgroundMusic = new QMediaPlayer;
	backgroundMusic->setMedia(QUrl("qrc:/Sounds/bgMusic.wav"));
	backgroundMusic->play();

	//Spawn enemyes
	QTimer * timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
	timer->start(2000);

}

Game::~Game()
{
}