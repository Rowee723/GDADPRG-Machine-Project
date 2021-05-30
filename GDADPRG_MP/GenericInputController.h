#pragma once
#include <iostream>
#include "AComponent.h"

class GenericInputController : public AComponent
{
	public:
		GenericInputController(string name);
		~GenericInputController();

		void assignEvent(sf::Event event);
		void perform();

	protected:
		//sf::Event event;
};

