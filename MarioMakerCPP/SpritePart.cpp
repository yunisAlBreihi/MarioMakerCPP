#include "SpritePart.h"
namespace universal 
{
	SpritePart::SpritePart(Sprite& parent, const sf::Vector2f& position) : m_parent(parent), m_position(position)
	{
	}
	Sprite& SpritePart::getSprite() const
	{
		return m_parent;
	}
}