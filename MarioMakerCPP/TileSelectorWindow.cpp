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
		m_spriteCreator = std::make_unique<SpriteCreator>();

		m_breakableBlockSprite = std::move(m_spriteCreator->CreateSprite(globals::PATH_TILESHEET, 1, sf::Vector2i(1, 1), '0'));
		m_grid->addSprite(*m_breakableBlockSprite);

		m_coinBlockSprite = std::move(m_spriteCreator->CreateSprite(globals::PATH_TILESHEET, 2, sf::Vector2i(1, 1), '1'));
		m_grid->addSprite(*m_coinBlockSprite);

		m_noteBlockSprite = std::move(m_spriteCreator->CreateSprite(globals::PATH_TILESHEET, 4, sf::Vector2i(1, 1), '3'));
		m_grid->addSprite(*m_noteBlockSprite);

		m_solidBlockSprite = std::move(m_spriteCreator->CreateSprite(globals::PATH_TILESHEET, 6, sf::Vector2i(1, 1), '4'));
		m_grid->addSprite(*m_solidBlockSprite);

		m_groundBlockSprite = std::move(m_spriteCreator->CreateSprite(globals::PATH_TILESHEET, 121, sf::Vector2i(1, 1), '5'));
		m_grid->addSprite(*m_groundBlockSprite);

		m_pipeSprite = std::move(m_spriteCreator->CreateSprite(globals::PATH_TILESHEET, 14, sf::Vector2i(2, 2), '9'));
		m_grid->addSprite(*m_pipeSprite);
	}

	void TileSelectorWindow::eventHandler()
	{
		if (m_window->pollEvent(m_event) == true) {
			if (m_event.type == sf::Event::Closed) {
				m_window->close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
				if (globals::isPositionInWindow(sf::Mouse::getPosition(), &*m_window) == true) {
					sf::Vector2i t_windowPos = globals::getPositionInWindow(sf::Mouse::getPosition(), &*m_window);
					const universal::Sprite* t_sprite = m_grid->getSpriteAtPosition(t_windowPos);

					if (t_sprite != nullptr) {
						m_selected = std::make_unique<universal::Sprite>(*t_sprite);
					}
				}
			}
		}
	}

	void TileSelectorWindow::render(sf::RenderWindow& window)
	{
		m_window->clear(globals::GRAY);

		//Render things here
		m_grid->render(*m_window);

		m_window->display();
	}

	const bool TileSelectorWindow::selectTile(universal::TileBase* tile)
	{
		const sf::Vector2i t_localMousePos = globals::getPositionInWindow(sf::Mouse::getPosition(), &*m_window);
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

	const universal::Sprite* TileSelectorWindow::getSelected()
	{
		return &*m_selected;
	}
}