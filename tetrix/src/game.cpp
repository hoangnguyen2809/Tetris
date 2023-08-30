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

void Game::handleInput()
{
	int keyPressed = GetKeyPressed();
	switch (keyPressed)
	{
	case KEY_LEFT:
		moveBlockLeft();
		break;
	case KEY_RIGHT:
		moveBlockRight();
		break;
	case KEY_DOWN:
		moveBlockDown();
		break;
	case KEY_UP:
		RotateBlock();
		break;
	}
}

void Game::moveBlockLeft()
{
	currentBlock.Move(0, -1);
	if (isBlockOutside())
	{
		currentBlock.Move(0, 1);
	}
}

void Game::moveBlockRight()
{
	currentBlock.Move(0, 1);
	if (isBlockOutside())
	{
		currentBlock.Move(0, -1);
	}
}

void Game::moveBlockDown()
{
	currentBlock.Move(1, 0);
	if (isBlockOutside())
	{
		currentBlock.Move(-1, 0);
	}
}



bool Game::isBlockOutside()
{
	vector<Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles)
	{
		if (grid.cellBoundary(item.row, item.column))
		{
			return true;
		}
	}
	return false;
}

bool Game::isBlockBottom()
{
	vector<Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles)
	{
		if (grid.bottomLock(item.row))
		{
			return true;
		}
	}
	return false;
}

void Game::blockFix()
{
	vector<Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles)
	{
		if (grid.cellBoundary(item.row, item.column))
		{
			if (grid.overmoveRight(item.row, item.column))
			{
				currentBlock.Move(0, -1);
			}
			else
				currentBlock.Move(0, 1);
			
		}
	}

}



void Game::RotateBlock()
{
	currentBlock.Rotate();
	if (isBlockOutside() && isBlockBottom())
	{
		currentBlock.undoRotation();
	}
	else
		blockFix();
	
}

void Game::LockBlock()
{
	vector<Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles)
	{
		grid.cells[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	nextBlock = randomBlockGen();
}