#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Map.h"
#include "Camera.h"
#include "UI.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Clock clock;

	Player player;
	Map map;
	Camera camera;
	UI ui;
	sf::ContextSettings settings;

	sf::RectangleShape rect;
	



	float deltaTime;

	void update();
	void render();
	void handleInput();

protected:

public:
	Game();
	void run();
};

