#pragma once
#include "WindowBase.h"
#include "Background.h"

namespace editor {
	class BGSelectorWindow : public WindowBase	{
	private:
		Background& m_background;

	public:
		BGSelectorWindow(const SpriteCreator& spriteCreator,
						 Background& background,
						 const sf::Vector2i& resolution,
						 const sf::Vector2i& position,
						 const char* windowName);

		void onSelection() override;
	};
}