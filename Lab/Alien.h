#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Behavior.h"

class Alien
{
public:

    Alien(Player* t_player);
    void update();
    void render(sf::RenderWindow& window);
    void keepOnScreen();

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f scale{0.3f, 0.3f};
    
    Player* playerPointer;
    sf::Vector2f velocity;

    // Vision Cone Parameters
    float coneLength = 500.0f;
    float coneAngle = 1200.0f; // Broken?
    float coneVisionAngle = 50.0f; // This one for vision
    sf::ConvexShape visionCone;
    const float PI = 3.14159265359f;
    sf::VertexArray directionLine;

    // Colors
    sf::Color red {255, 0, 0, 70};
    sf::Color white {255, 255, 255, 70};
};

