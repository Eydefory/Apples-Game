#pragma once
#include <cassert>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Apple.h"
#include "Rock.h"
#include "Constants.h"
enum GameMode
{
	APPLES_20 = 1 << 0,
	APPLES_50 = 1 << 1,
	SPEED_UP = 1 << 2,
	FINITE = 1 << 3
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
		float gameFinishedTime = 0.f;
		float gameWinningTime = 0.f;

		sf::Sound AppleEatSound;
		sf::Sound GameOverSound;

		
		
		//resources
		sf::Texture playertexture;
		sf::Texture appleTexture;
		sf::Texture rockTexture;
		sf::RectangleShape backround;
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
		game.modeText.setCharacterSize(20.f);
		game.modeText.setFillColor(sf::Color::White);	
		game.modeText.setPosition(160.f, 70.f);
		game.modeText.setOutlineColor(sf::Color::Black);
		game.modeText.setOutlineThickness(2.f);


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

		
		//////////////////////////////////////  GAME MODES  ///////////////////////////////////////////////////////////////////




		//Finite mode with 20 apples and speed up
		//game.gameMode = APPLES_20 | FINITE | SPEED_UP;
		//game.modeText.setString("Mode: Finite with 20 apples and speed up");


		//Finite mode with 20 apples and no speed up
		//game.gameMode = APPLES_20 | FINITE;
		//game.modeText.setString("Mode: Finite with 20 apples and no speed up");



		//Endless mode with 50 apples and speed up
		//game.gameMode = APPLES_50 | SPEED_UP;
		//game.modeText.setString("Mode: Endless with 50 apples and speed up");



		//Finite mode with 50 apples and speed up
		//game.gameMode = APPLES_50 | FINITE | SPEED_UP;
		//game.modeText.setString("Mode: Finite with 50 apples and speed up");
		


		//Endless mode with 20 apples and speed up
		game.gameMode = APPLES_20 | SPEED_UP;
		game.modeText.setString("Mode: Endless with 20 apples and speed up");


		//Endless mode with 20 apples and no speed up
		//game.gameMode = APPLES_20;
		//game.modeText.setString("Mode: Endless with 20 apples and no speed up");




		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		InitPlayer(game.player, game);
		InitApples(game.apples, game);
		InitRocks(game.rocks, game);

		

		game.AppleEatSound.setBuffer(game.eatenAppleSoundBuffer);
		game.GameOverSound.setBuffer(game.gameOverSoundBuffer);


		game.EatenApples = 0;
		game.isGameFinished = false;
		game.isWinning = false;


		game.backround.setSize(sf::Vector2f(SCREEN_WIGHT, SCREEN_HIGHT));
		game.backround.setFillColor(sf::Color(70, 130, 180, 160));
		game.backround.setPosition(0.f, 0.f);
	}

	void UpdateGame(Gamestate& game, float deltaTime, sf::RenderWindow& window);
	void DrawGame(Gamestate& game, sf::RenderWindow& window);
}

