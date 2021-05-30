#include "BGObjectMovement.h"

BGObjectMovement::BGObjectMovement(string name) : AComponent(name, Script)
{
	this->name = name;
	this->type = Script;
}

BGObjectMovement::~BGObjectMovement()
{
	AComponent::~AComponent();
}

void BGObjectMovement::perform()
{
	sf::Sprite* sprite = this->getOwner()->getSprite();
	sf::Vector2f offset(0.0f, 0.0f);

	offset.y += this->SPEED_MULTIPLIER;
	sprite->move(offset * deltaTime.asSeconds());

	sf::Vector2f localPos = sprite->getPosition();

	if (localPos.y * deltaTime.asSeconds() > 0) {
		sprite->setPosition(0, -BaseRunner::WINDOW_HEIGHT * 7);
	}
}
