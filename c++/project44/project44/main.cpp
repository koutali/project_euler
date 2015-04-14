#include "stdafx.h"

using namespace std;

unsigned int generatePentagonalNumber(unsigned int seed)
{
	return (seed*(6*seed - 1));
}

void generatePentagonalNumbers(vector<unsigned int> & pentagonalNumbers)
{
	cout << "Generating pentagonal numbers vector" << endl;

	for (unsigned int i = 0; i < 15000; ++i)
	{
		pentagonalNumbers.push_back(generatePentagonalNumber(i + 1));
	}
}

void generatePentagonalNumberDifferences(vector<unsigned int> & pentagonalNumbers, vector<unsigned int> &differences) 
{
	cout << "Generating differences vector" << endl;

	for (unsigned int i = 0; i < pentagonalNumbers.size(); ++i)
	{
		for (unsigned int j = i; j < pentagonalNumbers.size(); ++j)
		{
			//cout << "Comparing " << i << " with " << j << endl;

			if (i == j)
			{
				continue;
			}

			int sum = pentagonalNumbers.at(i) + pentagonalNumbers.at(j);
			int difference = pentagonalNumbers.at(i) - pentagonalNumbers.at(j);
			if (difference < 0)
			{
				difference *= -1;
			}

			if(std::find(pentagonalNumbers.begin(), pentagonalNumbers.end(), sum) != pentagonalNumbers.end() &&
				std::find(pentagonalNumbers.begin(), pentagonalNumbers.end(), difference) != pentagonalNumbers.end())
			{
				cout << "Found match!" << endl;
				differences.push_back(difference);
			}
		}
	}
}

void main()
{
	vector<unsigned int> pentagonalNumbers;
	generatePentagonalNumbers(pentagonalNumbers);

	vector<unsigned int> differences;
	generatePentagonalNumberDifferences(pentagonalNumbers, differences);

	if (differences.size() > 0)
	{	
		unsigned int min = *std::min_element(differences.begin(), differences.end());
		cout << "Minimum difference" << endl;
	}
	else
	{
		cout << "No element in pentagonal differences list. Increase range!" << endl;
	}
}