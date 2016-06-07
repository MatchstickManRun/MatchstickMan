#include "PlayScene.h"


USING_NS_CC;

Scene* PlayScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vec2(0.0f, -10.0f));
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	auto layer = PlayScene::create();

	scene->addChild(layer);

	return scene;
}


bool PlayScene::init()
{

	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(PlayScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));


	auto playItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(PlayScene::menuCloseCallback, this));

	playItem->setPosition(Vec2(origin.x + visibleSize.width-playItem->getContentSize().width/2,
		origin.y + playItem->getContentSize().width/2));
	//playItem->setScale(0.3f);
	auto menu = Menu::create(playItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto title = Label::createWithTTF("Matchstick Run", "fonts/Marker Felt.ttf", 24);
	title->setColor(Color3B(249, 194, 111));
	title->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - title->getContentSize().height));

	this->addChild(title, 1);

	auto background = Sprite::create("city.jpg");
	this->adaptToWinSize(background);
	background->setPosition(Vec2(visibleSize.width / 2 + origin.x, 
		visibleSize.height / 2 + origin.y));

	this->addChild(background, 0);

	hero = MatchstickMan::create();
	hero->getSprite()->setPosition(Vec2(visibleSize.width / 4, visibleSize.height / 4));
	hero->setEBody();
	addEntitySprite(hero, 1);

	hero->getSprite()->runAction(hero->creatAnimateRUN());

	/*auto board = Sprite::create("shortBoard.png");
	auto boardBody = PhysicsBody::createBox(board->getContentSize());
	boardBody->setDynamic(false);
	board->setPhysicsBody(boardBody);
	board->setScaleX(visibleSize.width/board->getContentSize().width);
	board->setPosition(visibleSize.width / 2, visibleSize.height / 4 - hero->getSprite()->getContentSize().height / 2 + 10);
	this->addChild(board, 1);*/

	boards[FirstBoard] = Board::create();
	boards[FirstBoard]->getSprite()->setScaleX(visibleSize.width / 
		boards[FirstBoard]->getSprite()->getContentSize().width);
	boards[FirstBoard]->setEBody();
	boards[FirstBoard]->getBody()->setDynamic(false);
	boards[FirstBoard]->getSprite()->setPosition(visibleSize.width / 2,
		visibleSize.height / 4 - hero->getSprite()->getContentSize().height / 2 + 10);
	addEntitySprite(boards[FirstBoard], 1);

	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 5.0f);
	auto edgeNode = Node::create();
	edgeNode->setPhysicsBody(body);
	edgeNode->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(edgeNode);

	this->scheduleUpdate();

	return true;
}

void PlayScene::adaptToWinSize(Node * node)
{
	auto myWinSize = Director::getInstance()->getWinSize();
	float winWidth = myWinSize.width;
	float winHeight = myWinSize.height;
	float width = node->getContentSize().width;
	float height = node->getContentSize().height;

	node->setScaleX(winWidth / width);
	node->setScaleY(winHeight / height);
}


void PlayScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void PlayScene::addEntitySprite(Entity * entity,int zOrder)
{
	this->addChild(entity->getSprite(), zOrder);
}

void PlayScene::update(float delta)
{
	
	int posX;
	

}
