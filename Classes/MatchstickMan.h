#ifndef __MATCHSTICK_MAN_H__
#define __MATCHSTICK_MAN_H__
#include "cocos2d.h"
#include "Entity.h"
using namespace cocos2d;

class MatchstickMan : public Entity
{
public:
	MatchstickMan();
	~MatchstickMan();
	CREATE_FUNC(MatchstickMan);

	virtual bool init();
public:
	void jump();
	void attack();
	Animate* creatAnimateRUN();
private:
	//void resetData();
	bool m_isJumping;

};
#endif // !__MATCHSTICK_MAN_H__


