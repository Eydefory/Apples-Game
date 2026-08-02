

#include "Apple.h"
#include "Game.h"
#include "Math.h"


namespace ApplesGame
{
	void FreeApples(Apples& apples)
	{
		delete[] apples.isAppleEaten;
		apples.isAppleEaten = nullptr;

		delete[] apples.applePos;
		apples.applePos = nullptr;

		delete[] apples.appleSprite;
		apples.appleSprite = nullptr;

		apples.numApples = 0;
	}

	
	void InitApples(Apples& apples, const Gamestate& game)
	{
		FreeApples(apples);

		if (game.gameMode & APPLES_20)
		{
			apples.numApples = 20;
		}
		else if (game.gameMode & APPLES_50)
		{
			apples.numApples = 50;
		}


		apples.isAppleEaten = new bool[apples.numApples];
		apples.applePos = new Position2D[apples.numApples];
		apples.appleSprite = new sf::Sprite[apples.numApples];


		for (int i = 0; i < apples.numApples; i++)
		{


			apples.isAppleEaten[i] = false;
			apples.applePos[i].x = rand() / (float)RAND_MAX * SCREEN_WIGHT;
			apples.applePos[i].y = rand() / (float)RAND_MAX * SCREEN_HIGHT;



			apples.appleSprite[i].setTexture(game.appleTexture);
			SetSpriteSize(apples.appleSprite[i], APPLE_SIZE, APPLE_SIZE);
			SetSpriteOrigin(apples.appleSprite[i], 0.5f, 0.5f);

		}



	}



	
	void DrawApples(Apples& apples, sf::RenderWindow& window)
		
	{
		
		for (int i = 0; i < apples.numApples; i++)
		{
			if (!apples.isAppleEaten[i])
			{
				apples.appleSprite[i].setPosition(
					apples.applePos[i].x,
					apples.applePos[i].y
				);

				window.draw(apples.appleSprite[i]);
			}
		}
			

				
			




		

		
	}

	

	

}
