// keylogs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void SplitNumberAndAppendToList(int number, std::vector<int>& list)
{
	int divisor = 100;
	while (divisor > 0)
	{
		int remainder = number / divisor;
		number = number % divisor;
		divisor = divisor / 10;

		std::vector<int>::iterator it = std::find(list.begin(), list.end(), remainder);
		if (it == list.end())
		{
			list.push_back(remainder);
		}
	}
}

bool ReadFileIntoList(std::vector<int>& fileContent)
{
	std::ifstream file("keylog.txt", std::ios::in);

	if (!file)
	{
		return false;
	}

	while (!file.eof())
	{
		int keys = 0;
		file >> keys;
		fileContent.push_back(keys);
	}

	file.close();
	return true;
}

void OrderMembers(std::vector<int>& fileContents, std::vector<int>& orderedList)
{
	for (std::vector<int>::iterator it = fileContents.begin(); it != fileContents.end(); ++it)
	{
		int firstDigit = (*it) / 100;
		int secondDigit = ((*it) % 100) / 10;
		int thirdDigit = (*it) % 10;

		size_t indexOfFirstDigit = std::find(orderedList.begin(), orderedList.end(), firstDigit) - orderedList.begin();
		size_t indexOfSecondDigit = std::find(orderedList.begin(), orderedList.end(), secondDigit) - orderedList.begin();
		size_t indexOfThirdDigit = std::find(orderedList.begin(), orderedList.end(), thirdDigit) - orderedList.begin();

		if (indexOfSecondDigit < indexOfFirstDigit)
		{
			std::swap(orderedList.at(indexOfSecondDigit), orderedList.at(indexOfFirstDigit));
		}

		if (indexOfThirdDigit < indexOfSecondDigit)
		{
			std::swap(orderedList.at(indexOfThirdDigit), orderedList.at(indexOfSecondDigit));
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<int> fileContent;
	bool operationResult = ReadFileIntoList(fileContent);
	if (!operationResult)
	{
		std::cout << "Failed to open file" << std::endl;
		return -1;
	}

	std::vector<int> orderedList;
	for (std::vector<int>::iterator it = fileContent.begin(); it != fileContent.end(); ++it)
	{
		SplitNumberAndAppendToList((*it), orderedList);
	}

	OrderMembers(fileContent, orderedList);

	return 0;
}

