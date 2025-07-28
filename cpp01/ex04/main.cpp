#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cerr << "MUST INCLUDE 3 ARGUMENTS, file, s1, and s2" << std::endl;
		return (1);
	}
	std::ifstream inputFile;
	size_t spos;
	size_t epos;
	inputFile.open(av[1], std::ios::in);
	if (!inputFile.is_open())
	{
		std::cerr << "file does not exist!!!" << std::endl;
	}
	else
	{
		inputFile.seekg(0, std::ios::end);
		std::streamsize size = inputFile.tellg();
		inputFile.seekg(0, std::ios::beg);
		char *buffer = new char[size];
		if (!buffer)
		{
			std::cerr << "malloc failed..." << std::endl;
			inputFile.close();
			return (1);
		}
		if (!inputFile.read(buffer, size))
		{
			std::cerr << "read Failed!" << std::endl;
			delete[] buffer;
			inputFile.close();
			return (1);
		}
		std::string fullFile(buffer, size);
		delete[] buffer;
		inputFile.close();
		std::string target(av[2]);
		std::string goal(av[3]);
		spos = fullFile.find(target);
		while (spos != std::string::npos)
		{
			epos = spos + target.length();
			fullFile = fullFile.substr(0, spos) + goal + fullFile.substr(epos, fullFile.length() - 1);
			spos = fullFile.find(target);
		}
		std::cout << fullFile << std::endl;
		std::ofstream outputFile;
		outputFile.open("result.txt", std::ios::out);
		if (!outputFile.is_open())
		{
			std::cerr << "Error opening file!" << std::endl;
			return (1);
		}
		outputFile << fullFile;
		outputFile.close();
	}
}