#include "GameObjectManager.h"

GameObjectManager* GameObjectManager::sharedInstance = NULL;

GameObjectManager* GameObjectManager::getInstance()
{
	if (sharedInstance == NULL) {
		sharedInstance = new GameObjectManager();
	}
	return sharedInstance;
}

AGameObject* GameObjectManager::findObjectByName(string name)
{
	return this->gameObjectMap[name];
}

List GameObjectManager::getAllObjects()
{
	return this->gameObjectList;
}

int GameObjectManager::activeObjects()
{
	return this->gameObjectList.size();
}

void GameObjectManager::processInput(sf::Event event)
{
	
	for (int i = 0; i < this->gameObjectList.size(); i++) {
		AGameObject::ComponentList componentList = this->gameObjectList[i]->getComponentsOfType(AComponent::ComponentType::Input);
		for (int j = 0; j < componentList.size(); j++) {
			GenericInputController* inputController = (GenericInputController*)componentList[j];

			inputController->assignEvent(event);
			inputController->perform();

		}

		this->processInputChildren(this->gameObjectList[i]->getChildren(), event);
	}
}

void GameObjectManager::processInputChildren(AGameObject::ObjectList objectList, sf::Event event)
{
	for (int i = 0; i < objectList.size(); i++) {
		AGameObject::ComponentList componentList = objectList[i]->getComponentsOfType(AComponent::ComponentType::Input);
		for (int j = 0; j < componentList.size(); j++) {
			GenericInputController* inputController = (GenericInputController*)componentList[j];
			inputController->assignEvent(event);
			inputController->perform();
		}
		this->processInputChildren(objectList[i]->getChildren(), event);
	}
}

void GameObjectManager::update(sf::Time deltaTime)
{
	for (int i = 0; i < this->gameObjectList.size(); i++) {
		if (this->gameObjectList[i]->isEnabled()) {
			AGameObject::ComponentList componentList = this->gameObjectList[i]->getComponentsOfType(AComponent::ComponentType::Script);
			for (int j = 0; j < componentList.size(); j++) {
				componentList[j]->setDeltaTime(deltaTime);
				componentList[j]->perform();
			}

			this->updateChildren(this->gameObjectList[i]->getChildren(), deltaTime);
		}
	}
}

void GameObjectManager::updateChildren(AGameObject::ObjectList objectList, sf::Time deltaTime)
{
	for (int i = 0; i < objectList.size(); i++) {
		if (objectList[i]->isEnabled()) {
			AGameObject::ComponentList componentList = objectList[i]->getComponentsOfType(AComponent::ComponentType::Script);
			for (int j = 0; j < componentList.size(); j++) {
				componentList[j]->setDeltaTime(deltaTime);
				componentList[j]->perform();
			}

			this->updateChildren(objectList[i]->getChildren(), deltaTime);
		}
	}
}

void GameObjectManager::draw(sf::RenderWindow* window, sf::RenderStates renderStates)
{
	
	for (int i = 0; i < this->gameObjectList.size(); i++) {
		this->gameObjectList[i]->draw(window, renderStates);
	}
}

void GameObjectManager::addObject(AGameObject* gameObject)
{
	this->gameObjectMap[gameObject->getName()] = gameObject;
	this->gameObjectList.push_back(gameObject);
	this->gameObjectMap[gameObject->getName()]->initialize();
}

void GameObjectManager::deleteObject(AGameObject* gameObject)
{
	List* tempList = new List();

	for (int i = 0; i < this->gameObjectList.size(); i++) {
		if (gameObject != this->gameObjectList[i])
			tempList->push_back(this->gameObjectList[i]);
	}

	this->gameObjectList.clear();
	this->gameObjectList.swap(*tempList);
}

void GameObjectManager::deleteObjectByName(string name)
{
	AGameObject* tempObject;
	List* tempList = new List();
	tempObject = this->gameObjectMap[name];
	this->gameObjectMap.erase(name);

	for (int i = 0; i < this->gameObjectList.size(); i++) {
		if (tempObject != this->gameObjectList[i])
			tempList->push_back(this->gameObjectList[i]);
	}

	this->gameObjectList.clear();
	this->gameObjectList.swap(*tempList);
}


