#pragma once
#include <memory>
#include <vector>
#include "SFML/Graphics/Texture.hpp"
#include "Tile.h"
#include "IRender.h"

namespace universal
{
	class Sprite : public IRender
	{
	private:
		std::vector<std::unique_ptr<Tile>> m_tiles;
		sf::Vector2f m_position;

	public:
		void render(sf::RenderWindow* window) override;

		void addTile(const Tile* tile);
	};
}