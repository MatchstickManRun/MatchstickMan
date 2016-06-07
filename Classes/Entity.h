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
	
	Sprite* eSprite;				//ʵ��Entity�����󶨵ľ���
	PhysicsBody* eBody;				//������ܰ󶨵ĸ��壨�ӳ���������
};


#endif // !__ENTITY_H__
