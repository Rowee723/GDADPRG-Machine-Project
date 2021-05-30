#pragma once
#include "AGameObject.h"
#include "ButtonListener.h"
#include "UIButtonInputController.h"
#include "UIText.h"

class UIButton : public AGameObject
{
	public:
		UIButton(sf::Texture* normalTexture, sf::Texture* pressedTexture, string name);
		~UIButton();

		void initialize();

		void setText(string text);
		void setButtonListener(ButtonListener* listener);
		void setScale(float x, float y);

		void changeButtonToNormal();
		void changeButtonToPressed();

	private:
		UIText* displayText = NULL;
		sf::Texture* normalTexture = NULL;
		sf::Texture* pressedTexture = NULL;
		ButtonListener* listener;

};

