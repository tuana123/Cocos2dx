#pragma once
#include "cocos2d.h"
#include "Objectt.h"

USING_NS_CC;

class Bullet :public Objectt
{
public:
	Bullet(Scene* scene);
	~Bullet();
	void Init() override;
	void Update(float deltaTime) override;
};
