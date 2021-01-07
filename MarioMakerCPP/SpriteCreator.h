#pragma once
#include "SFML/Graphics/Texture.hpp"
#include <memory>
#include "SFML/System/Vector2.hpp"
#include "Sprite.h"

namespace editor
{
	class SpriteCreator
	{
	private:
		const unsigned int m_headerSize = 11;
		const unsigned int m_separatorSize = 1;
		const unsigned int m_tileSheetLength = 16;
		const unsigned int m_tileSize = 16;

	public:
		sf::Texture CreateSprite(const char* spritePath, const unsigned int spriteIndex);
		std::unique_ptr<universal::Sprite> CreateSprite(const char* spritePath, unsigned int spriteIndex, const sf::Vector2i& spriteSize);
	};
}
