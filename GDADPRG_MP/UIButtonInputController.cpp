#include "UIButtonInputController.h"

UIButtonInputController::UIButtonInputController(string name, ButtonListener* buttonListener) : GenericInputController(name)
{
	this->buttonListener = buttonListener;
}

UIButtonInputController::~UIButtonInputController()
{
	AComponent::~AComponent();
}

void UIButtonInputController::perform()
{
	UIButton* button = (UIButton*)this->getOwner();
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && this->pressed) {
		this->pressed = false;
		button->changeButtonToNormal();
		this->buttonListener->onButtonReleased(button);
	}

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {;
		sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
		sf::FloatRect bounds = button->getWorldBounds();

		if (bounds.contains(mousePos)) {
			this->pressed = true;
			button->changeButtonToPressed();
			this->buttonListener->onButtonClick(button);
		}
	}
}
