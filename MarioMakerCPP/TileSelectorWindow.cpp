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

		m_sprite = std::move(m_spriteCreator->CreateSprite("Sprites/SMB_tiles_tilesheet.png", 47, sf::Vector2i(4,3)));

		//std::unique_ptr<universal::TileBase> t_tile = nullptr;
		//const sf::Vector2f t_tileSize = sf::Vector2f(globals::TILE_SIZE, globals::TILE_SIZE);

		//sf::Texture* t_tex = new sf::Texture(m_spriteCreator->CreateSprite("Sprites/SMB_tiles_tilesheet.png", 
		//	3));
		//t_tile = std::make_unique<universal::TileBase>(t_tileSize, t_tex);
		//m_grid->addTile(&*t_tile);

		//t_tex = new sf::Texture(m_spriteCreator->CreateSprite("Sprites/SMB_tiles_tilesheet.png", 24));
		//t_tile = std::make_unique<universal::TileBase>(t_tileSize, t_tex);
		//m_grid->addTile(&*t_tile);
	}

	void TileSelectorWindow::eventHandler()
	{
		if (m_window->pollEvent(m_event) == true) {
			if (m_event.type == sf::Event::Closed) {
				m_window->close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
				if (globals::isPositionInWindow(sf::Mouse::getPosition(), &*m_window) == true)
				{
					sf::Vector2i t_windowPos = globals::getPositionInWindow(sf::Mouse::getPosition(), &*m_window);
					const universal::TileBase* t_tile = &m_grid->getTileAtPosition(t_windowPos);

					if (t_tile != nullptr) {
						m_currentSelection = std::make_unique<universal::TileBase>(*t_tile);
					}
				}
			}
		}
	}

	void TileSelectorWindow::render(sf::RenderWindow* window)
	{
		m_window->clear(globals::GRAY);

		m_sprite->render(&*m_window);
		m_grid->render(&*m_window);

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
}