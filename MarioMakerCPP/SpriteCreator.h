#pragma once
#include "SFML/Graphics/Texture.hpp"
#include <memory>
#include "SFML/System/Vector2.hpp"

namespace editor 
{
	class SpriteCreator
	{
	private:
		const unsigned int t_headerSize = 11;
		const unsigned int t_separatorSize = 1;
		const unsigned int t_tileSheetLength = 15;
		const unsigned int t_tileSize = 16;
	
	public:
		sf::Texture CreateSprite(const char* spritePath, const unsigned int spriteIndex);
		sf::Texture CreateSprite(const char* spritePath, const sf::Vector2i& spriteTexPosition);
	};
}
