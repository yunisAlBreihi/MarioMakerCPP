#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "IRender.h"

namespace universal {
	class TileBase : public universal::IRender {
	private:
		std::unique_ptr<sf::RectangleShape> m_body = nullptr;

		sf::Texture* m_texture = nullptr;
		sf::IntRect m_rect;

	public:
		TileBase(const sf::Vector2f& size, sf::Texture* texture);
		TileBase(const sf::Vector2f& position, const sf::Vector2f& size, sf::Texture* texture);
		TileBase(const TileBase& other) noexcept;

		void render(sf::RenderWindow& window) override;

		const sf::Vector2f getPosition() const;
		void setPosition(const sf::Vector2f& position);
		const sf::Vector2f getSize() const;
		void setOutlineColor(const sf::Color& color);
		const sf::Color& getFillColor() const;
	};
}