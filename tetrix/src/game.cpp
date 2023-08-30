#include "game.h"
#include<random>

Game::Game()
{
	grid = Grid();
	blocks = { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
	currentBlock = randomBlockGen();
	nextBlock = randomBlockGen();
}

Block Game::randomBlockGen()
{
	int random = rand() % blocks.size();
	Block block = blocks[random];
	return block;
}

void Game::Draw()
{
	grid.gridDraw();
	currentBlock.blockDraw();
}
