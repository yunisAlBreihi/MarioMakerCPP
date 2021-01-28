#pragma once
#include "WindowBase.h"
namespace editor 
{
	class BGSelectorWindow : public WindowBase
	{
	public:
		BGSelectorWindow(const SpriteCreator& spriteCreator,
						 const sf::Vector2i& resolution,
						 const sf::Vector2i& position,
						 const char* windowName);
	};
}