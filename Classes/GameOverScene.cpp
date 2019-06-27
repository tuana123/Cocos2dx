#include "GameOverScene.h"

Scene * GameOverScene::createScene()
{
	return GameOverScene::create();
}

bool GameOverScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//Label *label = ResourceManager::GetInstance()->GetLabelByID(ID_LABEL);

	// Add Sprite Background
	auto background = ResourceManager::GetInstance()->GetSpriteByID(ID_BACKGROUND);
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(visibleSize.width / background->getContentSize().width,
		visibleSize.height / background->getContentSize().height);
	background->removeFromParent();
	this->addChild(background, -10);

	// Add Sprite Label GameOver
	auto lb_gameover = ResourceManager::GetInstance()->GetLabelByID(ID_LABEL);
	lb_gameover->setScale(1.5);
	lb_gameover->setString("GAME OVER");
	lb_gameover->removeFromParent();
	lb_gameover->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 128);
	this->addChild(lb_gameover, 1);

	// Add Label Point
	auto lb_point = ResourceManager::GetInstance()->GetLabelByID(ID_LABEL);
	lb_point->setString("Point");
	lb_point->removeFromParent();
	lb_point->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 64);
	this->addChild(lb_gameover, 1);

	// Add Label Score
	auto lb_score = ResourceManager::GetInstance()->GetLabelByID(ID_LABEL);
	std::string str = std::to_string(ResourceManager::GetInstance()->point);
	lb_score->setString(str);
	lb_score->removeFromParent();
	lb_score->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 32);
	this->addChild(lb_gameover, 1);

	// Add Sprite Play
	auto btn_play = ResourceManager::GetInstance()->GetButtonByID(ID_BUTTON_PLAY);
	btn_play->removeFromParent();
	btn_play->setPosition(Vec2(visibleSize.width * 2 / 3, visibleSize.height / 2 - 32));
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

	// Add Sprite Home
	auto btn_home = ResourceManager::GetInstance()->GetButtonByID(ID_BUTTON_HOME);
	btn_home->removeFromParent();
	btn_home->setPosition(Vec2(visibleSize.width * 1 / 3, visibleSize.height / 2 - 32));
	btn_home->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			Director::getInstance()->replaceScene(MenuScene::createScene());
			break;
		default:
			break;
		}
	});
	this->addChild(btn_home, 1);

	return true;
}
