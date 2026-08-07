
#include <cassert>
#include "Game.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <vector>


namespace ApplesGame
{
	void UpdateGame(Gamestate& game, float deltaTime, sf::RenderWindow& window)
	{
		if (game.isGameFinished)
		{

			if (!game.scoreAdded)
			{
				game.leaderboard["Player"] = game.EatenApples;
				game.scoreAdded = true;

				
				std::vector<std::pair<std::string, int>> sorted(
					game.leaderboard.begin(),
					game.leaderboard.end()
				);

				
				for (size_t i = 0; i < sorted.size(); i++)
				{
					for (size_t j = 0; j < sorted.size() - 1; j++)
					{
						if (sorted[j].second < sorted[j + 1].second)
						{
							std::swap(sorted[j], sorted[j + 1]);
						}
					}
				}

				
				std::string leaderboardStr = "===== LEADERBOARD =====\n";
				int place = 1;
				for (const auto& entry : sorted)
				{
					leaderboardStr += std::to_string(place++) + ". " +
						entry.first + " ..... " +
						std::to_string(entry.second) + "\n";
				}
				game.leaderboardText.setString(leaderboardStr);
			}

			

			game.gameFinishedTime += deltaTime;

			if (game.gameFinishedTime >= PAUSE_LENGTH)
			{
				game.stateType = GameStateType::Menu;
				
				auto oldLeaderboard = game.leaderboard;
				InitGame(game);
				game.leaderboard = oldLeaderboard;
				
			}

			return;
		}

		if (game.isWinning)
		{
			game.gameWinningTime += deltaTime;

			if (game.gameWinningTime >= PAUSE_LENGTH)
			{
				auto oldLeaderboard = game.leaderboard;
				InitGame(game);
				game.leaderboard = oldLeaderboard;
			}

			return;
		}
		
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			game.player.playerDir = PlayerDir::Right;

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			game.player.playerDir = PlayerDir::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			game.player.playerDir = PlayerDir::Left;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			game.player.playerDir = PlayerDir::Down;
		}


		switch (game.player.playerDir)
		{

		case PlayerDir::Right:
		{
			game.player.playerPos.x += game.player.playerSpeed * deltaTime;
			break;
		}
		case PlayerDir::Up:
		{
			game.player.playerPos.y -= game.player.playerSpeed * deltaTime;
			break;
		}
		case PlayerDir::Left:
		{
			game.player.playerPos.x -= game.player.playerSpeed * deltaTime;
			break;
		}
		case PlayerDir::Down:
		{
			game.player.playerPos.y += game.player.playerSpeed * deltaTime;
			break;
		}

		}



		


      
		
	
		if (game.stateType == GameStateType::Menu)
			{
			

			      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			      {
			              game.gameMode = APPLES_20 | SPEED_UP;
						  InitPlayer(game.player, game);

						  InitApples(game.apples, game);
						  InitRocks(game.rocks, game);
			              game.stateType = GameStateType::Game;
			      }




			      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			      {
			              game.gameMode = APPLES_20 | FINITE | SPEED_UP;
						  InitPlayer(game.player, game);
						  InitApples(game.apples, game);
						  InitRocks(game.rocks, game);
			              game.stateType = GameStateType::Game;
			      }




			      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			      {
			              game.gameMode = APPLES_50 | FINITE;
						  InitPlayer(game.player, game);

						  InitApples(game.apples, game);
						  InitRocks(game.rocks, game);
			              game.stateType = GameStateType::Game;
			      }




			      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			      {
			              game.gameMode = APPLES_50 | SPEED_UP;
						  InitPlayer(game.player, game);

						  InitApples(game.apples, game);
						  InitRocks(game.rocks, game);
			              game.stateType = GameStateType::Game;
			      }

			      return;
			}
			
		
		








