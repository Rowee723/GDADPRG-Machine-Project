#pragma once
#include <iostream>
#include "AGameObject.h"
#include "AComponent.h"

class AirplaneSpikeMovement : public AComponent
{
	public:
		AirplaneSpikeMovement(string name);
		~AirplaneSpikeMovement();
		void perform();

	private:
		float ticks = 0.0f;
};

