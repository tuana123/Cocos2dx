#include "SpaceShooter.h"
#include <Windows.h>

SpaceShooter::SpaceShooter(Scene *scene)
{
	this->scene = scene;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	this->m_sprite = ResourceManager::GetInstance()->GetSpriteByID(ID_SPACESHIP);
	this->m_sprite->setPosition(visibleSize.width / 2, 0);
	scene->addChild(this->m_sprite);
}

SpaceShooter::~SpaceShooter()
{
}

void SpaceShooter::Init()
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		Bullet *m_bullet1 = new Bullet(this->scene);

		this->m_bullets.push_back(m_bullet1);
	}
}

void SpaceShooter::Update(float deltaTime)
{
	
	static float count = 0;
	count += 0.1;
	if (count >= 1)
	{
		Shoot();
		count = 0;
	}
	for (auto b : m_bullets)
	{
		if (b->getSprite()->isVisible())
		{
			//b->getSprite()->setVisible(true);
			b->Update(deltaTime);

		}
	}
}

void SpaceShooter::Shoot()
{	
	for (auto bullet : m_bullets)
	{
		if (!bullet->getSprite()->isVisible())
		{	
			bullet->getSprite()->setVisible(true);
			Vec2 visible = this->m_sprite->getPosition();
			bullet->getSprite()->setPosition(visible);
			
			break;
		}
	}
}

void SpaceShooter::Collision(std::vector<Rock*> vetor_rock)
{
	/*int count = 0;

	for (auto rock : vetor_rock)
	{
		Sprite* b = rock->getRock;
		if(this->m_sprite->getBoundingBox().intersectsRect(b->getBoundingBox()))
		{

		}
	}*/
	
}
