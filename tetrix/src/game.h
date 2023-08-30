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
	void updateScore(int rowsCleared, int moveDown);
public:
	Game();
	Block randomBlockGen();
	Grid grid;
	int score;
	int level;

	bool gameOver;
	void Draw();
	void handleInput();
	void moveBlockLeft();
	void moveBlockRight();
	void moveBlockDown();
	void moveBlockBottom();
	
	bool isBlockOutside();
	bool isBlockBottom();
	void blockFix();
	void RotateBlock();
	bool fit();
};