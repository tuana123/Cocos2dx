#pragma once
#include "cocos2d.h"
#include "Objectt.h"

USING_NS_CC;

class Rock :public Objectt
{
public:
	Rock(Scene* scene);
	virtual ~Rock();

	void Init();
	void Update(float deltaTime) override;
};
