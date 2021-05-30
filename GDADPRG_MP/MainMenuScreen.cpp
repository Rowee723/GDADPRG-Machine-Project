#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen(string name) : AView(name), ButtonListener()
{
}

MainMenuScreen::~MainMenuScreen()
{
	GameObjectManager::getInstance()->deleteObject(this);
}

void MainMenuScreen::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::Window, 0));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->setPosition(BaseRunner::WINDOW_WIDTH / 2, BaseRunner::WINDOW_HEIGHT / 2);

	UIButton* button;
	sf::Texture* normalTexture = TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::ButtonNormal, 0);
	sf::Texture* pressedTexture = TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::ButtonPressed, 0);

	button = new UIButton(normalTexture, pressedTexture, "Resume");
	this->attachChild(button);
	button->setPosition(textureSize.x / 2 - 150, textureSize.y / 2 + 150);
	button->setScale(0.3f, 0.3f);
	button->setButtonListener(this);
	button->setText("Resume");

	button = new UIButton(normalTexture, pressedTexture, "Quit");
	this->attachChild(button);
	button->setPosition(textureSize.x / 2 + 150, textureSize.y / 2 + 150);
	button->setScale(0.3f, 0.3f);
	button->setButtonListener(this);
	button->setText("Quit");

	this->displayText = new UIText("MainMenu_Text");
	this->attachChild(this->displayText);
	this->displayText->setText("Game Paused");
	this->displayText->setPosition(textureSize.x / 2, textureSize.y / 3);
}

void MainMenuScreen::onButtonClick(UIButton* button)
{
	if(button->getName() == "Resume")
	{
		ApplicationManager::getInstance()->resumeApplication();
		MainMenuScreen::~MainMenuScreen();
	}
	else if(button->getName() == "Quit")
	{
		ApplicationManager::getInstance()->applicationQuit();
	}
}

void MainMenuScreen::onButtonReleased(UIButton* button)
{
	/*
	this->displayText->setText("BUTTON RELEASED! " + button->getName());
	if(button->getName() == "OPEN"){
		PopUpWindow* pop = new PopUpWindow("PopUp");
		GameObjectManager::getInstance()->addObject(pop);
	}
	
	if (button->getName() == "CLOSE") {
		MainMenuScreen::~MainMenuScreen();
	}
	*/
	
}
