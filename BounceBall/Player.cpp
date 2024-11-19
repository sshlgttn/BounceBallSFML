#include "Player.h"
#include <iostream>
#include "Collision.h"

void Player::update(float deltaTime)
{

}

void Player::movement(float deltaTime)
{
    int groundLevel = 800;
    velocity.x = 0;


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocity.x += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocity.x -= speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isGround) {
        velocity.y = -jumpForce; 
        isGround = false; 
    }

   
    if (!isGround) {
        velocity.y += gravity * (deltaTime*4.1);
    }

    shape.move(velocity.x * deltaTime, velocity.y * deltaTime);

    if (shape.getPosition().y >= groundLevel) { 
        shape.setPosition(shape.getPosition().x, groundLevel); 
        if (std::abs(velocity.y) > minBounceVelocity) {
            velocity.y = -velocity.y * bounceFactor; 
            
        }
        else {
            velocity.y = 0; 
            isGround = true; 
        }
    }
}

void Player::draw(sf::RenderWindow &window)
{
	shape.setRadius(50.0f);
	window.draw(shape);


}

sf::FloatRect Player::getBounds() const
{
    return shape.getGlobalBounds();
}

Player::Player(int startX, int startY) 
{
    shape.setPosition(startX, startY);
 
}

