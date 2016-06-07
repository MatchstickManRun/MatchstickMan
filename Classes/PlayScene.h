#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
#include "MatchstickMan.h"
#include "Board.h"

#define BoardAmount 4
#define FirstBoard 0
#define BottomBoard 1
#define MiddleBoard 2
#define TopBoard 3

class PlayScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	//This is a function to adapt the node to the game's window's size
	void adaptToWinSize(Node *node);

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	void addEntitySprite(Entity* entity,int zOrder);

	void update(float delta) override;

	// implement the "static create()" method manually
	CREATE_FUNC(PlayScene);
private:
	MatchstickMan* hero;
	Board* boards[BoardAmount];
};

#endif // __PLAY_SCENE_H__

