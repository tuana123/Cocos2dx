#pragma once
#include "cocos2d.h"
#include "Rock.h"
#include "SpaceShooter.h"
#include "ResourceManager.h"
#include <vector>

USING_NS_CC;

class GamePlayScene :public Scene
{
private:
	std::vector <Rock*> m_rock;
	SpaceShooter* m_spaceship = new SpaceShooter(this);
	float c = 0;

public:
	static Scene* createScene();
	virtual bool init()override;

	void update(float deltaTime) override;
	void GenerateRock();

	bool onTouchBegan(Touch*,Event*);
	bool onTouchMove(Touch*, Event*);
	void onTouchEnded(Touch*, Event*);

	CREATE_FUNC(GamePlayScene);
};
