#include "SaveHandler.h"
#include <iostream>
#include <fstream>

namespace editor
{
	void SaveHandler::saveGrid(const universal::Grid& grid)
	{
		std::ofstream t_myFile;
		t_myFile.open(m_fileName);

		const auto& t_sprites = grid.getSprites();
		//for (const auto& t_row : t_sprites) {
		//	for (const auto& t_sprite : t_row) {
		//		if (t_sprite != nullptr) {
		//			t_myFile << t_sprite->getId();
		//		}
		//		else {
		//			t_myFile << m_empty;
		//		}
		//	}
		//	t_myFile << m_newLine;
		//}

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