#pragma once
#include "Constants.h"
#include <SFML/Graphics.hpp>
#include "Math.h"



namespace ApplesGame
{
	struct Rocks

	{
		sf::Sprite rockSprite[NUM_ROCKS]; 
		bool isRockTouched[NUM_ROCKS];
        Position2D rockPos[NUM_ROCKS];
	};

	struct Gamestate;

	
	void InitRocks(Rocks& rocks, const Gamestate& game);
    void DrawRocks(Rocks& rock, sf::RenderWindow& window);

}

