#include "APoolable.h"

APoolable::APoolable(string name) : AGameObject(name)
{
}

APoolable::~APoolable()
{

}

void APoolable::initialize()
{
}

void APoolable::onRelease()
{
}

void APoolable::onActivate()
{
}

/*
APoolable* APoolable::clone()
{
	return 
}
*/