#include "Player.h"
#include "Game.h"

namespace ApplesGame
{
	void InitPlayer(Player& player, const Gamestate& game)
	{

		player.playerPos = { SCREEN_WIGHT / 2.f, SCREEN_HIGHT / 2.f };
		player.playerSpeed = INITIAL_SPEED;
		player.playerDir = PlayerDir::Right;

		player.sprite.setTexture(game.playertexture);
		SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
		SetSpriteOrigin(player.sprite, 0.5f, 0.5f);

	}
	void DrawPlayer(Player& player, sf::RenderWindow& window)
	{
		player.sprite.setPosition(player.playerPos.x, player.playerPos.y);
		window.draw(player.sprite);

		//player.sprite.setRotation((float)player.playerDir * -90.f);

		if(player.playerDir == PlayerDir::Left)
		{
			SetSpriteSize(player.sprite, -PLAYER_SIZE, PLAYER_SIZE);
			player.sprite.setRotation(0.f);
		}
		else
		{
			SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
			player.sprite.setRotation((float)player.playerDir * -90.f);
		}
		

		
		
	}
}

