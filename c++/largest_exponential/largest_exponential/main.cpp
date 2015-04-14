#include <iostream>
#include <cmath>
#include <fstream>

int main()
{
	std::ifstream file("base_exp.txt", std::ios::in);

	if (!file)
	{
		std::cout << "File could not be opened!" << std::endl;
		return EXIT_FAILURE;
	}

	double limit = 3005315.8832111973;
	int currentLine = 1;

	while (!file.eof())
	{
		double currBase = 0;
		double currExp = 0;

		file >> currBase >> currExp;
		double log1 = std::log10(currBase) * currExp;
		
		if (std::abs(log1 - limit) == 0.0)
			break;

		++currentLine;
	}

	std::cout << "largest number is on line: " << currentLine << std::endl;
	return EXIT_SUCCESS;
}