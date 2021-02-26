#include "Tile.h"

universal::Tile::Tile(const sf::Vector2f& size, sf::Texture* texture) {
	m_body = std::make_unique<sf::RectangleShape>(size);
	m_body->setOutlineColor(sf::Color::Black);
	m_body->setOutlineThickness(2);
	m_body->setTexture(texture);
}

universal::Tile::Tile(const sf::Vector2f& size, const sf::Vector2f& position, sf::Texture* texture) {
	m_body = std::make_unique<sf::RectangleShape>(size);
	m_body->setPosition(position);
	m_body->setOutlineColor(sf::Color::Black);
	m_body->setOutlineThickness(2);
	m_body->setTexture(texture);
}

universal::Tile::Tile(const Tile& other) noexcept {
	m_body = std::make_unique<sf::RectangleShape>(other.m_body->getSize());
	m_body->setPosition(other.m_body->getPosition());
	m_body->setTexture(other.m_body->getTexture());
}

void universal::Tile::render(sf::RenderWindow& window) {
	window.draw(*m_body);
}

const sf::Vector2f universal::Tile::getPosition() const {
	return m_body->getPosition();
}

void universal::Tile::setPosition(const sf::Vector2f& position) {
	m_body->setPosition(position);
}
