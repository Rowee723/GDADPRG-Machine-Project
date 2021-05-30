#pragma once
#include <iostream>
#include "AGameObject.h"
#include "GenericInputController.h"

class PlayerInputController : public GenericInputController
{
	public:
		PlayerInputController(string name);
		~PlayerInputController();

		void perform();
		bool isUp();
		bool isDown();
		bool isLeft();
		bool isRight();

	private:
		const float SPEED_MULTIPLIER = 300.0f;
		bool moveUp = false;
		bool moveDown = false;
		bool moveLeft = false;
		bool moveRight = false;

		void handleKeyboard(sf::Keyboard::Key key, bool press);

};

