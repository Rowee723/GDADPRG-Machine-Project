#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <time.h>
#include "Entity.h"
#include "TextureManager.h"
#include "GameObjectManager.h"
#include "BGObject.h"
#include "AirplanePlayer.h"
#include "AirplaneSupport.h"
#include "AirplaneSpike.h"
#include "MainMenuScreen.h"
#include "ApplicationManager.h"
#include "PauseButton.h"

using namespace std;

class BaseRunner : private sf::NonCopyable
{
public:
	static const sf::Time TIME_PER_FRAME;
	static const int WINDOW_WIDTH = 1024;
	static const int WINDOW_HEIGHT = 768;

	BaseRunner();
	void run();

private:
	sf::RenderWindow window;
	sf::RenderStates renderStates;
	Entity* background;
	Entity* mainEntity;
	int frame;
	float speed = 3;
	sf::Time counter;

	void render();
	void processEvents();
	void update(sf::Time elapsedtime);
	void handleKeyboard(sf::Keyboard::Key key, bool isPressed);
	float checkDistance(sf::Vector2f v1, sf::Vector2f v2);

	typedef unordered_map<sf::Keyboard::Key, bool> keyBool;
	keyBool keyCode;
};

