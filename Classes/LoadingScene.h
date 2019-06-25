#pragma once
#include "cocos2d.h"
#define ID_BACKGROUND 0
#define ID_LOADINGBG 5
#define ID_LOADINGPRO 6
#define ID_LABEL 1

USING_NS_CC;

class LoadingScene :public Scene
{
private:
	Sprite *background, *loadingBarBG, *loadingpress;
	Label *lb_loading;
	
	float scale = 0;
public:
	LoadingScene();
	virtual ~LoadingScene();
	static Scene* createScene();
	virtual bool init();

	void update(float deltaTime) override;

	CREATE_FUNC(LoadingScene);
};
