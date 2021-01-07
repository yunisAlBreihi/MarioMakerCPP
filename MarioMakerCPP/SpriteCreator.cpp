#include "SpriteCreator.h"

namespace editor 
{
	sf::Texture SpriteCreator::CreateSprite(const char* spritePath, const unsigned int spriteIndex)
	{
		const unsigned int t_col = spriteIndex % t_tileSheetLength;
		const unsigned int t_row = spriteIndex / t_tileSheetLength;

		const unsigned int t_numOfColSeparators = 1 + t_separatorSize * t_col;
		const unsigned int t_colIndex = t_numOfColSeparators + (t_col * t_tileSize);

		const unsigned int t_numOfRowSeparators = (1 + t_separatorSize * t_row) + (t_headerSize * 2);
		const unsigned int t_rowIndex = t_numOfRowSeparators + (t_row * t_tileSize);

		sf::Texture t_texture;
		sf::IntRect t_rect = { sf::Vector2i(t_colIndex, t_rowIndex), sf::Vector2i(t_tileSize, t_tileSize)};
		t_texture.loadFromFile(spritePath, t_rect);
		return t_texture;
	}

	sf::Texture SpriteCreator::CreateSprite(const char* spritePath, const sf::Vector2i& spriteTexPosition)
	{
		const unsigned int t_col = spriteTexPosition.x % t_tileSheetLength;
		const unsigned int t_row = spriteTexPosition.x / t_tileSheetLength;

		const unsigned int t_numOfColSeparators = 1 + t_separatorSize * t_col;
		const unsigned int t_colIndex = t_numOfColSeparators + (t_col * t_tileSize);

		const unsigned int t_numOfRowSeparators = (1 + t_separatorSize * t_row) + (t_headerSize * 2);
		const unsigned int t_rowIndex = t_numOfRowSeparators + (t_row * t_tileSize);

		sf::Texture t_texture;
		sf::IntRect t_rect = { sf::Vector2i(t_colIndex, t_rowIndex), sf::Vector2i(t_tileSize, t_tileSize) };
		t_texture.loadFromFile(spritePath, t_rect);
		return t_texture;
	}

}