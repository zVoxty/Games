#include "Score.h"
#include <QFont>

Score::Score(){
	//initialize the score to 0
	score = 0;

	//draw the text
	setPlainText(QString("Score: ") + QString::number(score));
	setDefaultTextColor(Qt::blue);
	setFont(QFont("times", 16));

}


Score::~Score()
{
}

void Score::increase(){
	score++;
	setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
	return score;
}
