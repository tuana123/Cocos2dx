#include "GamePlayScene.h"

Scene * GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

bool GamePlayScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Add Sprite Background
	auto background = ResourceManager::GetInstance()->GetSpriteByID(ID_BACKGROUND);
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(visibleSize.width / background->getContentSize().width,
		visibleSize.height / background->getContentSize().height);
	background->removeFromParent();
	this->addChild(background, -10);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GamePlayScene::onTouchMove, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	
	m_spaceship->Init();
	
	for (int i = 0; i < MAX_ROCK; i++)
	{
		Rock *rock = new Rock(this);
		m_rock.push_back(rock);
	}
		
	this->scheduleUpdate();

	return true;
}

void GamePlayScene::update(float deltaTime)
{
	c += deltaTime;
	
	if (c >= 0.2)
	{
		GenerateRock();	
		
		c = 0;
	}	

	m_spaceship->Update(deltaTime);
	
	for (auto r : m_rock)
	{
		if (r->getSprite()->isVisible())
		{
			r->Update(deltaTime);
		}
	}
}

void GamePlayScene::GenerateRock()
{	
	for (auto r : m_rock)
	{
		if (!r->getSprite()->isVisible())
		{
			r->getSprite()->setVisible(true);
			auto visibleSize = Director::getInstance()->getVisibleSize();
			float x = rand() % (int)(visibleSize.width + 1);
			r->getSprite()->setPosition(x, visibleSize.height);
			break;
		}		
	}
}

bool GamePlayScene::onTouchBegan(Touch *t, Event *)
{
	m_spaceship->getSprite()->setPosition(t->getLocation());
	return true;
}

bool GamePlayScene::onTouchMove(Touch *t, Event * event)
{
	m_spaceship->getSprite()->setPosition(t->getLocation());
	return true;
}

