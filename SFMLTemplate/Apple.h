#pragma once
#include "Constants.h"
#include "SFML/Graphics.hpp"
#include "Player.h"


namespace ApplesGame
{
	struct Apples
	{
		int numApples = 0;
		bool* isAppleEaten = nullptr;
		Position2D* applePos = nullptr;
		sf::Sprite* appleSprite = nullptr;
	};



	struct Gamestate;
	

	void FreeApples(Apples& apples);
	void InitApples(Apples& apples, const Gamestate& game);
    void DrawApples(Apples& apples, sf::RenderWindow& window);
}
