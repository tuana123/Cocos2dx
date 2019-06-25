#include "Bullet.h"
#include "ResourceManager.h"

Bullet::Bullet(Scene* scene)
{
	this->m_sprite = ResourceManager::GetInstance()->GetSpriteByID(ID_BULLET);
	this->m_sprite->setVisible(false);
	scene->addChild(this->m_sprite);
}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
	this->Update(0.5);
}

void Bullet::Update(float deltaTime)
{
	auto moveby = MoveBy::create(deltaTime, Vec2(this->m_sprite->getPosition().x,
		700));
	this->m_sprite->runAction(moveby);
	this->m_sprite->setVisible(false);
}
