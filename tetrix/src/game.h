#pragma once
#include "grid.h"
#include "blocks.h"

class Game
{
private:
	vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
public:
	Game();
	Block randomBlockGen();
	Grid grid;

	void Draw();
};