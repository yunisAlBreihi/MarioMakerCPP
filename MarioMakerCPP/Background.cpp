#include "Background.h"
#include "SFML/Graphics/Texture.hpp"
#include "globals.h"

namespace editor {
	Background::Background(const char* filepath) : m_filePath(filepath) {
		addBackgroundRepeat();
		addBackgroundRepeat();
		addBackgroundRepeat();

		changeBackground(BackgroundType::Forest);
	}

	void Background::render(sf::RenderWindow& window) {
		for (auto& t_body : m_bodies) {
			window.draw(*t_body);
		}
	}

	void Background::addBackgroundRepeat() {

		std::unique_ptr<sf::RectangleShape> t_body = std::make_unique<sf::RectangleShape>(sf::Vector2f(m_bgTileSize * m_numTiles * m_aspectX,
																									   m_bgTileSize * m_numTiles * m_aspectY));

		t_body->setPosition((m_bgTileSize * m_numTiles * m_aspectX) * repeatIndex, 0);
		sf::Texture* t_texture = new sf::Texture();
		sf::Vector2i t_rectPos(m_seperator, m_topRibbon + m_seperator + (m_bgTileSize * 0.5f) * m_tileOffset);
		sf::Vector2i t_rectSize((m_bgTileSize * 0.5f) * 10 * m_aspectX, (m_bgTileSize * 0.5f) * 10 * m_aspectY);
		sf::IntRect t_rect = { t_rectPos, t_rectSize };
		t_texture->loadFromFile(m_filePath, t_rect);
		t_body->setTexture(t_texture);

		m_bodies.push_back(std::move(t_body));
		repeatIndex++;
	}

	void Background::changeBackground(BackgroundType backgroundType)
	{
		sf::Texture* t_texture = new sf::Texture();
		sf::Vector2i t_rectPos(m_seperator, m_topRibbon + m_seperator + (m_bgTileSize * 0.5f) * m_tileOffset);
		sf::Vector2i t_rectSize((m_bgTileSize * 0.5f) * 10 * m_aspectX, (m_bgTileSize * 0.5f) * 10 * m_aspectY);
		sf::IntRect t_rect = { t_rectPos, t_rectSize };
		t_texture->loadFromFile(m_filePath, t_rect);

		for (auto& t_body : m_bodies) {
			switch (backgroundType) {
			case editor::BackgroundType::Ground:
				t_body->setTexture(t_texture);
				break;
			case editor::BackgroundType::Desert:
				t_rectPos.y += (m_backgroundTypeSizeY - 1.0f);
				t_rect = { t_rectPos , t_rectSize };
				t_texture->loadFromFile(m_filePath, t_rect);
				t_body->setTexture(t_texture);
				break;
			case editor::BackgroundType::Water:
				t_rectPos.x = m_backgroundTypeSizeX;
				t_rectPos.y += (m_backgroundTypeSizeY - 1.0f);
				t_rect = { t_rectPos , t_rectSize };
				t_texture->loadFromFile(m_filePath, t_rect);
				t_body->setTexture(t_texture);
				break;
			case editor::BackgroundType::Inside:
				t_rectPos.x = m_backgroundTypeSizeX;
				t_rectPos.y += (m_backgroundTypeSizeY - 1.0f) * 2.0f;
				t_rect = { t_rectPos , t_rectSize };
				t_texture->loadFromFile(m_filePath, t_rect);
				t_body->setTexture(t_texture);
				break;
			case editor::BackgroundType::Snow:
				t_rectPos.y += (m_backgroundTypeSizeY -1.0f) * 3.0f;
				t_rect = { t_rectPos , t_rectSize };
				t_texture->loadFromFile(m_filePath, t_rect);
				t_body->setTexture(t_texture);
				break;
			case editor::BackgroundType::Sky:
				t_rectPos.y += (m_backgroundTypeSizeY - 1.0f) * 4.0f;
				t_rect = { t_rectPos , t_rectSize };
				t_texture->loadFromFile(m_filePath, t_rect);
				t_body->setTexture(t_texture);
				break;
			case editor::BackgroundType::Forest:
				t_rectPos.y += (m_backgroundTypeSizeY - 1.0f + m_bgTileSize) * 5.0f;
				t_rect = { t_rectPos , t_rectSize };
				t_texture->loadFromFile(m_filePath, t_rect);
				t_body->setTexture(t_texture);
				break;
			case editor::BackgroundType::Night:
				t_rectPos.y += (m_backgroundTypeSizeY - 1.0f) * 7.0f;
				t_rect = { t_rectPos , t_rectSize };
				t_texture->loadFromFile(m_filePath, t_rect);
				t_body->setTexture(t_texture);
				break;
			case editor::BackgroundType::WaterNight:
				t_rectPos.y += (m_backgroundTypeSizeY - 1.0f) * 8.0f;
				t_rect = { t_rectPos , t_rectSize };
				t_texture->loadFromFile(m_filePath, t_rect);
				t_body->setTexture(t_texture);
				break;
			case editor::BackgroundType::SnowNight:
				t_rectPos.y += (m_backgroundTypeSizeY - 1.0f) * 11.0f;
				t_rect = { t_rectPos , t_rectSize };
				t_texture->loadFromFile(m_filePath, t_rect);
				t_body->setTexture(t_texture);
				break;
			case editor::BackgroundType::GhostHouseNight:
				t_rectPos.y += (m_backgroundTypeSizeY - 1.0f) * 12.0f;
				t_rect = { t_rectPos , t_rectSize };
				t_texture->loadFromFile(m_filePath, t_rect);
				t_body->setTexture(t_texture);
				break;
			}
		}
	}
}