#include "TileSelectorWindow.h"
#include "globals.h"

namespace editor
{
	TileSelectorWindow::TileSelectorWindow(const sf::Vector2i& resolution,
		const sf::Vector2i& position,
		const char* windowName)
	{
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(resolution.x, resolution.y), windowName);
		m_window->setPosition(position);

		m_grid = std::make_unique<universal::Grid>(resolution);

		//for (size_t j = 0; j < 10; j++) {
		//	for (size_t i = 0; i < 2; i++)
		//	{
		//		sf::Color t_color;
		//			if (i == 0)	{
		//				t_color = sf::Color::Blue;
		//			}
		//			else {
		//				t_color = sf::Color::Green;
		//			}
		//		std::unique_ptr t_tile = std::make_unique<universal::TileBase>(sf::Vector2f(i * globals::TILE_SIZE + i, j * globals::TILE_SIZE + j),
		//			sf::Vector2f(globals::TILE_SIZE, globals::TILE_SIZE),
		//			t_color);
		//		m_tiles.push_back(std::move(t_tile));
		//	}
		//}
	}

	void TileSelectorWindow::eventHandler()
	{
		if (m_window->pollEvent(m_event) == true) {
			if (m_event.type == sf::Event::Closed) {
				m_window->close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
				sf::Vector2i t_windowPos = globals::positionInWindow(sf::Mouse::getPosition(), &*m_window);
				const universal::TileBase* t_tile = &m_grid->getTileAtPosition(t_windowPos);

				if (t_tile != nullptr) {
					m_currentSelection = std::make_unique<universal::TileBase>(*t_tile);
				}

				//for (auto it = m_tiles.begin(); it != m_tiles.end(); ++it) {
				//	if (*it != nullptr) {
				//		if (selectTile(&**it) == true) {
				//			if (m_selectedTile != *it) {

				//				if (m_selectedTile != nullptr) {
				//					m_selectedTile->setOutlineColor(globals::UNHIGHLIGHTED_COLOR);
				//					m_tiles.emplace_back(std::move(m_selectedTile));
				//				}
				//				m_selectedTile = std::move(*it);
				//				m_selectedTile->setOutlineColor(globals::HIGHLIGHTED_COLOR);

				//				m_tiles.erase(it);
				//				break;
				//			}
				//		}
				//	}
				//}
			}
		}
	}

	void TileSelectorWindow::render(sf::RenderWindow* window)
	{
		m_window->clear(globals::GRAY);

		//Render things here
		//for (const auto& t_tile : m_tiles) {
		//	if (t_tile != nullptr) {
		//		t_tile->render(&*m_window);
		//	}
		//}

		//if (m_currentSelection != nullptr) {
		//	m_currentSelection->render(&*m_window);
		//}

		m_window->display();
	}

	const bool TileSelectorWindow::selectTile(universal::TileBase* tile)
	{
		const sf::Vector2i t_localMousePos = globals::positionInWindow(sf::Mouse::getPosition(), &*m_window);
		const sf::Vector2f t_tilePos = tile->getPosition();
		const sf::Vector2f t_tileSize = tile->getSize();

		bool left = t_localMousePos.x > t_tilePos.x;
		bool right = t_localMousePos.x < t_tilePos.x + t_tileSize.x;
		bool top = t_localMousePos.y > t_tilePos.y;
		bool bot = t_localMousePos.y < t_tilePos.y + t_tileSize.y;

		if (left == true && top == true && right == true && bot == true) {
			return true;
		}
		return false;
	}

	const universal::TileBase* TileSelectorWindow::getCurrentSelection()
	{
		return &*m_currentSelection;
	}
}