#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "TextureManager.h"
#include "AComponent.h"

using namespace std;

class AGameObject : sf::NonCopyable
{
	public:
		AGameObject(string name);
		~AGameObject();
		virtual void initialize() = 0;

		//virtual void processInput(sf::Event event) = 0;
		//virtual void update(sf::Time deltaTime) = 0;
		virtual void draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates);

		string getName();
		sf::Sprite* getSprite();
		sf::FloatRect getWorldBounds();
		sf::FloatRect getLocalBounds();

		AGameObject* getParent();

		void attachChild(AGameObject* child);
		void detachChild(AGameObject* child);
		void setPosition(float x, float y);
	
		typedef vector<AGameObject*>ObjectList;
		typedef vector<AComponent*> ComponentList;

		ObjectList getChildren();
		void updateChildren(ObjectList objectList, sf::Time deltaTime);

		void attachComponent(AComponent* component);
		void detachComponent(AComponent* component);

		AComponent* findComponentByName(string name);
		AComponent* findComponentOfType(AComponent::ComponentType type, string name);
		ComponentList getComponentsOfType(AComponent::ComponentType type);
		ComponentList getComponentsOfTypeRecursive(AComponent::ComponentType type);

		void setEnabled(bool flag);
		bool isEnabled();

	protected:
		string name;
		sf::Sprite* sprite;
		sf::Texture* texture;
		AGameObject* parent = NULL;

		ObjectList childList;
		ComponentList componentList;

	private:
		ComponentList getComponentsRecursiveProper(AGameObject* object, AComponent::ComponentType type, ComponentList foundList);
		bool enabled = true;
};

