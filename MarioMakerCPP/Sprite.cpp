#include "Sprite.h"
#include "globals.h"

namespace universal
{
	Sprite::Sprite(const char& id) : m_id(id) { }

	Sprite::Sprite(const Sprite& other) noexcept
	{
		for (const auto& t_tile : other.m_tiles) {
			m_tiles.emplace_back(std::make_unique<Tile>(*t_tile));
		}
		m_boundsSize = other.m_boundsSize;
		m_id = other.m_id;
	}

	void Sprite::render(sf::RenderWindow& window)
	{
		for (const auto& t_tile : m_tiles) {
			if (t_tile != nullptr) {
				t_tile->render(window);
			}
		}
	}

	void Sprite::addTile(const Tile& tile)
	{
		std::unique_ptr<Tile> t_tile = std::make_unique<Tile>(tile);
		m_tiles.emplace_back(std::move(t_tile));
	}

	void Sprite::setBoundsSize(const sf::Vector2f& size)
	{
		m_boundsSize = size;
	}

	const sf::Vector2f& Sprite::getBoundsSize() const
	{
		return m_boundsSize;
	}

	void Sprite::setPosition(const sf::Vector2f position)
	{
		int i = 0;
		for (int x = 0; x < m_boundsSize.x; ++x) {
			for (int y = 0; y < m_boundsSize.y; ++y, ++i) {
				sf::Vector2f t_newPos = sf::Vector2f(position.x + x * globals::TILE_SIZE, position.y + y * globals::TILE_SIZE);
				m_tiles[i]->setPosition(t_newPos);
			}
		}
	}
	
	const sf::Vector2f& Sprite::getPosition() const
	{
		return m_tiles[0]->getPosition();
	}

	const char& Sprite::getId() const
	{
		return m_id;
	}
}
