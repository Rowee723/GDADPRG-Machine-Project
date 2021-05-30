#include "UIButton.h"

UIButton::UIButton(sf::Texture* normalTexture, sf::Texture* pressedTexture, string name) : AGameObject(name)
{
	this->normalTexture = normalTexture;
	this->pressedTexture = pressedTexture;
}

UIButton::~UIButton()
{
	delete this->listener;
	AGameObject::~AGameObject();
}

void UIButton::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::ButtonNormal, 0));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	this->displayText = new UIText("");
	this->attachChild(this->displayText);
	this->displayText->setText("");
	this->displayText->setSize(80);
	this->displayText->setPosition(textureSize.x / 2 , textureSize.y / 2);
	
}

void UIButton::setText(string text)
{
	this->displayText->setText(text);
}

void UIButton::setButtonListener(ButtonListener* listener)
{
	this->listener = listener;
	UIButtonInputController* inputController = new UIButtonInputController("UI_InputController", this->listener);
	this->attachComponent(inputController);
}

void UIButton::setScale(float x, float y)
{
	this->sprite->setScale(x, y);
}

void UIButton::changeButtonToNormal()
{
	this->sprite->setTexture(*this->normalTexture);
}

void UIButton::changeButtonToPressed()
{
	this->sprite->setTexture(*this->pressedTexture);
}
