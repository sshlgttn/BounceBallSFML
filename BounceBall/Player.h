#pragma once
#include "Entity.h"

class Player : Entity
{
private:
	sf::CircleShape shape;
	bool isGround = true;
	float gravity = 980.f;
	float jumpForce = 1850.f;
	const float bounceFactor = 0.7f;
	const float minBounceVelocity = 50.0f;
	sf::Vector2i playerSize;
public:
	void update(float deltaTime) override;
	void movement(float deltaTime) override;
	void draw(sf::RenderWindow &window);
	sf::FloatRect getBounds() const override;
	Player(int startX, int startY);
	
	
protected:

};

