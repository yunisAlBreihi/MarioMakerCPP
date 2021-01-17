#include "Grid.h"
#include <iostream>

namespace universal
{
	Grid::Grid(const sf::Vector2i& windowSize)
	{
		m_gridSize = sf::Vector2i(windowSize.x / globals::TILE_SIZE, windowSize.y / globals::TILE_SIZE);

		for (size_t y = 0; y < m_gridSize.y; ++y) {
			m_spriteParts.push_back(std::vector<std::unique_ptr<universal::SpritePart>>());
			m_sprites.push_back(std::vector<std::unique_ptr<universal::Sprite>>());
			for (size_t x = 0; x < m_gridSize.x; ++x) {
				m_spriteParts[y].push_back(nullptr);
				m_sprites[y].push_back(nullptr);
			}
		}
	}

	void Grid::render(sf::RenderWindow& window)
	{
		for (size_t y = 0; y < m_gridSize.y; y++) {
			for (size_t x = 0; x < m_gridSize.x; x++) {
				if (m_sprites[y][x] != nullptr) {
					m_sprites[y][x]->render(window);
				}
			}
		}
	}

	void Grid::addSprite(const universal::Sprite& sprite)
	{
		for (size_t y = 0; y < m_gridSize.y; y++) {
			for (size_t x = 0; x < m_gridSize.x; x++) {
				if (m_spriteParts[y][x] == nullptr && m_sprites[y][x] == nullptr) {
					if (checkIfSpriteFit(sprite, x, y))	{
						m_sprites[y][x] = std::make_unique<universal::Sprite>(universal::Sprite(sprite));
						createSpriteParts(sprite, x, y);
						m_sprites[y][x]->setPosition(sf::Vector2f(x * globals::TILE_SIZE, y * globals::TILE_SIZE));
						return;
					}
				}
			}
		}
	}

	void Grid::addSpriteAtPosition(const universal::Sprite& sprite, const sf::Vector2i& position)
	{
		const unsigned int t_gridPosX = position.x / globals::TILE_SIZE;
		const unsigned int t_gridPosY = position.y / globals::TILE_SIZE;

		if (checkIfSpriteFit(sprite, t_gridPosX, t_gridPosY) == false) {
			return;
		}

		const universal::Sprite* t_sprite = getSpriteAtPosition(sf::Vector2i(position.x, position.y));

		if (t_sprite == nullptr) {
			std::unique_ptr<universal::Sprite> t_spriteToAdd = std::make_unique<universal::Sprite>(sprite);
			t_spriteToAdd->setPosition(sf::Vector2f(t_gridPosX * globals::TILE_SIZE, t_gridPosY * globals::TILE_SIZE));

			createSpriteParts(*t_spriteToAdd, t_gridPosX, t_gridPosY);
			m_sprites[t_gridPosY][t_gridPosX] = std::move(t_spriteToAdd);
		}
	}

	void Grid::removeSpriteAtPosition(const sf::Vector2i& position)
	{
		const unsigned int t_gridPosX = position.x / globals::TILE_SIZE;
		const unsigned int t_gridPosY = position.y / globals::TILE_SIZE;

		const universal::Sprite& t_sprite = *getSpriteAtPosition(sf::Vector2i(position.x, position.y));
		if (&t_sprite != nullptr) {
			removeSprite(t_sprite);
		}
	}

	const universal::Sprite* Grid::getSpriteAtPosition(const sf::Vector2i& position) const
	{
		const unsigned int gridPosX = position.x / globals::TILE_SIZE;
		const unsigned int gridPosY = position.y / globals::TILE_SIZE;

		if (m_spriteParts[gridPosY][gridPosX].get() != nullptr)	{
			return &(m_spriteParts[gridPosY][gridPosX]->getSprite());
		}
		else {
			return nullptr;
		}
	}

	const bool Grid::checkIfSpriteFit(const universal::Sprite& sprite, const unsigned int& indexX, const unsigned int& indexY) const
	{
		const sf::Vector2f t_bounds = sprite.getBoundsSize();

		for (int y = 0; y < t_bounds.y; ++y) {
			for (int x = 0; x < t_bounds.x; ++x) {
				if ( indexY + y > m_gridSize.y - 1 || indexX + x > m_gridSize.x - 1 ||
					m_spriteParts[indexY + y][indexX + x] != nullptr) {
					return false;
				}
			}
		}
		return true;
	}

	void Grid::createSpriteParts(const universal::Sprite& sprite, const unsigned int& indexX, const unsigned int& indexY)
	{
		const sf::Vector2f t_bounds = sprite.getBoundsSize();

		for (int y = 0; y < t_bounds.y; ++y) {
			for (int x = 0; x < t_bounds.x; ++x) {
				m_spriteParts[indexY + y][indexX + x] = std::make_unique<universal::SpritePart>(sprite);
			}
		}
	}

	void Grid::removeSprite(const Sprite& sprite)
	{
		const sf::Vector2f t_spritePos = sprite.getPosition();
		const sf::Vector2f t_spriteBounds = sprite.getBoundsSize();
		const int t_gridPosX = t_spritePos.x / globals::TILE_SIZE;
		const int t_gridPosY = t_spritePos.y / globals::TILE_SIZE;

		for (int y = 0; y < t_spriteBounds.y; ++y) {
			for (int x = 0; x < t_spriteBounds.x; ++x) {
				m_spriteParts[t_gridPosY + y][t_gridPosX + x].reset();
			}
		}
		m_sprites[t_gridPosY][t_gridPosX].reset();
	}
}
