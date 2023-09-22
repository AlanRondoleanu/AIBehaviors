#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

class Behavior {
public:
    static sf::Vector2f Wander(sf::Sprite& sprite);
    static sf::Vector2f Seek(sf::Sprite& sprite, sf::Vector2f target);

};

