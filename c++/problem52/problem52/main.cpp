#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

typedef unsigned long ulong;
typedef unsigned int uint;

void convertNumberToVector(ulong number, vector<uint>& pVector)
{
	ulong temp = number;
	while(number > 0)
	{
		temp = number % 10;
		pVector.push_back(temp);

		number = number / 10;
	}
}

bool vectorsMatch(const vector <uint>& pVectorOne, const vector<uint>& pVectorTwo)
{
	if (pVectorOne.size() != pVectorTwo.size())
	{
		return false;
	}

	for (size_t i = 0; i < pVectorOne.size(); ++i)
	{
		bool match = std::find(pVectorTwo.begin(), pVectorTwo.end(), pVectorOne.at(i)) != pVectorTwo.end();
		if (!match)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ulong number = 1;

	while (true)
	{
		vector<uint> numberVector;
		convertNumberToVector(number, numberVector);

		ulong doubleNumber = number * 2;
		vector<uint> doubleNumberVector;
		convertNumberToVector(doubleNumber, doubleNumberVector);

		if (!vectorsMatch(numberVector, doubleNumberVector))
		{
			++number;
			continue;
		}

		ulong threeTimes = number * 3;
		vector<uint> threeTimesVector;
		convertNumberToVector(threeTimes, threeTimesVector);
		if (!vectorsMatch(numberVector, threeTimesVector))
		{
			++number;
			continue;
		}

		ulong fourTimes = number * 4;
		vector<uint> fourTimesVector;
		convertNumberToVector(fourTimes, fourTimesVector);
		if (!vectorsMatch(numberVector, fourTimesVector))
		{
			++number;
			continue;
		}

		ulong fiveTimes = number * 5;
		vector<uint> fiveTimesVector;
		convertNumberToVector(fiveTimes, fiveTimesVector);
		if (!vectorsMatch(numberVector, fiveTimesVector))
		{
			++number;
			continue;
		}

		ulong sixTimes = number * 6;
		vector<uint> sixTimesVector;
		convertNumberToVector(sixTimes, sixTimesVector);
		if (!vectorsMatch(numberVector, sixTimesVector))
		{
			++number;
			continue;
		}

		cout << "Number: " << number << endl;
	}

	return EXIT_SUCCESS;
}