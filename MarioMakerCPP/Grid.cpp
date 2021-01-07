#include "Grid.h"
#include "globals.h"

namespace universal
{
	Grid::Grid(const sf::Vector2i& windowSize)
	{
		m_gridWidth = windowSize.x / globals::TILE_SIZE;
		m_gridHeight = windowSize.y / globals::TILE_SIZE;

		for (size_t x = 0; x < m_gridWidth; ++x) {
			m_tiles.push_back(std::vector<std::unique_ptr<universal::TileBase>>());
			for (size_t y = 0; y < m_gridHeight; ++y) {
				m_tiles[x].push_back(nullptr);
			}
		}
	}

	void Grid::render(sf::RenderWindow* window)
	{
		for (size_t x = 0; x < m_gridWidth; x++) {
			for (size_t y = 0; y < m_gridHeight; y++) {
				if(m_tiles[x][y] != nullptr){
					m_tiles[x][y]->render(&*window);
				}
			}
		}
	}

	void Grid::addTile(const universal::TileBase* tileToAdd)
	{
		for (size_t x = 0; x < m_gridWidth; x++) {
			for (size_t y = 0; y < m_gridHeight; y++) {
				if (m_tiles[x][y] == nullptr) {
					m_tiles[x][y] = std::make_unique<universal::TileBase>(universal::TileBase(*tileToAdd));
					m_tiles[x][y]->setPosition(sf::Vector2f(x * globals::TILE_SIZE, y * globals::TILE_SIZE));
					return;
				}
			}
		}
	}

	void Grid::addTileAtPosition(const universal::TileBase* tileToAdd, const sf::Vector2i& position)
	{
		const unsigned int t_gridPosX = position.x / globals::TILE_SIZE;
		const unsigned int t_gridPosY = position.y / globals::TILE_SIZE;

		if (t_gridPosX > m_gridWidth - 1 || t_gridPosY > m_gridHeight - 1) {
			return;
		}

		const universal::TileBase* t_tile = &getTileAtPosition(sf::Vector2i(position.x, position.y));

		if (t_tile == nullptr || tileToAdd->getFillColor() != m_tiles[t_gridPosX][t_gridPosY]->getFillColor()) {
			std::unique_ptr<universal::TileBase> t_tileToAdd = std::make_unique<universal::TileBase>(*tileToAdd);

			t_tileToAdd->setPosition(sf::Vector2f(t_gridPosX * globals::TILE_SIZE, t_gridPosY * globals::TILE_SIZE));
			m_tiles[t_gridPosX][t_gridPosY] = std::move(t_tileToAdd);
		}
	}

	const universal::TileBase& Grid::getTileAtPosition(const sf::Vector2i& position) const
	{
		const unsigned int gridPosX = position.x / globals::TILE_SIZE;
		const unsigned int gridPosY = position.y / globals::TILE_SIZE;

		return *m_tiles[gridPosX][gridPosY];
	}
}
