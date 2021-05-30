#pragma once
#include <iostream>
#include "AGameObject.h"
#include "AComponent.h"
#include "BaseRunner.h"

class BGObjectMovement : public AComponent
{
	public:
		BGObjectMovement(string name);
		~BGObjectMovement();
		void perform();

	private:
		const float SPEED_MULTIPLIER = 100.0f;
		float ticks = 0.0f;
};

