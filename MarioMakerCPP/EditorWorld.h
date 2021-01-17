#pragma once
#include <SFML/Graphics.hpp>
#include "TileSelectorWindow.h"
#include "Grid.h"
#include "IOHandler.h"


namespace editor
{
	class EditorWorld
	{
	private:
		std::unique_ptr<sf::RenderWindow> m_window = nullptr;
		std::unique_ptr<TileSelectorWindow> m_tileSelectorWindow = nullptr;

		std::unique_ptr<universal::Grid> m_grid = nullptr;
		IOHandler m_saveHandler;

		sf::Event m_event;

		bool m_gameRunning = false;

	public:
		EditorWorld(const sf::Vector2i& resolution, const sf::Vector2i& position, const char* windowName);

		void eventHandler();
		void render();

		bool gameRunning();
	};
}

