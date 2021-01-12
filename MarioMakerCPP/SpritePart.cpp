#include "SpritePart.h"
namespace universal 
{
	SpritePart::SpritePart(const Sprite& parent) : m_parent(parent) {}

	const Sprite& SpritePart::getSprite() const
	{
		return m_parent;
	}
}