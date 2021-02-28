#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "IRender.h"
#include "IEventHandler.h"
#include "TileBase.h"
#include "Grid.h"
#include "SpriteCreator.h"
#include "Sprite.h"

namespace editor {
	class WindowBase : public universal::IEventHandler, public universal::IRender {
	protected:
		std::unique_ptr<sf::RenderWindow> m_window = nullptr;
		sf::Event m_event;

		std::unique_ptr<universal::TileBase> m_currentSelection = nullptr;
		std::unique_ptr<universal::Sprite> m_selected = nullptr;
		std::unique_ptr<universal::Grid> m_grid = nullptr;

	public:
		WindowBase(const SpriteCreator& spriteCreator,
				   const sf::Vector2i& resolution,
				   const sf::Vector2i& position,
				   const char* windowName);

		void eventHandler() override;
		void render(sf::RenderWindow& window) override;

		const bool selectTile(universal::TileBase* tile);
		const universal::TileBase& getCurrentSelection() const;
		const universal::Sprite& getSelected() const;

		virtual void onSelection() = 0;
	};
}