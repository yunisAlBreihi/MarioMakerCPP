#include "EditorWorld.h"
#include <iostream>
#include "globals.h"

namespace editor
{
	EditorWorld::EditorWorld(const sf::Vector2i& resolution,
							 const sf::Vector2i& position,
							 const char* windowName)
	{
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(resolution.x, resolution.y), windowName);
		m_window->setPosition(position);

		m_tileSelectorWindow = std::make_unique<TileSelectorWindow>(sf::Vector2i(200, 720), 
																	sf::Vector2i(position.x + resolution.x, position.y), 
																	"Tile Selector");

		m_grid = std::make_unique<universal::Grid>(resolution);

		m_gameRunning = true;
	}

	void EditorWorld::start()
	{

	}

	void EditorWorld::eventHandler()
	{
		if (m_window->pollEvent(m_event) == true) {
			if (m_event.type == sf::Event::Closed) {
				m_window->close();
				m_gameRunning = false;
			}
		}

		if (m_tileSelectorWindow != nullptr) {
			m_tileSelectorWindow->eventHandler();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
			if (globals::isPositionInWindow(sf::Mouse::getPosition(), &*m_window) == true) {
				//if (m_tileSelectorWindow->getCurrentSelection() != nullptr) {
				//	sf::Vector2i t_mousePos = globals::getPositionInWindow(sf::Mouse::getPosition(), &*m_window);
				//	m_grid->addTileAtPosition(m_tileSelectorWindow->getCurrentSelection(), t_mousePos);
				//}

				if (m_tileSelectorWindow->getSelected() != nullptr) {
					sf::Vector2i t_mousePos = globals::getPositionInWindow(sf::Mouse::getPosition(), &*m_window);
					m_grid->addSpriteAtPosition(m_tileSelectorWindow->getSelected(), t_mousePos);
				}
			}
		}
	}

	void EditorWorld::render()
	{
		m_window->clear();

		//Render things here
		m_tileSelectorWindow->render(&*m_window);
		m_grid->render(&*m_window);

		m_window->display();
	}

	bool EditorWorld::gameRunning()
	{
		return m_gameRunning;
	}
}
