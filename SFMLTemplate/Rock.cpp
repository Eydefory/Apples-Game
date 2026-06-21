#include "Rock.h"
#include "Game.h"
#include "Math.h"


namespace ApplesGame
{
	
	void InitRocks(Rocks& rocks, const Gamestate& game)
	{
		
		
		
		for (int i = 0; i < NUM_ROCKS; i++)
		{
			rocks.isRockTouched[i] = false;
			rocks.rockPos[i].x = rand() / (float)RAND_MAX * SCREEN_WIGHT;
			rocks.rockPos[i].y = rand() / (float)RAND_MAX * SCREEN_HIGHT;

			rocks.rockSprite[i].setTexture(game.rockTexture);
			SetSpriteSize(rocks.rockSprite[i], ROCK_SIZE, ROCK_SIZE);
			SetSpriteOrigin(rocks.rockSprite[i], 0.5f, 0.5f);
		}
	}

	void DrawRocks(Rocks& rocks, sf::RenderWindow& window)
	{
		
		
		for (int i = 0; i < NUM_ROCKS; i++)
		{
			if (!rocks.isRockTouched[i])
			{
				rocks.rockSprite[i].setPosition(
					rocks.rockPos[i].x,
					rocks.rockPos[i].y
				);

				window.draw(rocks.rockSprite[i]);
			}
		}

			
		
	}

}

