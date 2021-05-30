#include "Entity.h"

Entity::Entity()
{
	this->texture = new sf::Texture();
	this->sprite = new sf::Sprite();
}

void Entity::setTexture(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite->setTexture(*texture);
}

void Entity::setPosition(float x, float y)
{
	this->sprite->setPosition(x, y);
}

void Entity::incrementTexture()
{
	int size = TextureManager::getInstance()->getTextureLength(this->assetType);

	this->counter = (this->counter + 1) % size;

	sf::Texture* texture = TextureManager::getInstance()->getTextureAt(this->assetType, this->counter);
	this->texture = texture;
	this->sprite->setTexture(*this->texture);
}

void Entity::updateTexture(sf::Texture* texture, TextureManager::AssetType assetType)
{
	this->assetType = assetType;
	this->texture = texture;
	this->sprite->setTexture(*this->texture);
	this->sprite->setOrigin(this->texture->getSize().x / 2, this->texture->getSize().y / 2);;
}

TextureManager::AssetType Entity::getAssetType()
{
	return this->assetType;
}

sf::Sprite* Entity::getSprite()
{
	return this->sprite;
}
