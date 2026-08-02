#pragma once
#include <cassert>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Apple.h"
#include "Rock.h"
#include "Constants.h"
struct Record
{
	std::string name;

	int score;
};
enum GameMode
{
	APPLES_20 = 1 << 0,
	APPLES_50 = 1 << 1,
	SPEED_UP = 1 << 2,
	FINITE = 1 << 3
};
enum class GameStateType
{
	Menu,
	Game
};


namespace ApplesGame
{

	struct Gamestate
	{
		Player player;
		Apples apples;
		Rocks rocks;
		int gameMode;

		int EatenApples = 0;
		bool isGameFinished = false;
		bool isWinning = false;
		bool scoreAdded = false;
		float gameFinishedTime = 0.f;
		float gameWinningTime = 0.f;

		sf::Sound AppleEatSound;
		sf::Sound GameOverSound;
		std::vector<Record> leaderboard;

		GameStateType stateType = GameStateType::Menu;
		
		//resources
		sf::Texture playertexture;
		sf::Texture appleTexture;
		sf::Texture rockTexture;
		sf::RectangleShape backround;
		sf::RectangleShape overlay;
		sf::SoundBuffer eatenAppleSoundBuffer;
		sf::SoundBuffer gameOverSoundBuffer;
		sf::Font font;
		sf::Text scoreText;
		sf::Text gameOverText;
		sf::Text keyHintText;
		sf::Text modeText;
		sf::Text gameOverScoreText;
		sf::Text winningText;
		sf::Text winningScoreText;

	};

	inline void InitGame(Gamestate& game)
	{
		assert(game.playertexture.loadFromFile(RESOURCES_PATH + "\\Player.png"));
		assert(game.appleTexture.loadFromFile(RESOURCES_PATH + "\\Apple.png"));
		assert(game.rockTexture.loadFromFile(RESOURCES_PATH + "\\Rock.png"));
		assert(game.eatenAppleSoundBuffer.loadFromFile(RESOURCES_PATH + "\\AppleEat.wav"));
		assert(game.gameOverSoundBuffer.loadFromFile(RESOURCES_PATH + "\\Death.wav"));
		assert(game.font.loadFromFile(RESOURCES_PATH + "\\Fonts\\Roboto-Bold.ttf"));
		

		game.scoreText.setFont(game.font);
		game.scoreText.setCharacterSize(27.f);
		game.scoreText.setFillColor(sf::Color::White);
		game.scoreText.setPosition(20.f, 20.f);
		game.scoreText.setOutlineColor(sf::Color::Black);
		game.scoreText.setOutlineThickness(2.f);

		game.gameOverText.setFont(game.font);
		game.gameOverText.setCharacterSize(60.f);
		game.gameOverText.setFillColor(sf::Color::White);
		game.gameOverText.setPosition(250.f, 250.f);
		game.gameOverText.setString("Game Over");
		game.gameOverText.setOutlineColor(sf::Color::Black);
		game.gameOverText.setOutlineThickness(2.f);

		game.keyHintText.setFont(game.font);
		game.keyHintText.setCharacterSize(27.f);
		game.keyHintText.setFillColor(sf::Color::White);
		game.keyHintText.setPosition(530.f, 20.f);
		game.keyHintText.setString("Use W,A,S,D to move");
		game.keyHintText.setOutlineColor(sf::Color::Black);
		game.keyHintText.setOutlineThickness(2.f);

		game.modeText.setFont(game.font);
		game.modeText.setCharacterSize(30.f);
		game.modeText.setFillColor(sf::Color::White);	
		game.modeText.setPosition(260.f, 130.f);
		game.modeText.setOutlineColor(sf::Color::Black);
		game.modeText.setOutlineThickness(2.f);
		game.modeText.setString(

			"CHOOSE MODE:\n\n"

			"1: 20 apples with speed up\n\n"



			"2: Finite 20 apples and Speed up\n\n"



			"3: 50 apples without speed up\n\n"



			"4: 50 apples with speed up"
		);


		game.gameOverScoreText.setFont(game.font);
		game.gameOverScoreText.setCharacterSize(30.f);
		game.gameOverScoreText.setFillColor(sf::Color::White);
		game.gameOverScoreText.setPosition(320.f, 320.f);
		game.gameOverScoreText.setOutlineColor(sf::Color::Black);
		game.gameOverScoreText.setOutlineThickness(1.5f);

		game.winningText.setFont(game.font);
		game.winningText.setCharacterSize(60.f);
		game.winningText.setFillColor(sf::Color::White);
		game.winningText.setPosition(270.f, 250.f);
		game.winningText.setString("You Win!");
		game.winningText.setOutlineColor(sf::Color::Black);
		game.winningText.setOutlineThickness(2.f);

		game.winningScoreText.setFont(game.font);
		game.winningScoreText.setCharacterSize(30.f);
		game.winningScoreText.setFillColor(sf::Color::White);
		game.winningScoreText.setPosition(300.f, 320.f);
		game.winningScoreText.setOutlineColor(sf::Color::Black);
		game.winningScoreText.setOutlineThickness(1.5f);

		
		InitPlayer(game.player, game);
		

		game.leaderboard =
		{
			{"Alice", 52},
			{"Bob", 45},
			{"Charlie", 38},
			{"David", 30},

		};

		game.AppleEatSound.setBuffer(game.eatenAppleSoundBuffer);
		game.GameOverSound.setBuffer(game.gameOverSoundBuffer);


		game.EatenApples = 0;
		game.isGameFinished = false;
		game.isWinning = false;
		game.scoreAdded = false;	

		game.backround.setSize(sf::Vector2f(SCREEN_WIGHT, SCREEN_HIGHT));
		game.backround.setFillColor(sf::Color(70, 130, 180, 160));
		game.backround.setPosition(0.f, 0.f);


		game.overlay.setSize(sf::Vector2f(SCREEN_WIGHT, SCREEN_HIGHT));
		game.overlay.setFillColor(sf::Color::Black);
		game.overlay.setPosition(0.f, 0.f);
		
	}

	void UpdateGame(Gamestate& game, float deltaTime, sf::RenderWindow& window);
	void DrawGame(Gamestate& game, sf::RenderWindow& window);
}

