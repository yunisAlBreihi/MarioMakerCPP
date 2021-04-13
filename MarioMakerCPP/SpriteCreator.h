#pragma once
#include "SFML/Graphics/Texture.hpp"
#include <memory>
#include "SFML/System/Vector2.hpp"
#include "Sprite.h"

namespace editor {
	enum class  SpriteType 
	{
		Ground,
		Desert,
		Water,
		Underground,
		GhostHouse,
		Castle,
		Snow,
		Airship,
		Forest,
		GroundNight,
		AirshipNight,
		WaterNight,
		SnowNight,
		GhostHouseNight,
	};

	class SpriteCreator {
	private:
		std::vector<std::unique_ptr<universal::Sprite>> m_sprites;

		const unsigned int m_headerSize = 11;
		const unsigned int m_separatorSize = 1;
		const unsigned int m_tileSheetLength = 16;
		const unsigned int m_tileSize = 16;

	public:
		sf::Texture CreateSprite(const char* spritePath, const unsigned int spriteIndex);
		void CreateSprite(const char* spritePath, sf::Vector2u spriteIndex, const sf::Vector2i& spriteSize, const char& id);

		const universal::Sprite& getSpriteById(const char& id) const;

		void changeSprite(SpriteType type);
	};
}
