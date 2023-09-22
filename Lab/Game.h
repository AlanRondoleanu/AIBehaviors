#pragma once

#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Alien.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void processKeyReleases(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	void loadTextures();
	void collisions();

	bool gameStart{ false };
	bool gameOver{ false };

	Player player;
	Alien enemies[3];
	int const ENEMY_AMOUNT{ 3 };

	sf::RenderWindow m_window; // main SFML window
	sf::Texture textureSheet; // The background for the game

	bool m_exitGame;

};
