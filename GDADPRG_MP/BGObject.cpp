#include "BGObject.h"

BGObject::BGObject(string name) : AGameObject(name)
{
	//this->name = name;
}

void BGObject::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::Desert, 0));

	this->sprite->setTextureRect(sf::IntRect(0,0,BaseRunner::WINDOW_WIDTH, BaseRunner::WINDOW_HEIGHT * 8));
	this->sprite->setPosition(0, -BaseRunner::WINDOW_HEIGHT * 7);

	BGObjectMovement* logicComponent = new BGObjectMovement("BGObjectMovement_1");
	this->attachComponent(logicComponent);
}

