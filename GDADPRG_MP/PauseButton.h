#pragma once
#include "AView.h"
#include "ButtonListener.h"
#include "UIButton.h"
#include "UIText.h"
#include "PopUpWindow.h"
#include "BaseRunner.h"

class PauseButton : public AView, public ButtonListener
{
	public:
		PauseButton(string name);
		~PauseButton();

		void initialize();
		void onButtonClick(UIButton* button);
		void onButtonReleased(UIButton* button);
};

