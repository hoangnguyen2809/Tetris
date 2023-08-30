#pragma once
#include "grid.h"
#include "blocks.h"

class Game
{
private:
	vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;

	void gameReset();
	void lockBlock();
public:
	Game();
	Block randomBlockGen();
	Grid grid;

	bool gameOver;
	void Draw();
	void handleInput();
	void moveBlockLeft();
	void moveBlockRight();
	void moveBlockDown();
	bool isBlockOutside();
	bool isBlockBottom();
	void blockFix();
	void RotateBlock();
	bool fit();
};