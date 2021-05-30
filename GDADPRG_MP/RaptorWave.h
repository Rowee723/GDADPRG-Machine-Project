#pragma once
#include <time.h>
#include "AGameObject.h"
#include "AComponent.h"
#include "AirplaneSupport.h"
#include "BaseRunner.h"

class RaptorWave : public AComponent
{
	public:
		RaptorWave(string name);
		~RaptorWave();
		void perform();

	private:
		AGameObject::ObjectList list;
		float ticks = 0;
		int counter = 0;
};

