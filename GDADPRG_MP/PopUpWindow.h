#pragma once
#include "AView.h"
#include "ButtonListener.h"
#include "UIButton.h"
#include "UIText.h"
#include "BaseRunner.h"

class PopUpWindow : public AView, public ButtonListener
{
	public:
		PopUpWindow(string name);
		~PopUpWindow();

		void initialize();
		void onButtonClick(UIButton* button);
		void onButtonReleased(UIButton* button);

	private:
		UIText* displayText = NULL;
};

