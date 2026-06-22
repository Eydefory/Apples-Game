#include "Math.h"
#include "SFML/Graphics.hpp"
namespace ApplesGame
{

	void SetSpriteSize(sf::Sprite& sprite, float desireWidth, float desireHeight)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sf::Vector2f scale = { desireWidth / spriteRect.width, desireHeight / spriteRect.height };
		sprite.setScale(scale);
	}
	void SetSpriteOrigin(sf::Sprite& sprite, float originX, float originY)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}
}

