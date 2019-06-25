#include "ResourceManager.h"
#include <fstream>

ResourceManager *ResourceManager::m_resource = nullptr;

ResourceManager::ResourceManager()
{

}

ResourceManager* ResourceManager::GetInstance()
{
	if (m_resource == nullptr)
	{
		m_resource = new ResourceManager();
	}
	return m_resource;
}

void ResourceManager::init(std::string path)
{
	this->m_dataFolderPath = path;	
	this->Load("Data.bin");
}

void ResourceManager::Load(std::string fileName)
{
	std::ifstream infile;
	
	infile.open(fileName);

	int id, lenght;
	std::string ignore, path_normal, path_pressed;

	if (infile.is_open())
	{
		infile >> ignore;
		infile >> lenght;

		for (int i = 0; i < lenght; i++)
		{
			infile >> ignore;
			infile >> id;
			infile >> ignore;
			infile >> path_normal;

			path_normal.replace(0, 2, this->m_dataFolderPath);

			Sprite * sprite = Sprite::create(path_normal);
			
			sprite->retain();

			m_sprites.insert(std::pair<int, Sprite*>(id, sprite));
		}
	
		infile >> ignore;
		infile >> lenght;
		
		for (int i = 0; i < lenght; i++)
		{
			infile >> ignore;
			infile >> id;
			infile >> ignore;
			infile >> path_normal;
			infile >> ignore;
			infile >> path_pressed;

			path_normal.replace(0, 2, this->m_dataFolderPath);
			path_pressed.replace(0, 2, this->m_dataFolderPath);

			ui::Button *sprite = ui::Button::create(path_normal, path_pressed);

			m_buttons.insert(std::pair<int, ui::Button*>(id, sprite));
		}
	
		infile >> ignore;
		infile >> lenght;
	
		for (int i = 0; i < lenght; i++)
		{
			infile >> ignore;
			infile >> id;
			infile >> ignore;
			infile >> path_normal;

			path_normal.replace(0, 2, this->m_dataFolderPath);

			Label *sprite = Label::createWithTTF("", path_normal, 20);
			
			m_labels.insert(std::pair<int, Label*>(id, sprite));
		}
	}
}

Sprite * ResourceManager::GetSpriteByID(int id)
{
	std::map<int, Sprite*>::iterator it = this->m_sprites.find(id);
	return it->second;
}

ui::Button * ResourceManager::GetButtonByID(int id)
{
	std::map<int, ui::Button*>::iterator it = this->m_buttons.find(id);
	return it->second;
}

Label * ResourceManager::GetLabelByID(int id)
{
	std::map<int, Label*>::iterator it = this->m_labels.find(id);
	return it->second;
}
