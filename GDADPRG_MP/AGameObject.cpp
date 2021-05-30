#include "AGameObject.h"

AGameObject::AGameObject(string name)
{
	this->name = name;
}

AGameObject::~AGameObject()
{
}

void AGameObject::draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates)
{
	if (this->sprite != NULL) {
		targetWindow->draw(*this->sprite, renderStates);
		renderStates.transform = renderStates.transform * this->sprite->getTransform();
	}

	for (int i = 0; i < this->childList.size(); i++) {
		AGameObject* child = this->childList[i];
		child->draw(targetWindow, renderStates);
	}
}

void AGameObject::attachChild(AGameObject* child)
{
	this->childList.push_back(child);
	child->parent = this;
	child->initialize();
}

void AGameObject::detachChild(AGameObject* child)
{
	int index = -1;
	for (int i = 0; i < this->childList.size(); i++) {
		if (this->childList[i] == child) {
			index = i;
		}
	}

	if (index != -1) {
		this->childList.erase(this->childList.begin() + index);
	}

}

void AGameObject::setPosition(float x, float y)
{
	this->sprite->setPosition(x, y);
}

AGameObject::ObjectList AGameObject::getChildren()
{
	return this->childList;
}

void AGameObject::updateChildren(ObjectList objectList, sf::Time deltaTime)
{
	for (int i = 0; i < objectList.size(); i++) {
		AGameObject::ComponentList componentList = objectList[i]->getComponentsOfType(AComponent::ComponentType::Script);
		for (int j = 0; j < componentList.size(); j++) {
			componentList[j]->setDeltaTime(deltaTime);
			componentList[j]->perform();
		}

		this->updateChildren(objectList[i]->getChildren(), deltaTime);
	}
}

void AGameObject::attachComponent(AComponent* component)
{
	this->componentList.push_back(component);
	component->attachOwner(this);
}

void AGameObject::detachComponent(AComponent* component)
{
	int index = -1;

	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i] == component) {
			this->componentList[i]->detachOwner();
			index = i;
		}
	}

	if (index != -1) {
		this->componentList.erase(this->componentList.begin() + index);
		component->detachOwner();
	}
}

string AGameObject::getName()
{
	return this->name;
}

sf::Sprite* AGameObject::getSprite()
{
	return this->sprite;
}

sf::FloatRect AGameObject::getWorldBounds()
{
	sf::FloatRect bounds = this->sprite->getGlobalBounds();

	if (this->parent != NULL) {
		sf::Sprite* parentSprite = this->parent->getSprite();
		bounds = parentSprite->getTransform().transformRect(bounds);
	}

	return bounds;
}

sf::FloatRect AGameObject::getLocalBounds()
{
	return this->sprite->getLocalBounds();
}

AGameObject* AGameObject::getParent()
{
	return this->parent;
}

AComponent* AGameObject::findComponentByName(string name)
{
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getName() == name)
			return this->componentList[i];
	}

	return NULL;
}

AComponent* AGameObject::findComponentOfType(AComponent::ComponentType type, string name)
{
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getName() == name && this->componentList[i]->getType() == type)
			return this->componentList[i];
	}

	return NULL;
}

AGameObject::ComponentList AGameObject::getComponentsOfType(AComponent::ComponentType type)
{
	ComponentList* temp = new ComponentList();

	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getType() == type) {
			temp->push_back(this->componentList[i]);
		}
	}

	return *temp;
}


AGameObject::ComponentList AGameObject::getComponentsOfTypeRecursive(AComponent::ComponentType type)
{
	ComponentList foundList;
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getType() == type) {
			foundList.push_back(this->componentList[i]);
		}
	}

	for (int i = 0; i < this->childList.size(); i++) {
		foundList = this->getComponentsRecursiveProper(this->childList[i], type, foundList);
	}

	return foundList;
}

void AGameObject::setEnabled(bool flag)
{
	this->enabled = flag;
}

bool AGameObject::isEnabled()
{
	return this->enabled;
}

AGameObject::ComponentList AGameObject::getComponentsRecursiveProper(AGameObject* object, AComponent::ComponentType type, ComponentList foundList)
{
	ObjectList children = object->childList;

	for (int i = 0; i < object->componentList.size(); i++) {
		if (object->componentList[i]->getType() == type) {
			foundList.push_back(this->componentList[i]);
		}
	}

	for (int i = 0; i < children.size(); i++) {
		this->getComponentsRecursiveProper(children[i], type, foundList);
	}

	return foundList;
}

