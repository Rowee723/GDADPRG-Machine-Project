#pragma once
#include "AGameObject.h"
#include "BGObjectMovement.h"
#include "BaseRunner.h"

class BGObject : public AGameObject
{
	public:
		BGObject(string name);
		void initialize();
};

