// problem59.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

char GetAscii(const int val)
{
	return ((val % 26) + 97);
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream file("cipher1.txt", std::ios::in);
	if (!file)
	{
		std::cout << "Failed to open file. Exiting application" << std::endl;
		return -1;
	}

	std::istream_iterator<int> start(file), end;
	std::vector<int> numbers(start, end);
	int first = 103;
	int second = 111;
	int third = 100;

	std::string result;

	for (size_t i = 0; i < numbers.size() - 3; i += 3)
	{
		char firstC = char(numbers.at(i) ^ first);
		result += firstC;

		char secondC = char(numbers.at(i + 1) ^ second);
		result +=  secondC;

		char thirdC = char(numbers.at(i + 2) ^ third);
		result += thirdC;
	}
	int sumOfChars = 0;
	for (size_t i = 0; i < result.size(); ++i)
	{
		sumOfChars += (int)result.at(i);
	}

	std::ofstream outfile("out.txt", std::ios::out);
	if (!outfile)
	{
		std::cout << "Could not create the output file. Will write to stdout" << std::endl;
		std::cout << result << std::endl;
		std::cout << "Sum of characters in the text: " << sumOfChars << std::endl;
	}
	else
	{
		std::cout << "Writing results to file..." << std::endl;
		outfile << result << std::endl;
		std::cout << "Sum of characters in the text: " << sumOfChars << std::endl;
		std::cout << "Done!" << std::endl;
		outfile.close();
	}

	return 0;
}
