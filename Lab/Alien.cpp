#include "Alien.h"

Alien::Alien(Player* t_player)
{
    playerPointer = t_player;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    if (texture.loadFromFile("assets/enemy.png"))
    {
        sprite.setTexture(texture);
    }
    sprite.setOrigin(306, 204);
    sprite.setScale(scale.x, scale.y);

    // Setup vision cone
    visionCone.setPointCount(3); // Triangle for the cone
    visionCone.setFillColor(white); // Orange color for vision cone

    directionLine.setPrimitiveType(sf::Lines);
    directionLine.resize(2);
    directionLine[0].color = red;
    directionLine[1].color = red;

    sprite.setPosition(100, 100);
}

void Alien::update()
{
    velocity = Behavior::Seek(sprite, playerPointer->getPosition());
    sprite.move(velocity);
    keepOnScreen();

    // Vision Cone Movement
    float halfAngleRad = (coneAngle * PI / 180.0f);
    sf::Vector2f base1(sprite.getPosition().x + coneLength * cos((sprite.getRotation() - halfAngleRad) * PI / 180.0f),
                       sprite.getPosition().y + coneLength * sin((sprite.getRotation() - halfAngleRad) * PI / 180.0f));
    sf::Vector2f base2(sprite.getPosition().x + coneLength * cos((sprite.getRotation() + halfAngleRad) * PI / 180.0f),
                       sprite.getPosition().y + coneLength * sin((sprite.getRotation() + halfAngleRad) * PI / 180.0f));

    // Set the vertices of the vision cone
    visionCone.setPoint(0, base1);
    visionCone.setPoint(1, sprite.getPosition());
    visionCone.setPoint(2, base2);

    // Calculate vector from alien to player
    sf::Vector2f playerPosition = playerPointer->getPosition();
    sf::Vector2f alienPosition = sprite.getPosition();
    sf::Vector2f vectorToPlayer = playerPosition - alienPosition;

    // Calculate the distance between the enemy and player
    float distanceToPlayer = std::sqrt(vectorToPlayer.x * vectorToPlayer.x + vectorToPlayer.y * vectorToPlayer.y);

    // Calculate angle between alien direction and vector to player
    float alienRotation = sprite.getRotation();
    
    // Calculate the direction line's endpoint position based on the sprite's rotation
    float lineLength = 450.0f; // Adjust the length of the line as needed
    float lineRotation = alienRotation; // Set the line's rotation to match the sprite's rotation
    sf::Vector2f endpoint(alienPosition.x + lineLength * cos(lineRotation * PI / 180.0f),
                          alienPosition.y + lineLength * sin(lineRotation * PI / 180.0f));

    float angle = atan2(vectorToPlayer.y, vectorToPlayer.x);
    angle = angle * 180.0f / PI;
    angle -= alienRotation;
    float halfVisionConeAngle = coneVisionAngle / 2.0f;

    // Normalize the angle to be within [-180, 180] degrees
    if (angle < -180.0f)
        angle += 360.0f;
    else if (angle > 180.0f)
        angle -= 360.0f;

    // Change Cone Color
    if (distanceToPlayer <= coneLength && angle >= -halfVisionConeAngle && angle <= halfVisionConeAngle) {
        visionCone.setFillColor(red);
    }
    else {
        visionCone.setFillColor(white);
    }

    // Middle of cone line
    directionLine[0].position = sprite.getPosition();
    directionLine[1].position = endpoint;
}

void Alien::render(sf::RenderWindow& window)
{
    window.draw(visionCone);
    window.draw(directionLine);
    window.draw(sprite);
}

void Alien::keepOnScreen()
{
    sf::Vector2f pos = sprite.getPosition();

    if (pos.x < 0)
    {
        pos.x += 2400;
    }
    else if (pos.x > 2400)
    {
        pos.x -= 2400;
    }
        
    if (pos.y < 0)
    {
        pos.y += 1800;
    }
    else if (pos.y > 1800)
    {
        pos.y -= 1800;
    }

    sprite.setPosition(pos);
}
