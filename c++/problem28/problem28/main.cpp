#include "stdafx.h"

using namespace std;

typedef unsigned int uint;
typedef enum tDirection
{
	RIGHT,
	LEFT,
	UP,
	DOWN
}tDirection;

static tDirection currentDirection = RIGHT;

void goRight(uint &x, uint &y, vector<vector<uint>> & matrix)
{
	uint temp = y + 1;
	if (temp < matrix.size())
	{
		++y;

		temp = x + 1;
		if (matrix[temp][y] == 0)
		{
			currentDirection = DOWN;
		}
	}	
}

void goLeft(uint &x, uint &y, vector<vector<uint>> & matrix)
{
	uint temp = y - 1;
	if (temp >= 0)
	{
		--y;
		
		temp = x - 1;
		if (matrix[temp][y] == 0)
		{
			currentDirection = UP;
		}
	}
}

void goUp(uint &x, uint &y, vector<vector<uint>> & matrix)
{
	uint temp = x - 1;
	if (x >= 0)
	{
		--x;

		temp = y + 1;
		if (matrix[x][temp] == 0)
		{
			currentDirection = RIGHT;
		}
	}
	
}

void goDown(uint &x, uint &y, vector<vector<uint>> & matrix)
{
	uint temp = x + 1;
	if (temp < matrix.size())
	{
		++x;

		temp = y - 1;
		if (matrix[x][temp] == 0)
		{
			currentDirection = LEFT;
		}
	}
}


void getNextIndices(uint &x, uint &y, vector<vector<uint>> & matrix)
{
	switch(currentDirection)
	{
	case LEFT:
		goLeft(x,y, matrix);
		break;

	case RIGHT:
		goRight(x, y, matrix);
		break;

	case UP:
		goUp(x, y, matrix);
		break;

	case DOWN:
		goDown(x, y, matrix);
		break;

	default:
		break;
	}
}

bool isNumberEven(uint num)
{
	return num % 2 == 0;
}

uint getStartingPoint(int dimension)
{
	uint start = 0;
	
	if (isNumberEven(dimension))
	{
		start = dimension / 2;
	}
	else
	{
		start = (dimension - 1) / 2;
	}

	return start;
}

void fillMatrix(vector<vector<uint>> & matrix)
{
	uint matrixSize, x, y; 

	cout << "Filling the matrix" << endl;

	matrixSize = matrix.size();
	x = y = getStartingPoint(matrixSize);

	for (uint i = 0; i < matrixSize * matrixSize; ++i)
	{
		matrix[x][y] = i + 1;
		getNextIndices(x,y,matrix);
	}

}

void print(vector<vector<uint>> & matrix)
{
	cout << "Printing matrix" << endl;

	for (uint i = 0; i < matrix.size(); ++i)
	{
		for (uint j = 0; j < matrix.size(); ++j)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}
}

int getDiagonalsSum(vector<vector<uint>> & matrix)
{
	int sum = 0;
	uint j = 0;
	for (uint i = 0; i < matrix.size(); ++i, ++j)
	{
		sum += matrix[i][j];
	}

	j = 0;
	for (uint i = matrix.size() - 1; i >= 0 && j < matrix.size(); --i, ++j)
	{
		if(i != j)
		{
			sum += matrix[i][j];
		}
	}

	return sum;
}
void main()
{
	vector <vector<uint>> matrix(1001, vector<uint>(1001));
	fillMatrix(matrix);
	//print(matrix);

	cout << getDiagonalsSum(matrix) << endl;
}