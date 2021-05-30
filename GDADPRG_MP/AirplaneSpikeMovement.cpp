#include "AirplaneSpikeMovement.h"

AirplaneSpikeMovement::AirplaneSpikeMovement(string name) : AComponent(name, Script)
{
	this->name = name;
	this->type = Script;
}

AirplaneSpikeMovement::~AirplaneSpikeMovement()
{
	AComponent::~AComponent();
}

void AirplaneSpikeMovement::perform()
{
	sf::Sprite* sprite = this->getOwner()->getSprite();
	this->ticks += deltaTime.asSeconds();

	if (this->ticks > 0.025f) {;
		sprite->rotate(10.0f);
		ticks = 0.0f;
	}
}
