#pragma once
#include "WindowBase.h"

namespace editor {
	class TileSelectorWindow : public WindowBase {
	public:
		TileSelectorWindow(const SpriteCreator& spriteCreator,
						   const sf::Vector2i& resolution,
						   const sf::Vector2i& position,
						   const char* windowName);
	};
}


