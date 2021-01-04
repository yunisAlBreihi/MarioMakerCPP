#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "IRender.h"
#include "IEventHandler.h"

namespace editor 
{
	class TileSelectorWindow :public universal::IEventHandler, public universal::IRender
	{
	private:
		std::unique_ptr<sf::RenderWindow> m_window = nullptr;
		sf::Event m_event;

		const sf::Color m_GRAY = sf::Color(128,128,128,255);

	public:
		TileSelectorWindow(const sf::Vector2i& resolution, const sf::Vector2i& position, const char* windowName);

		void eventHandler() override;
		void render(sf::RenderWindow* window) override;

	};
}


