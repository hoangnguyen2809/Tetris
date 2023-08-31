#include "blocks.h"

Position::Position(int row, int column)
{
	this->row = row;
	this->column = column;
}

Block::Block()
{
	id = 0;
	colorId = 0;
	rotationState = 0;
	rowOffset = 0;
	columnOffset = 0;
	colors = getCellColorsId();
}

void Block::blockDraw(int offSetX, int offsetY)
{
	vector<Position> currentPos = cells[rotationState];
	for (Position item : currentPos)
	{
		DrawRectangle((item.column+columnOffset)   * cellSize + offSetX, (item.row+rowOffset)  * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
	}
}

void Block::Move(int rows, int columns)
{
	rowOffset += rows;
	columnOffset += columns;
}

void Block::Rotate()
{
	rotationState++;
	if (rotationState == (int)cells.size())
	{
		rotationState = 0;
	}
}

void Block::undoRotation()
{
	rotationState--;
	if (rotationState == -1)
	{
		rotationState = cells.size() - 1;
	}
}

vector<Position> Block::getCellPositions()
{
	std::vector<Position> tiles = cells[rotationState];
	std::vector<Position> movedTiles;
	for (Position item : tiles)
	{
		Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
		movedTiles.push_back(newPos);
	}
	return movedTiles;
}


LBlock::LBlock()
{
	id = 1;
	colorId = 4;
	cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) };
	cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
	cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
	cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };
	Move(0, 3);
}

JBlock::JBlock()
{
	id = 2;
	colorId = 3;
	cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
	cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
	cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
	cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };
	Move(0, 3);
}

IBlock::IBlock()
{
	id = 3;
	colorId = 2;
	cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
	cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
	cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
	cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
	Move(-1, 3);
}

OBlock::OBlock()
{
	id = 4;
	colorId = 2;
	cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
	Move(0, 4);
}

SBlock::SBlock()
{
	id = 5;
	colorId = 3;
	cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
	cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
	cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
	cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };
	Move(0, 3);
}

TBlock::TBlock()
{
	id = 6;
	colorId = 2;
	cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
	cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
	cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
	cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };
	Move(0, 3);
}

ZBlock::ZBlock()
{
	id = 7;
	colorId = 4;
	cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
	cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
	cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
	cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };
	Move(0, 3);
}