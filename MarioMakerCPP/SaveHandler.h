#pragma once
#include "Grid.h"

namespace editor 
{
	class SaveHandler
	{
	private:
		const char* m_fileName = "MarioLevel.txt";
		const char m_empty = '#';
		const char m_newLine = '\n';
	public:
		void saveGrid(const universal::Grid& grid);
	};
}
