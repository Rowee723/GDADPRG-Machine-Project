#pragma once
#include "AGameObject.h"
#include "PlayerInputController.h"
#include "PlayerMovement.h"
#include "RaptorWave.h"
#include "BaseRunner.h"

class AirplanePlayer : public AGameObject
{
public:
	AirplanePlayer(string name);
	void initialize();
};

