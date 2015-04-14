// problem71.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Division.h"

std::string GetTime()
{
	SYSTEMTIME systime;
	GetLocalTime(&systime);

	std::ostringstream s;
	s << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
	
	std::string timeString(s.str());
	return timeString;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<cDivision> vect;
	const cDivision cD(3, 7);

	std::cout << "Started to create reciprocals at " << GetTime() << std::endl;

	const uint numeratorLimit = 1000000;
	const uint denominatorLimit = 1000000;
	try
	{
		for (size_t i = 1; i < numeratorLimit  ; i++)
		{
			for (size_t j = 1; j < denominatorLimit; j++)
			{
				cDivision d(i, j);
				//if (d <= cD)
				{
					std::vector<cDivision>::iterator it = std::find(vect.begin(), vect.end(), d);
					if (it == vect.end())
					{
						vect.push_back(d);
					}
				}
			}
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Done at " << GetTime() << std::endl;

	std::cout << "Sorting reciprocals..." << std::endl;
	std::sort(vect.begin(), vect.end());
	std::cout << "Done!" << std::endl;

	std::cout << "Searching for the key..." << std::endl;
	std::vector<cDivision>::iterator it = std::find(vect.begin(), vect.end(), cD);
	if (it != vect.end())
	{
		--it;
		std::cout << (*it).GetNumerator() << "/" << (*it).GetDenominator() << std::endl;
	}

	return 0;
}
