#pragma once
#include <memory>
#include <vector>
#include "IRender.h"
#include "TileBase.h"
#include "Sprite.h"
#include "SpritePart.h"

namespace universal
{
	class Grid : public universal::IRender
	{
	private:
		std::vector<std::vector<std::unique_ptr<universal::Sprite>>> m_sprites;
		std::vector<std::vector<std::unique_ptr<universal::SpritePart>>> m_spriteParts;

		unsigned int m_gridWidth = 0;
		unsigned int m_gridHeight = 0;

	private:
		void createSpriteParts(const universal::Sprite& sprite, const unsigned int& indexX, const unsigned int& indexY);
		//bool checkSpriteParts(const unsigned int& indexX, const unsigned int& indexY) const;

	public:
		Grid(const sf::Vector2i& resolution);
		void render(sf::RenderWindow* window) override;

		void addSprite(const universal::Sprite* sprite);
		void addSpriteAtPosition(const universal::Sprite* sprite, const sf::Vector2i& position);
		const universal::Sprite* getSpriteAtPosition(const sf::Vector2i& position) const;
		const bool checkIfSpriteFit(const universal::Sprite& sprite, const unsigned int& indexX, const unsigned int& indexY) const;
	};
}