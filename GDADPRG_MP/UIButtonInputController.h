#pragma once
#include "GenericInputController.h"
#include "ButtonListener.h"
#include "UIButton.h"

class UIButtonInputController : public GenericInputController
{
	public:
		UIButtonInputController(string name, ButtonListener* buttonListener);
		~UIButtonInputController();

		ButtonListener* buttonListener;

		void perform();

	private:
		bool pressed = false;
};

