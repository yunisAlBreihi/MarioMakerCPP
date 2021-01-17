#pragma once
#include "Grid.h"

namespace editor 
{
	class IOHandler
	{
	private:
		inline static const char* m_fileName = "MarioLevel.txt";
		static const char m_empty = '#';
		static const char m_newLine = '\n';
	public:
		static void saveGrid(const universal::Grid& grid);
		static const universal::Grid& loadGrid();
	};
}
