#include "Grid.h"
#include "globals.h"
#include <iostream>

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

	void Grid::render(sf::RenderWindow& window)
	{
		for (size_t x = 0; x < m_gridWidth; x++) {
			for (size_t y = 0; y < m_gridHeight; y++) {
				if (m_sprites[x][y] != nullptr) {
					m_sprites[x][y]->render(window);
				}
			}
		}
	}

	void Grid::addSprite(const universal::Sprite& sprite)
	{
		for (size_t x = 0; x < m_gridWidth; x++) {
			for (size_t y = 0; y < m_gridHeight; y++) {
				if (m_spriteParts[x][y] == nullptr && m_sprites[x][y] == nullptr) {
					m_sprites[x][y] = std::make_unique<universal::Sprite>(universal::Sprite(sprite));
					createSpriteParts(sprite, x, y);
					m_sprites[x][y]->setPosition(sf::Vector2f(x * globals::TILE_SIZE, y * globals::TILE_SIZE));
					return;
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
			m_sprites[t_gridPosX][t_gridPosY] = std::move(t_spriteToAdd);
		}
	}

	void Grid::removeSpriteAtPosition(const sf::Vector2i& position)
	{
		const unsigned int t_gridPosX = position.x / globals::TILE_SIZE;
		const unsigned int t_gridPosY = position.y / globals::TILE_SIZE;

		const universal::Sprite* t_sprite = getSpriteAtPosition(sf::Vector2i(position.x, position.y));

		if (t_sprite != nullptr) {

			removeSpriteParts(*t_sprite, t_gridPosX, t_gridPosY);
			m_sprites[t_gridPosX][t_gridPosY] = nullptr;
		}
	}

	const universal::Sprite* Grid::getSpriteAtPosition(const sf::Vector2i& position) const
	{
		const unsigned int gridPosX = position.x / globals::TILE_SIZE;
		const unsigned int gridPosY = position.y / globals::TILE_SIZE;

		if (m_spriteParts[gridPosX][gridPosY].get() != nullptr)	{
			return &(m_spriteParts[gridPosX][gridPosY]->getSprite());
		}
		else {
			return nullptr;
		}
	}

	const bool Grid::checkIfSpriteFit(const universal::Sprite& sprite, const unsigned int& indexX, const unsigned int& indexY) const
	{
		for (int x = 0; x < sprite.getBoundsSize().x; ++x) {
			for (int y = 0; y < sprite.getBoundsSize().y; ++y) {
				if ( indexX + x > m_gridWidth - 1 || indexY + y > m_gridHeight - 1 ||
					m_spriteParts[indexX + x][indexY + y] != nullptr) {
					return false;
				}
			}
		}
		return true;
	}

	void Grid::createSpriteParts(const universal::Sprite& sprite, const unsigned int& indexX, const unsigned int& indexY)
	{
		for (int x = 0; x < sprite.getBoundsSize().x; ++x) {
			for (int y = 0; y < sprite.getBoundsSize().y; ++y) {
				m_spriteParts[indexX + x][indexY + y] = std::make_unique<universal::SpritePart>(sprite);
			}
		}
	}

	void Grid::removeSpriteParts(const Sprite& sprite, const unsigned int& indexX, const unsigned int& indexY)
	{
		for (int x = 0; x < sprite.getBoundsSize().x; ++x) {
			for (int y = 0; y < sprite.getBoundsSize().y; ++y) {
				m_spriteParts[indexX + x][indexY + y] = nullptr;
			}
		}
	}

	const std::vector<std::vector<std::unique_ptr<Sprite>>>& Grid::getSprites() const
	{
		return m_sprites;
	}
}
