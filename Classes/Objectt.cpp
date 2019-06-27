#include "Objectt.h"

Sprite * Objectt::getSprite()
{
	return this->m_sprite;
}

void Objectt::setSprite(Sprite *s)
{
	this->m_sprite = s;
}

Objectt::Objectt()
{
}

Objectt::~Objectt()
{
}

Sprite* Objectt::DuplicateSprite(Sprite * sprite)
{
	Sprite* pRet = Sprite::createWithTexture(sprite->getTexture());
	if (sprite->getChildrenCount() > 0)
	{
		for (int child = 0; child < sprite->getChildrenCount(); child++)
		{
			Sprite* spriteChild = (Sprite*)sprite->getChildren().at(child);
			Sprite* clone = DuplicateSprite((Sprite*)spriteChild);
			clone->boundingBox() = spriteChild->boundingBox();
			clone->setContentSize(spriteChild->getContentSize());
			clone->setPosition(spriteChild->getPosition());
			clone->setAnchorPoint(spriteChild->getAnchorPoint());
			pRet->addChild(clone, spriteChild->getZOrder(), spriteChild->getTag());
		}
	}
	return pRet;
}
