#include "Rock.h"
#include "ResourceManager.h"

Rock::Rock(Scene * scene)
{
	Sprite *rock = ResourceManager::GetInstance()->GetSpriteByID(3);
	scene->addChild(rock);
}

Rock::~Rock()
{

}

void Rock::Init()
{

}

void Rock::Update(float deltaTime)
{

}
