#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Objectt
{
protected:
	Sprite *m_sprite;
public:
	Objectt();
	virtual ~Objectt();
	virtual void Update(float deltaTime) = 0;
	virtual void Init() = 0;
};