#include "BGSelectorWindow.h"
#include "globals.h"

namespace editor {
	BGSelectorWindow::BGSelectorWindow(const SpriteCreator& spriteCreator,
									   Background& background,
									   const sf::Vector2i& resolution,
									   const sf::Vector2i& position,
									   const char* windowName) : WindowBase(spriteCreator, resolution, position, windowName), m_background(background)
	{
		//Add sprites for backgrounds
		m_grid->addSprite(spriteCreator.getSpriteById('a'));
		m_grid->addSprite(spriteCreator.getSpriteById('b'));
		m_grid->addSprite(spriteCreator.getSpriteById('c'));
		m_grid->addSprite(spriteCreator.getSpriteById('d'));
	}

	void BGSelectorWindow::onSelection()
	{

		if (m_selected->getId() == 'a')
		{
			printf("Selected Ground");
			m_background.changeBackground(BackgroundType::Ground);
		}
		else if (m_selected->getId() == 'b')
		{
			printf("Selected Desert");
			m_background.changeBackground(BackgroundType::Desert);
		}
		else if (m_selected->getId() == 'c')
		{
			printf("Selected Desert");
			m_background.changeBackground(BackgroundType::Water);
		}
		else if (m_selected->getId() == 'd')
		{
			printf("Selected Desert");
			m_background.changeBackground(BackgroundType::Inside);
		}
	}

}