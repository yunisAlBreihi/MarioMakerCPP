#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "IRender.h"

namespace universal
{
	class TileBase : public universal::IRender
	{
	private:
		std::unique_ptr<sf::RectangleShape> m_body = nullptr;

	public:
		TileBase(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color);
		TileBase(const TileBase& other) noexcept;

		void render(sf::RenderWindow* window) override;

		const sf::Vector2f getPosition();
		void setPosition(const sf::Vector2f& position);
		const sf::Vector2f getSize();

		void setOutlineColor(const sf::Color& color);
	};
}