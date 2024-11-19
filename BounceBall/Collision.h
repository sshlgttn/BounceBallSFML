#pragma once
#include "Player.h"

class Collision
{
public:
	static bool checkCollision(const sf::FloatRect& a, const sf::FloatRect& b);
	static bool checkGroundCollision(Entity& entity, float groundLevel);
};

