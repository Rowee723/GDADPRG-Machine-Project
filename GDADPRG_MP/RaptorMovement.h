#pragma once
#include <iostream>
#include "AGameObject.h"
#include "AComponent.h"

class RaptorMovement :public AComponent
{
	public:
		RaptorMovement(string name, float speed, bool isRogue);
		~RaptorMovement();
		void perform();

	private:
		const float SPEED_MULTIPLIER = 50.0f;
		float speed;
		float ticks = 0.0f;
		bool isRogue;
		bool moveLeft = false;
		bool moveRight = true;
};

