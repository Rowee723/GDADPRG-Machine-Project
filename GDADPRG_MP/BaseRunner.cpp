#include "BaseRunner.h"

const sf::Time BaseRunner::TIME_PER_FRAME = sf::seconds(1.f / 60.f);
BaseRunner::BaseRunner() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asset Management")
{
	srand(time(0));
	TextureManager::getInstance()->loadAll();
	ApplicationManager::getInstance()->initialize(&this->window);

	BGObject* bgObject = new BGObject("desert");
	GameObjectManager::getInstance()->addObject(bgObject);

	AirplanePlayer* eagle = new AirplanePlayer("eagle");
	AirplaneSupport* raptor_1 = new AirplaneSupport("support");
	AirplaneSpike* spike_1 = new AirplaneSpike("spike");
	eagle->attachChild(raptor_1);
	eagle->attachChild(spike_1);
	raptor_1->setPosition(100, 100);
	spike_1->setPosition(100, 0);

	AirplaneSupport* raptor_2 = new AirplaneSupport("support");
	AirplaneSpike* spike_2 = new AirplaneSpike("spike");
	eagle->attachChild(raptor_2);
	eagle->attachChild(spike_2);
	raptor_2->setPosition(-50, 100);
	spike_2->setPosition(-50, 0);

	GameObjectManager::getInstance()->addObject(eagle);

	PauseButton* PauseMenu = new PauseButton("PauseMenu");
	GameObjectManager::getInstance()->addObject(PauseMenu);
}

void BaseRunner::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (this->window.isOpen()) {
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

		while (timeSinceLastUpdate > TIME_PER_FRAME) {
			timeSinceLastUpdate -= TIME_PER_FRAME;
			processEvents();
			update(TIME_PER_FRAME);

		}

		render();
	}
}

void BaseRunner::render()
{
	this->window.clear();
	GameObjectManager::getInstance()->draw(&this->window, this->renderStates);
	this->window.display();
}

void BaseRunner::processEvents()
{
	sf::Event event;

	while (this->window.pollEvent(event))
	{
		switch (event.type)
		{
		default:
			GameObjectManager::getInstance()->processInput(event);
			break;
		case sf::Event::Closed:
			this->window.close();
			break;
		}
	}
}

void BaseRunner::update(sf::Time elapsedtime)
{
	if (ApplicationManager::getInstance()->isPaused() == false) {
		GameObjectManager::getInstance()->update(elapsedtime);
	}
}

float BaseRunner::checkDistance(sf::Vector2f v1, sf::Vector2f v2)
{
	return sqrt(powf(v1.x - v2.x, 2) + powf(v1.y - v2.y, 2));
}
