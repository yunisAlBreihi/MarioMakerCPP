#pragma once
#include "Grid.h"
#include "SpriteCreator.h"

namespace editor
{
	class IOHandler
	{
	private:
		inline static const char* m_fileName = "MarioLevel.txt";
		static const char m_empty = '#';
		static const char m_newLine = '\n';
	public:
		static void saveGrid(universal::Grid& gridToSaveTo, const char* filename);
		static void loadGrid(const editor::SpriteCreator& spriteCreator, universal::Grid& gridToLoadTo, const char* filename);
	};
}
