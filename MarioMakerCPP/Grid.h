#pragma once
#include <memory>
#include <vector>
#include "IRender.h"
#include "TileBase.h"
#include "Sprite.h"
#include "SpritePart.h"

namespace universal
{
	class Grid : public IRender
	{
	private:
		std::vector<std::vector<std::unique_ptr<Sprite>>> m_sprites;
		std::vector<std::vector<std::unique_ptr<SpritePart>>> m_spriteParts;

		unsigned int m_gridWidth = 0;
		unsigned int m_gridHeight = 0;

	private:
		void createSpriteParts(const Sprite& sprite, const unsigned int& indexX, const unsigned int& indexY);

	public:
		Grid(const sf::Vector2i& resolution);
		void render(sf::RenderWindow& window) override;

		void addSprite(const Sprite& sprite);
		void addSpriteAtPosition(const Sprite& sprite, const sf::Vector2i& position);
		const Sprite* getSpriteAtPosition(const sf::Vector2i& position) const;
		const bool checkIfSpriteFit(const Sprite& sprite, const unsigned int& indexX, const unsigned int& indexY) const;

		const std::vector<std::vector<std::unique_ptr<Sprite>>>& getSprites() const;
	};
}