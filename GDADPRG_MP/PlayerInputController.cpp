#include "PlayerInputController.h"

PlayerInputController::PlayerInputController(string name) : GenericInputController(name)
{
	//this->name = name;
}

PlayerInputController::~PlayerInputController()
{
}

void PlayerInputController::perform()
{
	switch (event.type) {
	case sf::Event::KeyPressed:
		this->handleKeyboard(event.key.code, true);
		break;

	case sf::Event::KeyReleased:
		this->handleKeyboard(event.key.code, false);
		break;
	}
}

bool PlayerInputController::isUp()
{
	return this->moveUp;
}

bool PlayerInputController::isDown()
{
	return this->moveDown;
}

bool PlayerInputController::isLeft()
{
	return this->moveLeft;
}

bool PlayerInputController::isRight()
{
	return this->moveRight;
}

void PlayerInputController::handleKeyboard(sf::Keyboard::Key key, bool isPressed)
{
	switch (key)
	{
	case sf::Keyboard::W:
		this->moveUp = isPressed;
		break;

	case sf::Keyboard::A:
		this->moveLeft = isPressed;
		break;

	case sf::Keyboard::S:
		this->moveDown = isPressed;
		break;

	case sf::Keyboard::D:
		this->moveRight = isPressed;
		break;
	}
}
