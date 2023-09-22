#include "Game.h"

Game::Game() :
	m_window{ sf::VideoMode{ 2400U, 1800U, 32U }, "SFML Game" },
	m_exitGame{ false },
	enemies{&player, &player, &player }
{
	loadTextures();
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	srand(time(NULL));  // Initialize random number generator

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render(); 
	}
}

void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) 
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) 
		{
			processKeys(newEvent);
		}
		if (sf::Event::KeyReleased == newEvent.type)
		{
			processKeyReleases(newEvent);
		}
	}
}


void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}

	if (sf::Keyboard::Space == t_event.key.code)
	{
	}
	if (sf::Keyboard::S == t_event.key.code)
	{
	}
}

void Game::processKeyReleases(sf::Event t_event)
{
	if (sf::Event::KeyReleased == t_event.type)
	{
		
	}
}

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	if (gameStart)
	{
		collisions();

	}

	player.update();
	for (int i = 0; i < ENEMY_AMOUNT; i++)
	{
		enemies[i].update();
	}
}

void Game::render()
{
	m_window.clear(sf::Color::Black);
	for (int i = 0; i < ENEMY_AMOUNT; i++)
	{
		enemies[i].render(m_window);
	}
	player.render(m_window);
	m_window.display();
}

void Game::loadTextures()
{
	
}

void Game::collisions()
{
	////Cactus Collisions
	//for (size_t i = 0; i < CACTUS_AMOUNT; i++)
	//{
	//	if (dino.getGlobalBounds().intersects(cactusBoys[i].getSprite().getGlobalBounds()))
	//	{
	//		gameStart = false;
	//		gameOver = true;
	//		dino.setTextureRect(sf::IntRect{ 852, 0, dinoWidth, dinoHeight });
	//	}
	//}

	////Bird Collisions
	//if (dino.getGlobalBounds().intersects(bird.getSprite().getGlobalBounds()))
	//{
	//	gameStart = false;
	//	gameOver = true;
	//	dino.setTextureRect(sf::IntRect{ 852, 0, dinoWidth, dinoHeight });
	//}
}
