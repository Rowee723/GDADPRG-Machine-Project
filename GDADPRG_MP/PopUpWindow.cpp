#include "PopUpWindow.h"

PopUpWindow::PopUpWindow(string name) : AView(name), ButtonListener()
{
}

PopUpWindow::~PopUpWindow()
{
	GameObjectManager::getInstance()->deleteObject(this);
}

void PopUpWindow::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::Window, 0));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->sprite->setScale(0.7f, 0.7f);
	this->sprite->setColor(sf::Color::Green);
	this->setPosition(BaseRunner::WINDOW_WIDTH / 2, BaseRunner::WINDOW_HEIGHT / 2);

	UIButton* button;
	sf::Texture* normalTexture = TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::ButtonNormal, 0);
	sf::Texture* pressedTexture = TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::ButtonPressed, 0);

	button = new UIButton(normalTexture, pressedTexture, "CLOSE");
	this->attachChild(button);
	button->setPosition(textureSize.x / 2, textureSize.y / 2 + 150);
	button->setScale(0.3f, 0.3f);
	button->setButtonListener(this);
	button->setText("CLOSE");

	this->displayText = new UIText("PopUp_Text");
	this->attachChild(this->displayText);
	this->displayText->setText("Hello World");
	this->displayText->setPosition(textureSize.x / 2, textureSize.y / 3);
}

void PopUpWindow::onButtonClick(UIButton* button)
{
	this->displayText->setText("BYE!");
}

void PopUpWindow::onButtonReleased(UIButton* button)
{
	PopUpWindow::~PopUpWindow();
}


