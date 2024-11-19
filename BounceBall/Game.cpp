#include "Game.h"
#include "Collision.h"
#include <iostream>

void Game::update()
{
	deltaTime = clock.restart().asSeconds();
	
}

void Game::render()
{
	
	window.clear();
	player.draw(window);
	window.draw(rect);
	window.display();
}

void Game::handleInput()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
	
	if (Collision::checkCollision(player.getBounds(), rect.getGlobalBounds()))
		std::cout << "COLLISION";
	player.movement(deltaTime);
	//std::cout << Collision::checkCollision(player.getBounds(), rect.getGlobalBounds()) << std::endl;
	//std::cout << player.getBounds().height << std::endl;
	//std::cout << rect.getGlobalBounds().height << std::endl;

	


}

Game::Game()
	:
	
	window(sf::VideoMode(1920, 900), "SFML Game"),
	player(300, 800),
	camera(),
	map(),
	ui()
{
	
	deltaTime = clock.restart().asSeconds();
	rect.setSize(sf::Vector2f(100, 100));
	rect.setPosition(sf::Vector2f(600,800));
	
	window.setFramerateLimit(60);
}

void Game::run()
{
	while (window.isOpen()) {
		handleInput();
		update();
		render();
	}
}
