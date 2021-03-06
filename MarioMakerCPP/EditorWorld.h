#pragma once
#include <SFML/Graphics.hpp>
#include "TileSelectorWindow.h"
#include "Grid.h"
#include "IOHandler.h"
#include "BGSelectorWindow.h"
#include "Background.h";

namespace editor {
	class EditorWorld 	{
	private:
		std::unique_ptr<sf::RenderWindow> m_window = nullptr;
		std::unique_ptr<TileSelectorWindow> m_tileSelectorWindow = nullptr;
		std::unique_ptr<BGSelectorWindow> m_bgSelectorWindow = nullptr;

		std::unique_ptr<SpriteCreator> m_spriteCreator = nullptr;

		std::unique_ptr<universal::Grid> m_grid = nullptr;
		IOHandler m_IOHandler;

		sf::Event m_event;

		bool m_gameRunning = false;
		bool m_loadLevel = true;
		bool m_saveLevel = true;

		std::unique_ptr<editor::Background> m_background;

	public:
		EditorWorld(const sf::Vector2i& resolution, const sf::Vector2i& position, const char* windowName);

		void eventHandler();
		void render();

		bool gameRunning();
	};
}

