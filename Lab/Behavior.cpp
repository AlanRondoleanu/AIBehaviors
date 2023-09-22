#include "Behavior.h"


sf::Vector2f Behavior::Wander(sf::Sprite& sprite)
{
    sf::Vector2f steering;
    float wanderRate = 0.5;
    float wanderOffset = 1;
    float wanderRadius = 500;
    float maxAcc = 2;

    // Generate a random value between -1 and +1 for wanderOrientation
    float wanderOrientation = 0.0f;
    wanderOrientation += (static_cast<float>(std::rand() % 200) / 100.0f - 1.0f) * wanderRate;
    float targetOrientation = wanderOrientation + sprite.getRotation();
    sprite.setRotation(targetOrientation);

    // Get the center of the wander circle
    sf::Vector2f circleCenter = sprite.getPosition() + wanderOffset * sf::Vector2f(std::cos(targetOrientation), std::sin(targetOrientation));
    sf::Vector2f targetPosition = circleCenter + wanderRadius * sf::Vector2f(std::cos(targetOrientation), std::sin(targetOrientation));

    // Calculate steering to reach the target position
    steering = targetPosition - sprite.getPosition();

    // Limit the steering force to the maximum allowed acceleration
    float steeringMagnitude = std::sqrt(steering.x * steering.x + steering.y * steering.y);
    if (steeringMagnitude > maxAcc)
    {
        steering *= maxAcc / steeringMagnitude;
    }
  
    return steering;
}

sf::Vector2f Behavior::Seek(sf::Sprite& sprite, sf::Vector2f target)
{
    sf::Vector2f steering;
    float maxAcc = 2;

    steering = target - sprite.getPosition();
    float steeringMagnitude = std::sqrt(steering.x * steering.x + steering.y * steering.y);

    if (steeringMagnitude > 0.0f)
    {
        steering /= steeringMagnitude;
    }
    steering *= maxAcc;

    // Calculate the angle
    float angle = std::atan2(steering.y, steering.x);
    sprite.setRotation(angle * 180.0f / 3.14159265f);

    return steering;
}
