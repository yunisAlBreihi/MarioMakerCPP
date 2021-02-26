#include "BGSelectorWindow.h"
#include "globals.h"

namespace editor {
	BGSelectorWindow::BGSelectorWindow(const SpriteCreator& spriteCreator,
		const sf::Vector2i& resolution,
		const sf::Vector2i& position,
		const char* windowName) : WindowBase(spriteCreator, resolution, position, windowName)
	{
		//Add sprites for backgrounds
		m_grid->addSprite(spriteCreator.getSpriteById('a'));
	}
}