		for (int i = 0; i < game.apples.numApples; ++i)
		{
			if (!game.apples.isAppleEaten[i])
			{
				float dx = fabs(game.player.playerPos.x - game.apples.applePos[i].x);
				float dy = fabs(game.player.playerPos.y - game.apples.applePos[i].y);
				if (dx <= (APPLE_SIZE + PLAYER_SIZE) / 2.f &&
					dy <= (APPLE_SIZE + PLAYER_SIZE) / 2.f)
				{

					game.EatenApples++;
					if (game.gameMode & FINITE)
					{
						game.apples.isAppleEaten[i] = true;
					}
					else
					{
						game.apples.applePos[i].x = rand() / (float)RAND_MAX * SCREEN_WIGHT;
						game.apples.applePos[i].y = rand() / (float)RAND_MAX * SCREEN_HIGHT;
					}


					game.apples.appleSprite[i].setPosition(game.apples.applePos[i].x, game.apples.applePos[i].y);
					
					game.AppleEatSound.play();

					if (game.gameMode & SPEED_UP)
					{
						game.player.playerSpeed += ACCELERATION;
					}


				}
			}
		}

		

		if (game.player.playerPos.x - PLAYER_SIZE / 2.f < 0.f || game.player.playerPos.x + PLAYER_SIZE / 2.f > SCREEN_WIGHT ||
			game.player.playerPos.y - PLAYER_SIZE / 2.f < 0.f || game.player.playerPos.y + PLAYER_SIZE / 2.f > SCREEN_HIGHT)
		{


			game.isGameFinished = true;
			game.gameFinishedTime = 0.f;
			game.GameOverSound.play();
			return;
		}


		for (int i = 0; i < NUM_ROCKS; ++i)
		{


			float dx = fabs(game.player.playerPos.x - game.rocks.rockPos[i].x);
			float dy = fabs(game.player.playerPos.y - game.rocks.rockPos[i].y);
			if (dx <= (ROCK_SIZE + PLAYER_SIZE) / 2.f &&
				dy <= (ROCK_SIZE + PLAYER_SIZE) / 2.f)
			{
				game.gameFinishedTime = 0.f;
				
				game.isGameFinished = true;
				game.GameOverSound.play();
				return;

			}


		}




		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{

			game.isGameFinished = true;
			window.close();
		}

		game.scoreText.setString("Score: " + std::to_string(game.EatenApples));
		game.gameOverScoreText.setString("Your Score: " + std::to_string(game.EatenApples));
		game.winningScoreText.setString("Your Score: " + std::to_string(game.EatenApples));



		if(game.gameMode & FINITE)
		{
			if (game.EatenApples >= game.apples.numApples)
			{
				
				game.gameWinningTime = 0.f;
				game.isWinning = true;
				game.stateType = GameStateType::Menu;


				
				
				return;
			}
		}

	}


	


	void DrawGame(Gamestate& game, sf::RenderWindow& window)
	{
		if (game.isGameFinished)
		{
			game.backround.setFillColor(sf::Color(183, 87, 82));
		}
		if (game.isWinning)
		{
			game.backround.setFillColor(sf::Color(119, 221, 119));
			
		}

		window.draw(game.backround);
		DrawPlayer(game.player, window);
		DrawApples(game.apples, window);
		DrawRocks(game.rocks, window);
		if (!game.isGameFinished)
		{
			window.draw(game.keyHintText);
			window.draw(game.scoreText);

			
			
		}
		else
		{
			window.draw(game.gameOverText);
			window.draw(game.gameOverScoreText);
			window.draw(game.leaderboardText);

		}
		
		if (game.isWinning)
		{
			
			window.draw(game.winningText);
			window.draw(game.winningScoreText);
			window.draw(game.leaderboardText);

		}

		if (game.stateType == GameStateType::Menu)
		{
			window.draw(game.overlay);
			window.draw(game.modeText);
		}



		
		
		window.display();
	}

}
	



	

		


		

		


	
