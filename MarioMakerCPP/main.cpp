#include "EditorWorld.h"

int main()
{
	const sf::Vector2i m_RESOLUTION = sf::Vector2i(1280, 720);

	std::unique_ptr<editor::EditorWorld> m_editor = std::make_unique<editor::EditorWorld>(m_RESOLUTION,
																						  sf::Vector2i(200, 200), 
																				          "Mario Maker");

	while (m_editor->gameRunning() == true) {
		m_editor->eventHandler();
		m_editor->render();
	}

	return 0;
}