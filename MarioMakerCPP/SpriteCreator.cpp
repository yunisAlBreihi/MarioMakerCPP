#include "SpriteCreator.h"
#include "globals.h"

namespace editor
{
	sf::Texture SpriteCreator::CreateSprite(const char* spritePath, const unsigned int spriteIndex)
	{
		const unsigned int t_col = spriteIndex % m_tileSheetLength;
		const unsigned int t_row = spriteIndex / m_tileSheetLength;

		const unsigned int t_numOfColSeparators = 1 + m_separatorSize * t_col;
		const unsigned int t_colIndex = t_numOfColSeparators + (t_col * m_tileSize);

		const unsigned int t_numOfRowSeparators = (1 + m_separatorSize * t_row) + (m_headerSize * 2);
		const unsigned int t_rowIndex = t_numOfRowSeparators + (t_row * m_tileSize);

		sf::Texture t_texture;
		sf::IntRect t_rect = { sf::Vector2i(t_colIndex, t_rowIndex), sf::Vector2i(m_tileSize, m_tileSize) };
		t_texture.loadFromFile(spritePath, t_rect);
		return t_texture;
	}

	std::unique_ptr<universal::Sprite> SpriteCreator::CreateSprite(const char* spritePath, unsigned int spriteIndex, const sf::Vector2i& spriteSize, const char& id)
	{
		const sf::Vector2f t_spriteSize = sf::Vector2f(globals::TILE_SIZE, globals::TILE_SIZE);

		std::unique_ptr<universal::Sprite> t_sprite = std::make_unique<universal::Sprite>(id);
		t_sprite->setBoundsSize(sf::Vector2f(spriteSize.x, spriteSize.y));

		if ((spriteIndex % m_tileSheetLength) + spriteSize.x > m_tileSheetLength) {
			const unsigned int t_quotient = spriteIndex / m_tileSheetLength;
			spriteIndex = (m_tileSheetLength * t_quotient) + (m_tileSheetLength - spriteSize.x);
		}

		for (size_t i = 0; i < spriteSize.x; ++i) {
			const unsigned int t_col = (spriteIndex + i) % m_tileSheetLength;
			const unsigned int t_numOfColSeparators = 1 + (m_separatorSize * t_col);
			const unsigned int t_colIndex = t_numOfColSeparators + (t_col * m_tileSize);

			for (size_t j = 0; j < spriteSize.y; ++j) {
				const unsigned int t_row = (spriteIndex + ((m_tileSize - 1) * j)) / m_tileSheetLength;
				const unsigned int t_numOfRowSeparators = (1 + (m_separatorSize * t_row)) + (m_headerSize * 2);
				const unsigned int t_rowIndex = t_numOfRowSeparators + (t_row * m_tileSize);

				sf::Texture* t_texture = new sf::Texture();
				sf::IntRect t_rect = { sf::Vector2i(t_colIndex, t_rowIndex), sf::Vector2i(m_tileSize, m_tileSize) };
				t_texture->loadFromFile(spritePath, t_rect);

				std::unique_ptr<universal::Tile> t_tile = std::make_unique<universal::Tile>(t_spriteSize, t_texture);
				t_tile->setPosition(sf::Vector2f(globals::TILE_SIZE * i, globals::TILE_SIZE * j));
				t_sprite->addTile(std::move(&*t_tile));
			}
		}

		return t_sprite;
	}
}