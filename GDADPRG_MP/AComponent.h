#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
class AGameObject;

class AComponent
{
	public:
		enum ComponentType { NotSet = -1, Script = 0, Renderer = 1, Input = 2 };
		AComponent(string name, ComponentType type);
		~AComponent();

		void attachOwner(AGameObject* owner);
		void detachOwner();
		AGameObject* getOwner();
		ComponentType getType();
		string getName();

		void setDeltaTime(sf::Time deltaTime);
		void setEvent(sf::Event event);
		virtual void perform() = 0;

	protected:
		AGameObject* owner;
		ComponentType type;
		string name;
		sf::Time deltaTime;
		sf::Event event;
};

