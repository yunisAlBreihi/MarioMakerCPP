#pragma once
#include <memory>
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "IRender.h"

namespace universal {
	class Tile : public IRender {
	private:
		std::unique_ptr<sf::RectangleShape> m_body = nullptr;

	public:
		Tile(const sf::Vector2f& size, sf::Texture* texture);
		Tile(const sf::Vector2f& size, const sf::Vector2f& position, sf::Texture* texture);
		Tile(const Tile& other) noexcept;

		void render(sf::RenderWindow& window) override;

		const sf::Vector2f getPosition() const;
		void setPosition(const sf::Vector2f& position);

	};
}
