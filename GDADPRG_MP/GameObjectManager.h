#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "AGameObject.h"
#include "GenericInputController.h"

using namespace std;
typedef unordered_map<string, AGameObject*> Hashtable;
typedef vector<AGameObject*> List;

class GameObjectManager
{
	public:
		static GameObjectManager* getInstance();
		AGameObject* findObjectByName(string name);
		List getAllObjects();
		int activeObjects();
		void processInput(sf::Event event);
		void processInputChildren(AGameObject::ObjectList objectList, sf::Event event);
		void update(sf::Time deltaTime);
		void updateChildren(AGameObject::ObjectList objectList, sf::Time deltaTime);
		void draw(sf::RenderWindow* window, sf::RenderStates renderStates);
		void addObject(AGameObject* gameObject);
		void deleteObject(AGameObject* gameObject);
		void deleteObjectByName(string name);

	private:
		GameObjectManager() {};
		GameObjectManager(GameObjectManager const&) {};
		GameObjectManager& operator=(GameObjectManager const&) {};
		static GameObjectManager* sharedInstance;

		Hashtable gameObjectMap;
		List gameObjectList;
};

