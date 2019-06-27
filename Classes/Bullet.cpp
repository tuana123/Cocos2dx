#include "Bullet.h"
#include "ResourceManager.h"

Bullet::Bullet(Scene* scene)
{
	this->Init();
	scene->addChild(this->m_sprite);
}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
	this->m_sprite = DuplicateSprite(ResourceManager::GetInstance()->GetSpriteByID(ID_BULLET));
	this->m_sprite->setVisible(false);
}

void Bullet::Update(float deltaTime)
{
	if (this->m_sprite->getPositionY() > Director::getInstance()->getVisibleSize().height)
	{
		m_sprite->setVisible(false);
	}
	else if (m_sprite->isVisible())
	{
		float y = m_sprite->getPositionY() + deltaTime * 500;
		m_sprite->setPositionY(y);
	}	
}
