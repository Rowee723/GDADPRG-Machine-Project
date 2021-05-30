#include "SpriteSheetManager.h"
#include "TextureManager.h"
#include "BaseRunner.h"
#include <iostream>

SpriteSheetManager::SpriteSheetManager(string name) : AGameObject(name)
{
}

void SpriteSheetManager::initialize()
{
	std::cout << "Declared as " << this->getName() << "\n";

	//assign texture
	this->sprite = new sf::Sprite();

	for(int i=1; i<4;i++)
	{
		string name = "J" + std::to_string(i);

		std::cout << name << endl;
		sf::Texture* texture = TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::, i);
		textureList.push_back(texture);
	}

	this->sprite->setPosition(BaseRunner::WINDOW_WIDTH / 2 - 900, BaseRunner::WINDOW_HEIGHT/2 + 100);
	this->sprite->setTexture(*textureList[Index]);

}

void SpriteSheetManager::processInput(sf::Event event)
{
}

void SpriteSheetManager::update(sf::Time deltaTime)
{

	if(TimeLimit > deltaTime.asSeconds())
	{

		this->sprite->move(5 * deltaTime.asSeconds(), 0);
	}


	TimeElapse += deltaTime.asSeconds();
	if(TimeElapse> 0.7)
	{
		Index++;
		TimeElapse = 0;
	}

	if(Index == 3)
	{
		Index = 0;
	}

	this->sprite->setTexture(*textureList[Index]);

	if(this->sprite->getPosition().x >= BaseRunner::WINDOW_WIDTH)
	{
		
	}
}
