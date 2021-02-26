#include "TileBase.h"
#include "globals.h"

namespace universal {
	TileBase::TileBase(const sf::Vector2f& size, sf::Texture* texture) {
		m_body = std::make_unique<sf::RectangleShape>(size);
		m_body->setOutlineColor(sf::Color::Black);
		m_body->setOutlineThickness(2);
		m_body->setTexture(texture);
	}

	TileBase::TileBase(const sf::Vector2f& position, const sf::Vector2f& size, sf::Texture* texture) {
		m_body = std::make_unique<sf::RectangleShape>(size);
		m_body->setPosition(position);
		m_body->setOutlineColor(sf::Color::Black);
		m_body->setOutlineThickness(2);
		m_body->setTexture(texture);
	}

	TileBase::TileBase(const TileBase& other) noexcept {
		m_body = std::make_unique<sf::RectangleShape>(other.m_body->getSize());
		m_body->setPosition(other.m_body->getPosition());
		m_body->setTexture(other.m_body->getTexture());
	}


	void TileBase::render(sf::RenderWindow& window) {
		window.draw(*m_body);
	}

	const sf::Vector2f TileBase::getPosition() const {
		return m_body->getPosition();
	}

	void TileBase::setPosition(const sf::Vector2f& position) {
		m_body->setPosition(position);
	}

	const sf::Vector2f TileBase::getSize() const {
		return m_body->getSize();
	}

	void TileBase::setOutlineColor(const sf::Color& color) {
		m_body->setOutlineColor(color);
	}

	const sf::Color& TileBase::getFillColor() const {
		return m_body->getFillColor();
	}
}