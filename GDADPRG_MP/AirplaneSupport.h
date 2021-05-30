#pragma once
#include<iostream>
#include <time.h>
#include "AGameObject.h"
#include "AirplaneSupportMovement.h"
#include "RaptorMovement.h"
#include "BaseRunner.h"

class AirplaneSupport : public AGameObject
{
	public:
		AirplaneSupport(string name);
		void initialize();
};

