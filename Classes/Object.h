#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Object
{
protected:
	Scene *m_sprite;
public:
	Object();
	virtual ~Object();
	virtual void Update(float deltaTime) = 0;
	virtual void Init() = 0;
};