#include "Collision.h"

bool Collision::checkCollision(const sf::FloatRect& a, const sf::FloatRect& b)
{
    return a.intersects(b);
}

bool Collision::checkGroundCollision(Entity& entity, float groundLevel)
{
    auto bounds = entity.getBounds(); // �������� ����� getBounds() � Entity
    return bounds.top + bounds.height >= groundLevel;
}
