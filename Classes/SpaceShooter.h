#pragma once
#include "cocos2d.h"
#include "ResourceManager.h"
#include <vector>
#include "Rock.h"
#include "Bullet.h"

USING_NS_CC;

class SpaceShooter :public Objectt
{
private:
	std::list <Bullet*> m_bullets;
	Scene *scene;
public:
	SpaceShooter(Scene* scene);
	~SpaceShooter();
	void Init() override;
	void Update(float deltaTime) override;
	void Shoot();
	void Collision(std::vector<Rock*>);
};
