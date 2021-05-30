#include "RaptorMovement.h"

RaptorMovement::RaptorMovement(string name, float speed, bool isRogue) : AComponent(name, Script)
{
	this->name = name;
	this->type = Script;
	this->speed = speed;
	this->isRogue = isRogue;
}

RaptorMovement::~RaptorMovement()
{
	AComponent::~AComponent();
}

void RaptorMovement::perform()
{
	sf::Sprite* sprite = this->getOwner()->getSprite();
	sf::Vector2f offset(0.0f, 0.0f);

	this->ticks += deltaTime.asSeconds();

	if (isRogue) {
		if (this->moveRight) {
			offset.y -= speed;
			offset.x += SPEED_MULTIPLIER;
			sprite->move(offset * deltaTime.asSeconds());
		}
		else if (this->moveLeft) {
			offset.y -= speed;
			offset.x -= SPEED_MULTIPLIER;
			sprite->move(offset * deltaTime.asSeconds());
		}

		if (this->ticks > 0.5f && this->moveRight) {
			this->moveRight = false;
			this->moveLeft = true;
			this->ticks = 0.0f;
		}
		else if (this->ticks > 0.5f && this->moveLeft) {
			this->moveLeft = false;
			this->moveRight = true;
			this->ticks = 0.0f;
		}
	}

	else {
		if (this->ticks > 0.005f) {
			offset.y -= speed;
			sprite->move(offset * deltaTime.asSeconds());
			this->ticks = 0.0f;
		}
	}
}
