#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	Background.setFillColor(sf::Color::Green);
	Background.setPosition(0, 0);
}

Menu::~Menu()
{
}

void Menu::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::Space)) {
		gameState->setCurrentState(State::LEVEL);
		std::cout << "\n Escape pressed.";
	}
	if (input->isPressed(sf::Keyboard::C)) {
		gameState->setCurrentState(State::CREDITS);
		std::cout << "\n C pressed.";
	}
}

void Menu::update(float dt)
{
	Background.setSize(sf::Vector2f(window->getSize()));

}

void Menu::render()
{
	beginDraw();
	window->draw(Background);
	endDraw();
}
