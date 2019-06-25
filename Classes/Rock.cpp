#include "Rock.h"
#include "ResourceManager.h"

Rock::Rock(Scene * scene)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	this->m_sprite = ResourceManager::GetInstance()->GetSpriteByID(ID_ROCK);
	float x = rand() % (int)(visibleSize.width + 1);
	this->m_sprite->setPosition(x, visibleSize.height);
	scene->addChild(m_sprite);
}

Rock::~Rock()
{

}

void Rock::Init()
{
	this->Update(0.5);
}

void Rock::Update(float deltaTime)
{
	auto moveto = MoveTo::create(deltaTime, Vec2(this->m_sprite->getPosition().x, -10));
	this->m_sprite->runAction(moveto);
	this->m_sprite->release();
}
