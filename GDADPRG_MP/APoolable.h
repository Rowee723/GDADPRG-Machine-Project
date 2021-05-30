#pragma once
#include "AGameObject.h"
class APoolable : public AGameObject
{
	public:
		APoolable(string name);
		~APoolable();
		virtual	void initialize();
		virtual void onRelease();
		virtual void onActivate();
		//virtual APoolable* clone();
};

