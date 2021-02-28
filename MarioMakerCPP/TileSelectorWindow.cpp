#include "TileSelectorWindow.h"
#include "globals.h"

namespace editor {
	TileSelectorWindow::TileSelectorWindow(const SpriteCreator& spriteCreator,
		const sf::Vector2i& resolution,
		const sf::Vector2i& position,
		const char* windowName) : WindowBase(spriteCreator, resolution, position, windowName) {
		m_grid->addSprite(spriteCreator.getSpriteById('0'));
		m_grid->addSprite(spriteCreator.getSpriteById('1'));
		m_grid->addSprite(spriteCreator.getSpriteById('3'));
		m_grid->addSprite(spriteCreator.getSpriteById('4'));
		m_grid->addSprite(spriteCreator.getSpriteById('5'));
		m_grid->addSprite(spriteCreator.getSpriteById('6'));
	}

	void TileSelectorWindow::onSelection()
	{
		printf("Selected in TileSelector");
	}
}