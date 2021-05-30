#include "AirplaneSupport.h"

AirplaneSupport::AirplaneSupport(string name) : AGameObject(name)
{
	this->name = name;
}

void AirplaneSupport::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::Raptor, 0));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	if (this->name == "support") {
		this->sprite->setPosition(0, 0);
		AirplaneSupportMovement* logicComponent = new AirplaneSupportMovement("AirplaneSupportMovement_1");
		this->attachComponent(logicComponent);
	}

	else if (this->name == "raptor") {
		bool isRogue;
		float x = rand() % (BaseRunner::WINDOW_WIDTH - 100) + 50;
		this->sprite->setPosition(x, BaseRunner::WINDOW_HEIGHT);
		float speed = rand() % 300 + 50;
		int random = rand() % 2;

		if (random == 0)
			isRogue = true;
		else
			isRogue = false;

		RaptorMovement* logicComponent = new RaptorMovement("RaptorMovement_1", speed, isRogue);
		this->attachComponent(logicComponent);
	}
}


