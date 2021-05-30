#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

using namespace std;

class TextureManager
{
public:
	enum AssetType { Desert, Eagle, Raptor, Spike, Window, ButtonNormal, ButtonPressed, PauseMenu };
	enum FontType { DefaultFont };

	typedef unordered_map<TextureManager::AssetType, vector<sf::Texture*>> TextureMap;
	typedef unordered_map<TextureManager::FontType, sf::Font*> FontMap;
	
	static TextureManager* getInstance(); 
	void loadAll();
	sf::Texture* getTextureAt(TextureManager::AssetType assetType, int index);
	int getTextureLength(TextureManager::AssetType assetType);
	sf::Font* getFont(FontType fontType);

private:
	TextureManager() {};
	TextureManager(TextureManager const&);
	TextureManager& operator=(TextureManager const&) {};
	static TextureManager* sharedInstance;

	TextureMap textureMap;
	FontMap fontMap;
};

