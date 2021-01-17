#pragma once
#include <memory>
#include <vector>
#include "IRender.h"
#include "TileBase.h"
#include "Sprite.h"
#include "SpritePart.h"
#include "globals.h"

namespace universal
{
	class Grid : public IRender
	{
	private:
		globals::Vector2D<std::unique_ptr<Sprite>> m_sprites;
		globals::Vector2D<std::unique_ptr<SpritePart>> m_spriteParts;

		sf::Vector2i m_gridSize;

	private:
		void createSpriteParts(const Sprite& sprite, const unsigned int& indexX, const unsigned int& indexY);
		void removeSprite(const Sprite& sprite);

	public:
		Grid(const sf::Vector2i& resolution);
		void render(sf::RenderWindow& window) override;

		void addSprite(const Sprite& sprite);
		void addSpriteAtPosition(const Sprite& sprite, const sf::Vector2i& position);
		void removeSpriteAtPosition(const sf::Vector2i& position);
		const Sprite* getSpriteAtPosition(const sf::Vector2i& position) const;
		const bool checkIfSpriteFit(const Sprite& sprite, const unsigned int& indexX, const unsigned int& indexY) const;

		inline const auto& getSprites() const { return m_sprites; }
	};
}