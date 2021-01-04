#include "TileSelectorWindow.h"

namespace editor
{
	TileSelectorWindow::TileSelectorWindow(const sf::Vector2i& resolution,
										   const sf::Vector2i& position,
										   const char* windowName)
	{
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(resolution.x, resolution.y), windowName);
		m_window->setPosition(position);
	}

	void TileSelectorWindow::eventHandler()
	{
		if (m_window->pollEvent(m_event) == true) {
			if (m_event.type == sf::Event::Closed) {
				m_window->close();
			}
		}
	}

	void TileSelectorWindow::render(sf::RenderWindow* window)
	{
		m_window->clear(m_GRAY);

		//Render things here

		m_window->display();
	}
}