#include "grid.h"
#include<iostream>

using namespace std;

Grid::Grid()
{
	numCols = 20;
	numRows = 10;
	cellSize = 30;
}

void Grid::gridInitialize()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			grid[row][column] = 0;
		}
	}
}

void Grid::Print()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			cout << grid[row][column] << " ";
		}
		cout << endl;
	}
}

void Grid::Draw()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			
		}
		
	}
}
