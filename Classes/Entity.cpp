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
//���ø��壬����ֱ�������ڵ��ã�������ͨ���������
void Entity::setEBody()
{
	eBody = PhysicsBody::createBox(eSprite->getContentSize());
	eSprite->setPhysicsBody(eBody);

}
//ʹ�󶨵ľ���������Ļ��С
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
