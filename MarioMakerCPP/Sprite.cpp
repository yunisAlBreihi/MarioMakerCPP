#include "Sprite.h"

namespace universal
{
	void Sprite::render(sf::RenderWindow* window)
	{
		for (const auto& t_tile : m_tiles) {
			if (t_tile != nullptr) {
				t_tile->render(&*window);
			}
		}
	}

	void Sprite::addTile(const Tile* tile)
	{
		std::unique_ptr<Tile> t_tile = std::make_unique<Tile>(*tile);
		m_tiles.emplace_back(std::move(t_tile));
	}
}
