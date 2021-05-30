#include "RaptorWave.h"

RaptorWave::RaptorWave(string name) : AComponent(name, Script)
{
	srand(time(0));
}

RaptorWave::~RaptorWave()
{
	AComponent::~AComponent();
}

void RaptorWave::perform()
{
	AirplaneSupport* temp;
	float x;
	this->ticks += deltaTime.asSeconds();

	if (this->ticks > 1.0f && counter < 15) {
		temp = new AirplaneSupport("raptor");
		GameObjectManager::getInstance()->addObject(temp);
		counter++;
		this->ticks = 0.0f;
	}
}
