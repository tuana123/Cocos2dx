#include "LoadingScene.h"
#include "ResourceManager.h"


Scene * LoadingScene::createScene()
{
	auto scene = LoadingScene::create();
	return scene;
}

bool LoadingScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleSize();
	
	auto background = ResourceManager::GetInstance()->GetSpriteByID(0);
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->removeFromParent();
	this->addChild(background,-10);

	auto loadingBarBG = ResourceManager::GetInstance()->GetSpriteByID(5);
	loadingBarBG->setPosition(visibleSize.width / 2, origin.y + 64);
	this->addChild(loadingBarBG, 1);

	this->scheduleUpdate();
}

void LoadingScene::update(float deltaTime)
{

}
