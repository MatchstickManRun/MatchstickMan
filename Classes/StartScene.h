#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"
#include "MatchstickMan.h"

class StartScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void adaptToWinSize(Node *node);

	void update(float delta) override;
	bool isKeyPressed(EventKeyboard::KeyCode keyCode);
	void keyPressedDuration(EventKeyboard::KeyCode code);
    
	void addEntitySprite(Entity* entity, int zOrder);

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
private:
	MatchstickMan* hero;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
};

#endif // __START_SCENE_H__
