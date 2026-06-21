// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constants.h"
#include "Game.h"

int main()

{
	using namespace ApplesGame;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIGHT, SCREEN_HIGHT), "SFML works!");

	int seed = (int)time(nullptr);
	srand(seed);


	//Game init
	Gamestate game;
	InitGame(game);



	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	
	

	while (window.isOpen())
	{

		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;



		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		UpdateGame(game, deltaTime, window);
		DrawGame(game, window);


		
	}
	return 0;
}

