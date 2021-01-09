#pragma once
#include "Sprite.h"
#include "SFML/System/Vector2.hpp"

namespace universal 
{
	class SpritePart
	{
	private:
		Sprite& m_parent;
		sf::Vector2f m_position;

	public:
		SpritePart(Sprite& parent, const sf::Vector2f& position);

		Sprite& getSprite() const;
	};
}
