#pragma once
#include "Constants.h"
#include "SFML/Graphics.hpp"
#include "Player.h"


namespace ApplesGame
{
	struct Apples
	{
		int numApples = 0;
		std::vector<bool> isAppleEaten;
		std::vector<Position2D> applePos;
		std::vector<sf::Sprite> appleSprite;
	};



	struct Gamestate;
	

	
	void InitApples(Apples& apples, const Gamestate& game);
    void DrawApples(Apples& apples, sf::RenderWindow& window);
}
