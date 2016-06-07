#ifndef __ENTITY_H__
#define __ENTITY_H__	

#include "cocos2d.h"
using namespace cocos2d;

class Entity : public Node
{
public:
	Entity();
	~Entity();
	Sprite* getSprite();
	PhysicsBody* getBody();
	virtual void setEBody();
	void adaptSize();

protected:
	
	Sprite* eSprite;				//实体Entity类所绑定的精灵
	PhysicsBody* eBody;				//精灵可能绑定的刚体（视场景而定）
};


#endif // !__ENTITY_H__
