#pragma once
#include <memory>
#include "SFML/Graphics/Texture.hpp"

namespace universal
{
	class Sprite
	{
		std::unique_ptr<sf::Texture> m_texture = nullptr;
	};
}
