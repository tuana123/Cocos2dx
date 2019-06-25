#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <map>
#include <string>

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
