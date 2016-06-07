#include "Board.h"

Board::Board()
{
	eSprite = Sprite::create("shortBoard.png");
	//eBody->setDynamic(false);
	//setEBody();
}

Board::~Board()
{
}

bool Board::init()
{
	return true;
}


//使board横向移动起来
void Board::fly()
{
	posX = eSprite->getPositionX();
	speed = 2;
	posX -= speed;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	if (posX < -eSprite->getContentSize().width / 2)
	{
		posX = visibleSize.width + eSprite->getContentSize().width;

	}
	eSprite->setPositionX(posX);
}





