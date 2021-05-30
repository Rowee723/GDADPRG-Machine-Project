#include "TextureManager.h"

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance()
{
	if (sharedInstance == NULL) {
		sharedInstance = new TextureManager();
	}

	return sharedInstance;
}

void TextureManager::loadAll()
{
	//------TEXTURES------//
	sf::Texture* texture;

	//Desert
	texture = new sf::Texture();
	if (texture->loadFromFile("Assets/Desert.png")) {
		cout << "Asset(Texture): Desert.png - loaded successfully!\n";
		texture->setRepeated(true);
		this->textureMap[Desert].push_back(texture);
	}
	else { cout << "Asset(Texture): Desert.png - load Failed!\n"; }

	//Eagle
	texture = new sf::Texture();
	if (texture->loadFromFile("Assets/Eagle.png")) {
		cout << "Asset(Texture): Eagle.png - loaded successfully!\n";
		this->textureMap[Eagle].push_back(texture);
	}
	else { cout << "Asset(Texture): Eagle.png - load Failed!\n"; }

	//Raptor
	texture = new sf::Texture();
	if (texture->loadFromFile("Assets/Raptor.png")) {
		cout << "Asset(Texture): Raptor.png - loaded successfully!\n";
		this->textureMap[Raptor].push_back(texture);
	}
	else { cout << "Asset(Texture): Raptor.png - load Failed!\n"; }

	//Spike
	texture = new sf::Texture();
	if (texture->loadFromFile("Assets/Spike.png")) {
		cout << "Asset(Texture): Spike.png - loaded successfully!\n";
		this->textureMap[Spike].push_back(texture);
	}
	else { cout << "Asset(Texture): Spike.png - load Failed!\n"; }

	//Window
	texture = new sf::Texture();
	if (texture->loadFromFile("Assets/Window.png")) {
		cout << "Asset(Texture): Window.png - loaded successfully!\n";
		this->textureMap[Window].push_back(texture);
	}
	else { cout << "Asset(Texture): Window.png - load Failed!\n"; }

	//Button Normal
	texture = new sf::Texture();
	if (texture->loadFromFile("Assets/ButtonNormal.png")) {
		cout << "Asset(Texture): ButtonNormal.png - loaded successfully!\n";
		this->textureMap[ButtonNormal].push_back(texture);
	}
	else { cout << "Asset(Texture): ButtonNormal.png - load Failed!\n"; }

	//Button Pressed
	texture = new sf::Texture();
	if (texture->loadFromFile("Assets/ButtonPressed.png")) {
		cout << "Asset(Texture): ButtonPressed.png - loaded successfully!\n";
		this->textureMap[ButtonPressed].push_back(texture);
	}
	else { cout << "Asset(Texture): ButtonPressed.png - load Failed!\n"; }

	//Pause Menu
	texture = new sf::Texture();
	if (texture->loadFromFile("Assets/PauseMenu.png")) {
		cout << "Asset(Texture): PauseMenu.png - loaded successfully!\n";
		this->textureMap[PauseMenu].push_back(texture);
	}
	else { cout << "Asset(Texture): PauseMenu.png - load Failed!\n"; }

	//

	
	
	//------FONTS------//
	sf::Font* font;

	//Default Font
	font = new sf::Font();
	if (font->loadFromFile("Media/Sansation.ttf")) {
		cout << "Media(font): Sansation.ttf - loaded successfully!\n";
		this->fontMap[DefaultFont] = font;
	}

	
}

sf::Texture* TextureManager::getTextureAt(TextureManager::AssetType assetType, int index)
{
	if (!this->textureMap[assetType].empty()) {
		return this->textureMap[assetType][index];
	}

	else {
		cout << "No texture found for " << assetType << endl;;
		return NULL;
	}
}

int TextureManager::getTextureLength(TextureManager::AssetType assetType)
{
	if (!this->textureMap[assetType].empty()) {
		return this->textureMap[assetType].size();
	}

	else {
		cout << "No textures found for " << assetType << endl;
		return 0;
	}
}

sf::Font* TextureManager::getFont(FontType fontType)
{
	return this->fontMap[fontType];
}
