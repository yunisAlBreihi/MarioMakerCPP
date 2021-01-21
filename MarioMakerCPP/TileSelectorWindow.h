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
#include "WindowBase.h"

namespace editor 
{
	class TileSelectorWindow :public WindowBase
	{
	private:
		std::unique_ptr<sf::RenderWindow> m_window = nullptr;
		sf::Event m_event;

		std::unique_ptr<universal::TileBase> m_currentSelection = nullptr;
		std::unique_ptr<universal::Sprite> m_selected = nullptr;
		std::unique_ptr<universal::Grid> m_grid = nullptr;
	
	public:
		TileSelectorWindow(const SpriteCreator& spriteCreator,
						   const sf::Vector2i& resolution,
						   const sf::Vector2i& position,
						   const char* windowName);
	};
}


