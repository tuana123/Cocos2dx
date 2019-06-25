#pragma once
#include "cocos2d.h"
#include "ResourceManager.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

class MenuScene :public Scene
{
private:
	Sprite *background, *logo;
	ui::Button *btn_play;
public:
	static Scene* createScene();
	virtual bool init();

	CREATE_FUNC(MenuScene);
};