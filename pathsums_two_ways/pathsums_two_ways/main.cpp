#include <iostream>
#include <fstream>
#include <iomanip>

const int MATRIX_SIZE = 80;

void createMatrix(int** p_matrix)
{
	std::ifstream file("matrix.txt", std::ios::in);
	if (!file)
	{
		std::cout << "File could not be opened!" << std::endl;
		return;
	}

	int yDimension = 0;
	while(!file.eof())
	{
		int xDimension = 0;
		int number;
		while(xDimension < MATRIX_SIZE)
		{			
			file >> number;

			if (xDimension < MATRIX_SIZE && yDimension < MATRIX_SIZE)
			{
				p_matrix[yDimension][xDimension] = number;
			}

			++xDimension;
		}

		++yDimension;
	}
}

void cleanupMatrix(int** p_matrix)
{
	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		delete p_matrix[i];
		p_matrix[i] = nullptr;
	}

	delete p_matrix;
	p_matrix = nullptr;
}

void printMatrix(int** p_matrix)
{
	std::ofstream file("out.txt", std::ios::out);

	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < MATRIX_SIZE; ++j)
		{			
			file << std::setw(6) << p_matrix[i][j] << " ";
		}
		file << std::endl;
	}
}

void preprocess(int** p_matrix)
{
	for (int i = MATRIX_SIZE - 2; i >= 0; i--) 
	{
		p_matrix[MATRIX_SIZE - 1] [i] += p_matrix[MATRIX_SIZE - 1] [i+1];
		p_matrix[i][MATRIX_SIZE - 1]  += p_matrix[i+1][MATRIX_SIZE - 1];
	}
}

int getSum(int** p_matrix)
{
	for (int i = MATRIX_SIZE - 2; i >= 0; i--)
	{
		for (int j = MATRIX_SIZE - 2; j >= 0; j--) 
		{
			if (p_matrix[i + 1][j] < p_matrix[i] [j + 1])
			{
				p_matrix[i][j] += p_matrix[i + 1][j];
			}
			else
			{
				p_matrix[i][j] += p_matrix[i] [j + 1];

			}
		}
	}

	return p_matrix[0][0];
}

int main()
{
	int ** matrix = new int* [MATRIX_SIZE];
	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		matrix[i] = new int [MATRIX_SIZE];
	}

	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < MATRIX_SIZE; ++j)
		{
			matrix[i][j] = 0;
		}
	}

	createMatrix(matrix);
	//printMatrix(matrix);
	preprocess(matrix);

	std::cout <<"Minimum sum: " << getSum(matrix) << std::endl;

	cleanupMatrix(matrix);

	return EXIT_SUCCESS;
}