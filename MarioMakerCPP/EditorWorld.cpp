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
		m_rectangle = new sf::RectangleShape(sf::Vector2f(32.0f,32.0f));

		m_texture = new sf::Texture();
		m_rect = new sf::IntRect(sf::Vector2i(32, 32), sf::Vector2i(16, 16));

		m_texture->loadFromFile("spritesheet.png", *m_rect);
		m_rectangle->setTexture(m_texture);
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
			if (m_tileSelectorWindow->getCurrentSelection() != nullptr) {
				sf::Vector2i t_mousePos = globals::positionInWindow(sf::Mouse::getPosition(), &*m_window);
				m_grid->addTileAtPosition(m_tileSelectorWindow->getCurrentSelection(), t_mousePos);
			}
		}
	}

	void EditorWorld::render()
	{
		m_window->clear();

		//Render things here
		m_tileSelectorWindow->render(&*m_window);
		m_grid->render(&*m_window);

		m_window->draw(*m_rectangle);

		m_window->display();
	}

	bool EditorWorld::gameRunning()
	{
		return m_gameRunning;
	}
}
