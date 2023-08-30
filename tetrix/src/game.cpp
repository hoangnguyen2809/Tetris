#include "game.h"
#include<random>

Game::Game()
{
	grid = Grid();
	blocks = { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
	currentBlock = randomBlockGen();
	nextBlock = randomBlockGen();
	gameOver = false;
	score = 0;
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
	if (gameOver && keyPressed != 0)
	{
		gameOver = false;
		gameReset();
	}
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
	case KEY_SPACE:
		moveBlockBottom();
		break;
	}
}

void Game::moveBlockLeft()
{
	if (!gameOver)
	{
		currentBlock.Move(0, -1);
		if (isBlockOutside() || fit() == false)
		{
			currentBlock.Move(0, 1);
		}
	}
}

void Game::moveBlockRight()
{
	if (!gameOver)
	{
		currentBlock.Move(0, 1);
		if (isBlockOutside() || fit() == false)
		{
			currentBlock.Move(0, -1);
		}
	}
	}
	

void Game::moveBlockDown()
{
	if (!gameOver)
	{
		currentBlock.Move(1, 0);
		if (isBlockOutside() || fit() == false)
		{
			currentBlock.Move(-1, 0);
			lockBlock();
		}
	}
}

void Game::moveBlockBottom()
{
	if (!gameOver)
	{
		while (!isBlockOutside() && fit() == true)
		{
			currentBlock.Move(1, 0);
		}
		if (isBlockOutside() || fit() == false)
		{
			currentBlock.Move(-1, 0);
			lockBlock();
		}
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
	if (!gameOver)
	{
		currentBlock.Rotate();
		if (isBlockOutside() && isBlockBottom() || fit() == false)
		{
			currentBlock.undoRotation();
		}
		else
			blockFix();
	}
}

bool Game::fit()
{
	vector<Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles)
	{
		if (grid.emptyCell(item.row, item.column) == false)
			return false;
	}
	return true;
}


void Game::gameReset()
{
	grid.gridInitialize();
	score = 0;
}

void Game::lockBlock()
{
	vector<Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles)
	{
		grid.cells[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if (fit() == false)
	{
		gameOver = true;
	}
	nextBlock = randomBlockGen();
	int rowsCleared = grid.clearFullRows();
	updateScore(rowsCleared, 0);

}

void Game::updateScore(int rowsCleared, int moveDownPoints)
{
	switch (rowsCleared)
	{
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	default: 
		break;
	}
	score += moveDownPoints;
}
