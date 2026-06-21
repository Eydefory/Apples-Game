#pragma once
#include "Constants.h"
#include "Math.h"
#include "SFML/Graphics.hpp"


namespace ApplesGame
{
	

	enum class PlayerDir
	{
		Right = 0,
		Up,
		Left,
		Down
	};



	struct Player
	{

		Position2D playerPos;
		float playerSpeed = INITIAL_SPEED;
		PlayerDir playerDir = PlayerDir::Right;
		sf::Sprite sprite;
	};

	struct Gamestate;

	void InitPlayer(Player& player, const Gamestate& game);
	void DrawPlayer(Player& player, sf::RenderWindow& window);
	

}

