#include "LoadingScene.h"
#include "ResourceManager.h"
#include "MenuScene.h"


LoadingScene::LoadingScene()
{
}

LoadingScene::~LoadingScene()
{
}

Scene * LoadingScene::createScene()
{
	return LoadingScene::create();
}

bool LoadingScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	// Add Background
	background = ResourceManager::GetInstance()->GetSpriteByID(ID_BACKGROUND);
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(visibleSize.width / background->getContentSize().width,
		visibleSize.height / background->getContentSize().height);
	background->removeFromParent();
	this->addChild(background,-10);

	//Add Loading Bar BackGround
	loadingBarBG = ResourceManager::GetInstance()->GetSpriteByID(ID_LOADINGBG);
	loadingBarBG->setPosition(visibleSize.width / 2, origin.y + 64);
	this->addChild(loadingBarBG, 1);

	//Add Loading progess
	loadingpress = ResourceManager::GetInstance()->GetSpriteByID(ID_LOADINGPRO);
	loadingpress->setAnchorPoint(Vec2(0, 0.5));
	loadingpress->setPosition(visibleSize.width  /2 - loadingpress->getContentSize().width / 2,
		origin.y + 64);
	loadingpress->setScale(0, 1);
	this->addChild(loadingpress, 2);

	//Add Label Loading
	lb_loading = ResourceManager::GetInstance()->GetLabelByID(ID_LABEL);
	lb_loading->setString("Loading...");
	lb_loading->setPosition(visibleSize.width / 2, loadingpress->getPositionY());
	this->addChild(lb_loading,3);

	this->scheduleUpdate();

	return true;
}

void LoadingScene::update(float deltaTime)
{
	scale += 0.01;
	loadingpress->setScale(scale, 1);
	if (scale >= 1)
	{
		this->unscheduleUpdate();
		Director::getInstance()->replaceScene(MenuScene::createScene());
	}

}
