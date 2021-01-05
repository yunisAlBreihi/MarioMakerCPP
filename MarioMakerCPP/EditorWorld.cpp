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
			sf::Vector2i t_mousePos = globals::positionInWindow(sf::Mouse::getPosition(), &*m_window);
			//std::cout << "Mouse X: " << t_mousePos.x << " Mouse Y: " << t_mousePos.y << std::endl;
			paint(m_tileSelectorWindow->getCurrentSelection(), t_mousePos);
		}
	}

	void EditorWorld::render()
	{
		m_window->clear();

		//Render things here
		m_tileSelectorWindow->render(&*m_window);

		for (const auto& t_paintedTile : m_paintedObjects) {
			if (t_paintedTile != nullptr) {
				t_paintedTile->render(&*m_window);
			}
		}

		m_window->display();
	}

	bool EditorWorld::gameRunning()
	{
		return m_gameRunning;
	}

	void EditorWorld::paint(const universal::TileBase* objectToPaint, const sf::Vector2i& position)
	{
		if (objectToPaint != nullptr) {
			universal::TileBase* t_tileCopy = new universal::TileBase(*objectToPaint);
			t_tileCopy->setPosition(sf::Vector2f(position.x, position.y));
			m_paintedObjects.push_back(t_tileCopy);
		}
	}
}
