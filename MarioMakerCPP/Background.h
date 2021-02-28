#pragma once
#include <memory>
#include "IRender.h"
#include "Sprite.h"

namespace editor {

	enum class BackgroundType
	{
		Ground,
		Desert,
		Water,
		Inside,
		Snow,
		Sky,
		Forest,
		Night,
		WaterNight,
		SnowNight,
		GhostHouseNight,
	};

	class Background : public universal::IRender {
	private:
		std::vector<std::unique_ptr<sf::RectangleShape>> m_bodies;

		const char* m_filePath = "";
		int repeatIndex = 0;

		//For getting tiles from sprite sheet
		const float m_bgTileSize = 34.0f;
		const float m_numTiles = 12.0f;
		const float m_aspectX = 3.0f;
		const float m_aspectY = 2.0f;
		const float m_seperator = 1.0f;
		const float m_topRibbon = 10.0f;
		const float m_tileOffset = 9.0f;
		
	public:
		Background(const char* filepath);

		void render(sf::RenderWindow& window) override;

		void addBackgroundRepeat();
		void changeBackground(BackgroundType backgroundType);
	};
}