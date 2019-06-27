#include "Rock.h"
#include "ResourceManager.h"

Rock::Rock(Scene * scene)
{
	Init();
	scene->addChild(m_sprite,3);
}

Rock::~Rock()
{

}


void Rock::Init()
{
	this->m_sprite = DuplicateSprite(ResourceManager::GetInstance()->GetSpriteByID(ID_ROCK));
	
	
	
	this->m_sprite->setVisible(false);
}

void Rock::Update(float deltaTime)
{
	if (m_sprite->getPositionY() < 0)
	{
		m_sprite->setVisible(false);
	}
	else
	{
		float y = m_sprite->getPositionY();
		m_sprite->setPositionY(y - deltaTime * 500);
	}
}
