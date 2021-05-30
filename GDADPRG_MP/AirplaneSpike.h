#pragma once
#include "AGameObject.h"
#include "AirplaneSpikeMovement.h"
#include "BaseRunner.h"

class AirplaneSpike : public AGameObject
{
	public:
		AirplaneSpike(string name);
		void initialize();
};

