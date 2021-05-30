#include "AirplanePlayer.h"

AirplanePlayer::AirplanePlayer(string name) : AGameObject(name)
{
	this->name = name;
}

void AirplanePlayer::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::Eagle, 0));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->sprite->setPosition(BaseRunner::WINDOW_WIDTH / 2, BaseRunner::WINDOW_HEIGHT / 2);

	PlayerInputController* inputController = new PlayerInputController("MyPlayerInput");
	this->attachComponent(inputController);

	PlayerMovement* movement = new PlayerMovement("MyMovement");
	this->attachComponent(movement);

	//RaptorWave* wave = new RaptorWave("MyWave");
	//this->attachComponent(wave);
}
