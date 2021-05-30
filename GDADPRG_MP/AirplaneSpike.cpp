#include "AirplaneSpike.h"

AirplaneSpike::AirplaneSpike(string name): AGameObject(name)
{
	this->name = name;
}

void AirplaneSpike::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::Spike, 0));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->sprite->setScale(0.15f, 0.15f);
	this->sprite->setPosition(0, 0);

	AirplaneSpikeMovement* logicComponent = new AirplaneSpikeMovement("AirplaneSpikeMovement_1");
	this->attachComponent(logicComponent);
}
