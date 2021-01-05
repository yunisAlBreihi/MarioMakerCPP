#pragma once
#include <SFML/Graphics.hpp>
#include "TileSelectorWindow.h"
#include "Grid.h"


namespace editor
{
	class EditorWorld
	{
	private:
		std::unique_ptr<universal::Grid> m_grid = nullptr;

		std::unique_ptr<sf::RenderWindow> m_window = nullptr;
		std::unique_ptr<TileSelectorWindow> m_tileSelectorWindow = nullptr;
		sf::Event m_event;

		//std::vector<universal::TileBase*> m_paintedObjects;

		bool m_gameRunning = false;

	public:
		EditorWorld(const sf::Vector2i& resolution, const sf::Vector2i& position, const char* windowName);

		void start();
		void eventHandler();
		void render();

		bool gameRunning();

		//void paint(const universal::TileBase* objectToPaint, const sf::Vector2i& position);
	};
}

