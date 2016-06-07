#include "MatchstickMan.h"

MatchstickMan::MatchstickMan()
{
	
	eSprite = Sprite::create("run1.png");
	//adaptSize();
	//setEBody();
}

MatchstickMan::~MatchstickMan()
{
}

bool MatchstickMan::init()
{
	return true;
}

void MatchstickMan::jump()
{
}

void MatchstickMan::attack()
{
}

Animate * MatchstickMan::creatAnimateRUN()
{
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("runs.plist", "runs.png");


	int iFrameNum = 6;
	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*>frameVec;

	for (int i = 1; i <= iFrameNum; i++)
	{
		frame = frameCache->getSpriteFrameByName(StringUtils::format("run%d.png", i));
		frameVec.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.08f);

	Animate* action = Animate::create(animation);

	return action;

}

