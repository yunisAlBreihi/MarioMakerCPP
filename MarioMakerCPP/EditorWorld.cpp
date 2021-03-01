#include "EditorWorld.h"
#include <iostream>
#include <fstream>
#include "globals.h"

namespace editor
{
	EditorWorld::EditorWorld(const sf::Vector2i& resolution,
		const sf::Vector2i& position,
		const char* windowName) {
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(resolution.x, resolution.y), windowName);
		m_window->setPosition(position);

		m_spriteCreator = std::make_unique<SpriteCreator>();
		m_spriteCreator->CreateSprite(globals::TILE_TILESHEET_PATH, sf::Vector2u(1, 0), sf::Vector2i(1, 1), '0');
		m_spriteCreator->CreateSprite(globals::TILE_TILESHEET_PATH, sf::Vector2u(2, 0), sf::Vector2i(1, 1), '1');
		m_spriteCreator->CreateSprite(globals::TILE_TILESHEET_PATH, sf::Vector2u(4, 0), sf::Vector2i(1, 1), '3');
		m_spriteCreator->CreateSprite(globals::TILE_TILESHEET_PATH, sf::Vector2u(6, 0), sf::Vector2i(1, 1), '4');
		m_spriteCreator->CreateSprite(globals::TILE_TILESHEET_PATH, sf::Vector2u(15, 7), sf::Vector2i(1, 1), '5');
		m_spriteCreator->CreateSprite(globals::TILE_TILESHEET_PATH, sf::Vector2u(14, 0), sf::Vector2i(2, 2), '6');

		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(1, 0), sf::Vector2i(2, 2), 'a');
		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(6, 0), sf::Vector2i(2, 2), 'b');
		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(10, 0), sf::Vector2i(2, 2), 'c');
		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(14, 0), sf::Vector2i(2, 2), 'd');
		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(14, 0), sf::Vector2i(2, 2), 'e');
		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(14, 0), sf::Vector2i(2, 2), 'f');
		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(1, 2), sf::Vector2i(2, 2), 'g');
		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(6, 2), sf::Vector2i(2, 2), 'h');
		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(10, 2), sf::Vector2i(2, 2), 'i');
		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(14, 2), sf::Vector2i(2, 2), 'j');
		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(14, 2), sf::Vector2i(2, 2), 'k');
		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(1, 4), sf::Vector2i(2, 2), 'l');
		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(6, 4), sf::Vector2i(2, 2), 'm');
		m_spriteCreator->CreateSprite(globals::BG_THUMBNAILS_PATH, sf::Vector2u(10, 4), sf::Vector2i(2, 2), 'n');

		m_background = std::make_unique<editor::Background>(globals::BG_TILESHEET_PATH);

		m_tileSelectorWindow = std::make_unique<TileSelectorWindow>(
			*m_spriteCreator,
			sf::Vector2i(200, 720),
			sf::Vector2i(position.x + resolution.x, position.y),
			"Tile Selector");

		m_bgSelectorWindow = std::make_unique<BGSelectorWindow>(
			*m_spriteCreator,
			*m_background,
			sf::Vector2i(200, 720),
			sf::Vector2i(position.x - 200, position.y),
			"Background Selector");

		m_grid = std::make_unique<universal::Grid>(resolution);

		m_gameRunning = true;

		if (m_loadLevel == true) {
			m_IOHandler.loadGrid(*m_spriteCreator, *m_grid, "MarioLevel1.txt");
		}

	}

	void EditorWorld::eventHandler() {
		if (m_window->pollEvent(m_event) == true) {
			if (m_event.type == sf::Event::Closed) {
				m_window->close();
				m_gameRunning = false;

				if (m_saveLevel == true) {
					m_IOHandler.saveGrid(*m_grid, "MarioLevel1.txt");
				}
			}
		}

		if (m_tileSelectorWindow != nullptr) {
			m_tileSelectorWindow->eventHandler();
		}

		if (m_bgSelectorWindow != nullptr) {
			m_bgSelectorWindow->eventHandler();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
			if (globals::isPositionInWindow(sf::Mouse::getPosition(), *m_window) == true) {
				if (&m_tileSelectorWindow->getSelected() != nullptr) {
					sf::Vector2i t_mousePos = globals::getPositionInWindow(sf::Mouse::getPosition(), *m_window);
					m_grid->addSpriteAtPosition(m_tileSelectorWindow->getSelected(), t_mousePos);
				}
			}
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) == true) {
			if (globals::isPositionInWindow(sf::Mouse::getPosition(), *m_window) == true) {
				sf::Vector2i t_mousePos = globals::getPositionInWindow(sf::Mouse::getPosition(), *m_window);
				m_grid->removeSpriteAtPosition(t_mousePos);
			}
		}
	}

	void EditorWorld::render() {
		m_window->clear();

		//Render things here, between the clear and display.
		m_background->render(*m_window);
		m_tileSelectorWindow->render(*m_window);
		m_bgSelectorWindow->render(*m_window);
		m_grid->render(*m_window);

		m_window->display();
	}

	bool EditorWorld::gameRunning() {
		return m_gameRunning;
	}
}
