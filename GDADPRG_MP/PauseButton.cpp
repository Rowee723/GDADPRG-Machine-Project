#include "PauseButton.h"

PauseButton::PauseButton(string name) : AView(name), ButtonListener()
{
}

PauseButton::~PauseButton()
{
	GameObjectManager::getInstance()->deleteObject(this);
}

void PauseButton::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::PauseMenu, 0));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2,  textureSize.y / 2);
	this->sprite->setScale(0.2f, 0.2f);
	this->setPosition(BaseRunner::WINDOW_WIDTH - 200, BaseRunner::WINDOW_HEIGHT - 50);

	UIButton* button;
	sf::Texture* normalTexture = TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::ButtonNormal, 0);
	sf::Texture* pressedTexture = TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::ButtonPressed, 0);

	button = new UIButton(normalTexture, pressedTexture, "Quit");
	this->attachChild(button);
	button->setPosition(textureSize.x - button->getLocalBounds().width / 2, textureSize.y / 2);
	button->setScale(1.f, 1.f);
	button->setButtonListener(this);
	button->setText("Quit");

	
}

void PauseButton::onButtonClick(UIButton* button)
{
	MainMenuScreen* MainMenu = new MainMenuScreen("MainMenu");
	GameObjectManager::getInstance()->addObject(MainMenu);
	ApplicationManager::getInstance()->pauseApplication();
}

void PauseButton::onButtonReleased(UIButton* button)
{
}
