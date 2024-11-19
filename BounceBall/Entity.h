#include <SFML/Graphics.hpp>



class Entity {
protected:
    sf::Sprite sprite;
    sf::Texture texture;

    float deltaTime;
    float speed = 200;


    sf::Vector2i velocity = sf::Vector2i(0,0);

public:

    virtual sf::FloatRect getBounds() const = 0;

    virtual void movement(float deltaTime) = 0;

    virtual void update(float deltaTime) = 0;

    virtual void draw(sf::RenderWindow& window) = 0;





    virtual ~Entity() {}
};