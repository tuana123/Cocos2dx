#include "MenuScene.h"
#include "GamePlayScene.h"

Scene * MenuScene::createScene()
{
	return MenuScene::create();
}

bool MenuScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Add Sprite Background
	background = ResourceManager::GetInstance()->GetSpriteByID(ID_BACKGROUND);
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(visibleSize.width / background->getContentSize().width,
		visibleSize.height / background->getContentSize().height);
	background->removeFromParent();
	this->addChild(background, -10);

	// Add Sprite Logo
	logo = ResourceManager::GetInstance()->GetSpriteByID(ID_LOGO);
	logo->removeFromParent();
	logo->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 128);
	this->addChild(logo, 1);

	// Add Sprite Play
	btn_play = ResourceManager::GetInstance()->GetButtonByID(ID_BUTTON_PLAY);
	btn_play->removeFromParent();
	btn_play->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 32));
	btn_play->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			Director::getInstance()->replaceScene(GamePlayScene::createScene());
			break;
		default:
			break;
		}
	});

	this->addChild(btn_play, 1);

	return true;
}
