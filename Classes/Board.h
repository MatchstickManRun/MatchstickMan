#ifndef __BOARD_H__
#define __BOARD_H__
#include "cocos2d.h"
#include "Entity.h"
using namespace cocos2d;

class Board : public Entity
{
public:
	Board();
	~Board();
	CREATE_FUNC(Board);

	virtual bool init();
public:

	void fly();

private:

	int posX;
	int speed;				//board飞行的速度

};
#endif // !__BOARD_H__


