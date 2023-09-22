#include "Player.h"

Player::Player()
{
    if (!texture.loadFromFile("assets/player.png"))
    {
        // Handle error if the texture fails to load
    }
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setScale(scale);

    // Set initial player position
    playerPosition = sf::Vector2f(400, 300); 
    sprite.setPosition(playerPosition);
}

void Player::update()
{
    // Reset desired velocity
    desiredVelocity = sf::Vector2f(0, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        desiredVelocity.x -= maxSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        desiredVelocity.x += maxSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        desiredVelocity.y -= maxSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        desiredVelocity.y += maxSpeed;
    }

    // Apply acceleration to approach desired velocity
    playerVelocity += (desiredVelocity - playerVelocity) * acceleration;

    // Apply damping to slow down the player gradually
    playerVelocity *= damping;

    // Update player position based on velocity
    playerPosition += playerVelocity;

    // Update sprite position
    sprite.setPosition(playerPosition);

    // Update sprite rotation to match the movement direction
    float angle = std::atan2(playerVelocity.y, playerVelocity.x) * 180.0f / 3.14159265f;
    sprite.setRotation(angle + 90);
}

void Player::render(sf::RenderWindow& window)
{
    //window.draw(playerShape);
    window.draw(sprite);
}
