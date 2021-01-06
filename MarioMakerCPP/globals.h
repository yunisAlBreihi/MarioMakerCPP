#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace globals
{
	static const unsigned int TILE_SIZE = 32;

	static const sf::Color GRAY = sf::Color(128, 128, 128, 255);
	static const sf::Color UNHIGHLIGHTED_COLOR = sf::Color(0,0,0,255);
	static const sf::Color HIGHLIGHTED_COLOR = sf::Color(255,0,0,255);

	static const sf::Vector2i& getPositionInWindow(const sf::Vector2i& position, sf::RenderWindow* window)
	{
		//the extra 30.0f in "y" is compensate for the the window top ribbon
		return sf::Vector2i(position.x - window->getPosition().x,
							position.y - window->getPosition().y - 30.0f);
	}

	static bool isPositionInWindow(const sf::Vector2i& position, sf::RenderWindow* window)
	{
		const sf::Vector2i t_posInWindow = sf::Vector2i(position.x - window->getPosition().x, position.y - window->getPosition().y - 30.0f);
		const sf::Vector2u t_windowSize = window->getSize();

		if (t_posInWindow.x < 0 || t_posInWindow.y < 0 || 
			t_posInWindow.x > t_windowSize.x ||
			t_posInWindow.y > t_windowSize.y) {
			return false;
		}
		return true;
	}
}