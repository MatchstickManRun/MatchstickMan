#include "StartScene.h"
#include "PlayScene.h"

USING_NS_CC;

Scene* StartScene::createScene()
{
    auto scene = Scene::create();
	
    
    auto layer = StartScene::create();

    scene->addChild(layer);

    return scene;
}


bool StartScene::init()
{
  
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(StartScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    
	auto playItem = MenuItemImage::create(
		"play1.png",
		"play1.png",
		CC_CALLBACK_1(StartScene::menuCloseCallback, this));

	playItem->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	playItem->setScale(0.3f);
    auto menu = Menu::create(playItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto title = Label::createWithTTF("Matchstick Run", "fonts/Marker Felt.ttf", 24);
	title->setColor(Color3B(249, 194, 111));
    title->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - title->getContentSize().height));
    
    this->addChild(title, 1);
    

	auto background = Sprite::create("city.jpg");
	adaptToWinSize(background);

	background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(background, 0);

	hero = MatchstickMan::create();
	hero->getSprite()->setPosition(Vec2(visibleSize.width / 4 + origin.x, 
		visibleSize.height / 10 + hero->getSprite()->getContentSize().height / 4.7 + origin.y));
	addEntitySprite(hero, 1);
	
	hero->getSprite()->runAction(hero->creatAnimateRUN());

	auto board = Sprite::create("board.png");
	board->setScaleX(40);
	
	board->setPosition(visibleSize.width / 4 + origin.x, visibleSize.height / 10 + origin.y);
	this->addChild(board, 1);



	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event * event)
	{
		keys[keyCode] = true;
	};

	listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event * event)
	{
		keys[keyCode] = false;
	};

	EventDispatcher *eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	this->scheduleUpdate();
    return true;
}

void StartScene::adaptToWinSize(Node * node)
{
	auto myWinSize = Director::getInstance()->getWinSize();
	float winWidth = myWinSize.width;
	float winHeight = myWinSize.height;
	float width = node->getContentSize().width;
	float height = node->getContentSize().height;
	
	node->setScaleX(winWidth / width);
	node->setScaleY(winHeight / height);
}

void StartScene::update(float delta)
{
	Node::update(delta);
	auto leftArrow = EventKeyboard::KeyCode::KEY_LEFT_ARROW, rightArrow = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
	auto upArrow = EventKeyboard::KeyCode::KEY_UP_ARROW, downArrow = EventKeyboard::KeyCode::KEY_DOWN_ARROW;
	if (isKeyPressed(leftArrow)) {
		keyPressedDuration(leftArrow);
	}
	else if (isKeyPressed(rightArrow)) {
		keyPressedDuration(rightArrow);
	}
	else if (isKeyPressed(upArrow)) {
		keyPressedDuration(upArrow);
	}
	else if (isKeyPressed(downArrow)) {
		keyPressedDuration(downArrow);
	}
}

bool StartScene::isKeyPressed(EventKeyboard::KeyCode keyCode)
{
	if (keys[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void StartScene::keyPressedDuration(EventKeyboard::KeyCode code)
{
	int offsetX = 0, offsetY = 0;
	switch (code) {
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		offsetX = -5;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		offsetX = 5;
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		offsetY = 5;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		offsetY = -5;
		break;
	default:
		offsetY = offsetX = 0;
		break;
	}
	// 0.3s代表着动作从开始到结束所用的时间，从而显得不会那么机械。
	auto stickMan = hero->getSprite();
	auto moveTo = MoveTo::create(0.3, Vec2(stickMan->getPositionX() + offsetX, stickMan->getPositionY() + offsetY));
	stickMan->runAction(moveTo);
}

void StartScene::addEntitySprite(Entity * entity, int zOrder)
{
	this->addChild(entity->getSprite(), zOrder);
}


void StartScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(PlayScene::createScene());

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
