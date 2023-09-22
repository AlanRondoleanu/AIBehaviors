#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
    Player();
    void update();
    void render(sf::RenderWindow& window);
    sf::Vector2f getPosition() { return playerPosition; }

private:
    sf::Sprite sprite;
    sf::Texture texture;

    sf::Vector2f playerPosition;
    sf::Vector2f playerVelocity{0, 0};
    sf::Vector2f desiredVelocity;
    float acceleration = 0.2f; 
    float damping = 0.95f;

    float maxSpeed{ 3.0f };
    sf::Vector2f scale{0.4f, 0.4f};
};

