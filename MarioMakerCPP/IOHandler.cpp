#include "IOHandler.h"
#include <iostream>
#include <fstream>
#include "globals.h"

namespace editor
{
	void IOHandler::saveGrid(universal::Grid& gridToSaveTo)
	{
		std::ofstream t_myFile;
		t_myFile.open(m_fileName);

		if (t_myFile.is_open() == true) {
			const auto& t_sprites = gridToSaveTo.getSprites();

			for (size_t x = 0; x < t_sprites.size(); ++x) {
				for (size_t y = 0; y < t_sprites[x].size(); ++y) {
					if (t_sprites[x][y] != nullptr) {
						t_myFile << t_sprites[x][y]->getId();
					}
					else {
						t_myFile << m_empty;
					}
				}
				t_myFile << m_newLine;
			}
		}
	}

	void IOHandler::loadGrid(const editor::SpriteCreator& spriteCreator, universal::Grid& grid)
	{
		universal::Grid t_grid = universal::Grid(globals::EDITOR_RESOLUTION);

		std::ifstream t_myFile;
		t_myFile.open(m_fileName);

		if (t_myFile.is_open() == true) {
			std::string t_line;

			auto& t_gridSprites = grid.getSprites();

			int lineIndex = 0;
			
			while (std::getline(t_myFile, t_line)) {
				for (size_t i = 0; i < t_line.size(); i++) {
					if (t_line[i] != '#') {
						universal::Sprite t_sprite = universal::Sprite(spriteCreator.getSpriteById(t_line[i]));
						grid.addSpriteAtPosition(t_sprite, sf::Vector2i(i * globals::TILE_SIZE, lineIndex * globals::TILE_SIZE));
					}
				}
				lineIndex++;
			}
		}
	}
}