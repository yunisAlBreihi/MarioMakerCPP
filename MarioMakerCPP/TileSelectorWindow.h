#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "IRender.h"
#include "IEventHandler.h"
#include "TileBase.h"
#include "Grid.h"
#include "SpriteCreator.h"
#include "Sprite.h"

namespace editor 
{
	class TileSelectorWindow :public universal::IEventHandler, public universal::IRender
	{
	private:
		std::unique_ptr<sf::RenderWindow> m_window = nullptr;
		sf::Event m_event;

		std::unique_ptr<universal::TileBase> m_currentSelection = nullptr;
		std::unique_ptr<universal::Sprite> m_selected = nullptr;
		std::unique_ptr<universal::Grid> m_grid = nullptr;
		
		std::unique_ptr<SpriteCreator> m_spriteCreator = nullptr;

		std::unique_ptr<universal::Sprite> m_solidBlockSprite = nullptr;
		std::unique_ptr<universal::Sprite> m_breakableBlockSprite = nullptr;
		std::unique_ptr<universal::Sprite> m_coinBlockSprite = nullptr;
		std::unique_ptr<universal::Sprite> m_noteBlockSprite = nullptr;
		std::unique_ptr<universal::Sprite> m_groundBlockSprite = nullptr;
		std::unique_ptr<universal::Sprite> m_pipeSprite = nullptr;
	public:
		TileSelectorWindow(const sf::Vector2i& resolution, const sf::Vector2i& position, const char* windowName);

		void eventHandler() override;
		void render(sf::RenderWindow& window) override;

		const bool selectTile(universal::TileBase* tile);
		const universal::TileBase* getCurrentSelection();
		const universal::Sprite* getSelected();
	};
}


