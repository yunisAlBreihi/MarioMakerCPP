#include "Grid.h"
#include "globals.h"

namespace universal
{
	Grid::Grid(const sf::Vector2i& windowSize)
	{
		m_gridWidth = windowSize.x / globals::TILE_SIZE;
		m_gridHeight = windowSize.y / globals::TILE_SIZE;

		for (size_t x = 0; x < m_gridWidth; ++x) {
			m_spriteParts.push_back(std::vector<std::unique_ptr<universal::SpritePart>>());
			m_sprites.push_back(std::vector<std::unique_ptr<universal::Sprite>>());
			for (size_t y = 0; y < m_gridHeight; ++y) {
				m_spriteParts[x].push_back(nullptr);
				m_sprites[x].push_back(nullptr);
			}
		}
	}

	void Grid::render(sf::RenderWindow* window)
	{
		for (size_t x = 0; x < m_gridWidth; x++) {
			for (size_t y = 0; y < m_gridHeight; y++) {
				//if(m_tiles[x][y] != nullptr){
				//	m_tiles[x][y]->render(&*window);
				//}

				if (m_sprites[x][y] != nullptr) {
					m_sprites[x][y]->render(&*window);
				}

				if (m_spriteParts[x][y] != nullptr) {
					m_spriteParts[x][y]->getSprite().render(&*window);
				}
			}
		}
	}

	void Grid::addSprite(const universal::Sprite* sprite)
	{
		for (size_t x = 0; x < m_gridWidth; x++) {
			for (size_t y = 0; y < m_gridHeight; y++) {
				if (m_sprites[x][y] == nullptr) {
					m_sprites[x][y] = std::make_unique<universal::Sprite>(universal::Sprite(*sprite));
					//m_sprites[x][y]->setPosition(sf::Vector2f(x * globals::TILE_SIZE, y * globals::TILE_SIZE));
					return;
				}
			}
		}
	}

	void Grid::addSpriteAtPosition(const universal::Sprite* sprite, const sf::Vector2i& position)
	{
		const unsigned int t_gridPosX = position.x / globals::TILE_SIZE;
		const unsigned int t_gridPosY = position.y / globals::TILE_SIZE;

		if (t_gridPosX > m_gridWidth - 1 || t_gridPosY > m_gridHeight - 1) {
			return;
		}

		const universal::Sprite* t_sprite = &getSpriteAtPosition(sf::Vector2i(position.x, position.y));

		if (t_sprite == nullptr) {
			std::unique_ptr<universal::Sprite> t_spriteToAdd = std::make_unique<universal::Sprite>(*sprite);

			t_spriteToAdd->setPosition(sf::Vector2f(t_gridPosX * globals::TILE_SIZE, t_gridPosY * globals::TILE_SIZE));
			m_sprites[t_gridPosX][t_gridPosY] = std::move(t_spriteToAdd);
		}
	}

	const universal::Sprite& Grid::getSpriteAtPosition(const sf::Vector2i& position) const
	{
		const unsigned int gridPosX = position.x / globals::TILE_SIZE;
		const unsigned int gridPosY = position.y / globals::TILE_SIZE;

		return *m_sprites[gridPosX][gridPosY];
	}
}
