#pragma once
#include "AView.h"
#include "ButtonListener.h"
#include "UIButton.h"
#include "UIText.h"
#include "PopUpWindow.h"
#include "BaseRunner.h"

class MainMenuScreen : public AView, public ButtonListener
{
	public:
		MainMenuScreen(string name);
		~MainMenuScreen();

		void initialize();
		void onButtonClick(UIButton* button);
		void onButtonReleased(UIButton* button);

	private:
		UIText* displayText = NULL;
};

