#include "Entity.h"


Entity::Entity()
{
	eSprite = NULL;	
}

Entity::~Entity()
{

}

Sprite * Entity::getSprite()
{
	return this->eSprite;
}

PhysicsBody * Entity::getBody()
{
	return eBody;
}
//设置刚体，可以直接在类内调用，在类外通过对象调用
void Entity::setEBody()
{
	eBody = PhysicsBody::createBox(eSprite->getContentSize());
	eSprite->setPhysicsBody(eBody);

}
//使绑定的精灵适配屏幕大小
void Entity::adaptSize()
{
	auto winSize = Director::getInstance()->getWinSize();
	auto spriteSize = eSprite->getContentSize();
	float winWidth = winSize.width;
	float winHeight = winSize.height;
	float spriteWidth = spriteSize.width;
	float spriteHeight = spriteSize.height;
	eSprite->setScaleX(winWidth / (10 * spriteWidth));
	eSprite->setScaleY(winHeight / (5 * spriteHeight));
}
