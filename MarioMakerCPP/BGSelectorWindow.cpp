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
		m_grid->addSprite(spriteCreator.getSpriteById('e'));
		m_grid->addSprite(spriteCreator.getSpriteById('f'));
		m_grid->addSprite(spriteCreator.getSpriteById('g'));
		m_grid->addSprite(spriteCreator.getSpriteById('h'));
		m_grid->addSprite(spriteCreator.getSpriteById('i'));
		m_grid->addSprite(spriteCreator.getSpriteById('j'));
		m_grid->addSprite(spriteCreator.getSpriteById('k'));
		m_grid->addSprite(spriteCreator.getSpriteById('l'));
		m_grid->addSprite(spriteCreator.getSpriteById('m'));
		m_grid->addSprite(spriteCreator.getSpriteById('n'));
	}

	void BGSelectorWindow::onSelection()
	{
		if (m_selected->getId() == 'a')
		{
			printf("Selected Ground\n");
			m_background.changeBackground(BackgroundType::Ground);
		}
		else if (m_selected->getId() == 'b')
		{
			printf("Selected Desert\n");
			m_background.changeBackground(BackgroundType::Desert);
		}
		else if (m_selected->getId() == 'c')
		{
			printf("Selected Water\n");
			m_background.changeBackground(BackgroundType::Water);
		}
		else if (m_selected->getId() == 'd')
		{
			printf("Selected Underground\n");
			m_background.changeBackground(BackgroundType::Inside);
		}
		else if (m_selected->getId() == 'e')
		{
			printf("Selected GhostHouse\n");
			m_background.changeBackground(BackgroundType::Inside);
		}
		else if (m_selected->getId() == 'f')
		{
			printf("Selected Castle\n");
			m_background.changeBackground(BackgroundType::Inside);
		}
		else if (m_selected->getId() == 'g')
		{
			printf("Selected Snow\n");
			m_background.changeBackground(BackgroundType::Snow);
		}
		else if (m_selected->getId() == 'h')
		{
			printf("Selected Airship\n");
			m_background.changeBackground(BackgroundType::Sky);
		}
		else if (m_selected->getId() == 'i')
		{
			printf("Selected Forest\n");
			m_background.changeBackground(BackgroundType::Forest);
		}
		else if (m_selected->getId() == 'j')
		{
			printf("Selected GroundNight\n");
			m_background.changeBackground(BackgroundType::Night);
		}
		else if (m_selected->getId() == 'k')
		{
			printf("Selected AirshipNight\n");
			m_background.changeBackground(BackgroundType::Night);
		}
		else if (m_selected->getId() == 'l')
		{
			printf("Selected WaterNight\n");
			m_background.changeBackground(BackgroundType::WaterNight);
		}
		else if (m_selected->getId() == 'm')
		{
			printf("Selected SnowNight\n");
			m_background.changeBackground(BackgroundType::SnowNight);
		}
		else if (m_selected->getId() == 'n')
		{
			printf("Selected GhostHouseNight\n");
			m_background.changeBackground(BackgroundType::GhostHouseNight);
		}
	}

}