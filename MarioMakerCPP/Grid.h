#pragma once
#include <memory>
#include <vector>
#include "IRender.h"
#include "TileBase.h"

namespace universal 
{
	class Grid : public universal::IRender
	{
	private:
		std::vector<std::vector<std::unique_ptr<universal::TileBase>>> m_tiles;

		unsigned int m_gridWidth = 0;
		unsigned int m_gridHeight = 0;

	public:
		Grid(const sf::Vector2i& windowSize);

		void render(sf::RenderWindow* window) override;

		void addTileAtPosition(const universal::TileBase* tileToAdd, const sf::Vector2i& position);
		const universal::TileBase& getTileAtPosition(const sf::Vector2i& position)const;
	};
}