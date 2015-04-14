#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include "boost/algorithm/string.hpp"

bool openFileAndReadContent(const std::string& pFileName, std::vector<std::string>& pFileContent)
{
	std::ifstream file(pFileName.c_str());
	if (!file)
	{
		std::cout << "File could not be opened!" << std::endl;
		return false;
	}

	std::string line;
	std::getline(file, line);

	boost::split(pFileContent, line, boost::is_any_of(","));
	return true;
}


template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
	return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::map<B,A> flip_map(const std::map<A,B> &src)
{
	std::map<B,A> dst;
	std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
		flip_pair<A,B>);
	return dst;
}

int main()
{
	std::vector<std::string> fileContent;
	bool fileContentRead = openFileAndReadContent("cipher1.txt", fileContent);
	if (!fileContentRead)
	{
		std::cout << "File content could not be read" << std::endl;
		return EXIT_FAILURE;
	}

	std::map<int, float> letters;
	std::vector<std::string>::iterator itFirst;
	for (itFirst = fileContent.begin(); itFirst != fileContent.end(); ++itFirst)
	{
		int numberOfOccurences = std::count(fileContent.begin(), fileContent.end(), (*itFirst));
		int encryptResult = atoi((*itFirst).c_str());
		float occurenceFrequency = (float) (numberOfOccurences) / (69.0f);
		letters.insert(std::pair<int, float>(encryptResult, occurenceFrequency));
	}

	std::map<float, int> sortedLetters = flip_map(letters);
	
	sortedLetters.clear();
	letters.clear();
	fileContent.clear();
	return EXIT_SUCCESS;
}