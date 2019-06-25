#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <map>
#include <string>
#define ID_BACKGROUND 0
#define ID_LOADINGBG 5
#define ID_LOADINGPRO 6
#define ID_LABEL 1
#define ID_BULLET 2
#define ID_ROCK 3
#define ID_SPACESHIP 4
#define ID_LOGO 1
#define ID_BUTTON_PLAY 0
#define ID_BUTTON_RESUM 1
#define ID_BUTTON_HOME 2

USING_NS_CC;

class ResourceManager
{
private:
	
	static ResourceManager* m_resource;
	ResourceManager();

	std::string m_dataFolderPath;
	
	std::map <int, Sprite*> m_sprites;
	std::map <int, ui::Button*> m_buttons;
	std::map <int, Label*> m_labels;

public:
	
	static ResourceManager* GetInstance();
	
	void init(std::string path);
	void Load(std::string fileName);
	
	Sprite* GetSpriteByID(int id);
	ui::Button* GetButtonByID(int id);
	Label* GetLabelByID(int id);
};
