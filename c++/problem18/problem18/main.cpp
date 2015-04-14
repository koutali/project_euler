#include "stdafx.h"

int main()
{	

	std::fstream file("D:\\workspace\\project_euler\\problem18\\problem18\\input_data.txt", std::ios::in);
	if (!file)
	{
		std::cout << "File could not be opened!" << std::endl;
		return EXIT_FAILURE;
	}

	std::vector <std::vector<int>> numbersInTriangle;

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		int tempValue;
		if (!(iss >> tempValue)) 
		{ 
			break; 
		}
		else
		{
			std::regex delimiter(" ");
			std::sregex_token_iterator tokenIterator(line.begin(), line.end(), delimiter, -1);
			std::sregex_token_iterator end;

			std::vector<int> numbersInOneTriangleLine;
			int currentNumberOfEntries = 0;
			for(; tokenIterator != end; ++tokenIterator, ++currentNumberOfEntries)
			{
				std::istringstream buffer((*tokenIterator).str());
				int valueToAdd;
				buffer >> valueToAdd;

				numbersInOneTriangleLine.push_back(valueToAdd);
			}

			numbersInTriangle.push_back(numbersInOneTriangleLine);
		}
	}

	for (size_t i = numbersInTriangle.size() - 1; i > 0; --i)
	{
		std::vector<int>numbersInLine = numbersInTriangle.at(i);
		for (size_t j = 0; j < numbersInLine.size() - 1; ++j)
		{
			int first_number = numbersInLine.at(j);
			int second_number = numbersInLine.at(j + 1);

			int greater_number = (first_number > second_number) ? first_number : second_number;

			numbersInTriangle.at(i-1).at(j) += greater_number;
		}
	}

	std::cout << "Maximum sum: " << numbersInTriangle.at(0).at(0) << std::endl;
	return EXIT_SUCCESS;
}