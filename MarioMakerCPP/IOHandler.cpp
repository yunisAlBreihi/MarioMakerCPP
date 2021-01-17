#include "IOHandler.h"
#include <iostream>
#include <fstream>
#include "globals.h"

namespace editor
{
	void IOHandler::saveGrid(const universal::Grid& grid)
	{
		std::ofstream t_myFile;
		t_myFile.open(m_fileName);

		const auto& t_sprites = grid.getSprites();

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

	const universal::Grid& IOHandler::loadGrid()
	{
		universal::Grid t_grid = universal::Grid(globals::EDITOR_RESOLUTION);

		//for (size_t i = 0; i < t_grid->; i++)
		//{

		//}
		return t_grid;
	}
}