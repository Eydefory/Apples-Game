#pragma once

namespace sf
{
	class Sprite;
}

namespace ApplesGame
{
	struct Vector2D
	{
		float x = 0;
		float y = 0;
	};
	typedef Vector2D Position2D;


	void SetSpriteSize(sf::Sprite& sprite, float desireWidth, float desireHeight);
	void SetSpriteOrigin(sf::Sprite& sprite, float originX, float originY);
}
