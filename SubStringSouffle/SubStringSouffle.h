// SubStringSouffle.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iterator>
#include <algorithm>    // std::sort
#include <numeric>    // easy vector string accumilate.
#include <fstream>
#include <ctime>
#include <limits.h>
#include <unistd.h>

class SubStringSouffle
{
	public:

//public timers and cache. cos am empty pubilic is somthing i cant let appen right now.

	//Timer variables at the very top.
	std::clock_t start, cache;

	//Cache string to hold values.
	std::string str, commonWords_filename, allWords_filename;

private:

	//Vectors to store all the words.
	std::vector<std::string> commonwordsList;
	std::vector<std::string> allwordsList;
	std::vector<std::string> SubStringList;
	std::vector<std::string> local_SubStringPile;

	//Counters to keep track of word counts for different lists.
	int commoncount = 0;
	int wordcount = 0;
	int SubStringcout = 0;




	//Private functions.
	private:
	void _validateStreamFiles();
	void _writeResultsToFile(std::string filename);
	void _printResultData();
	void _noLoopTraverse();
	void _emptyTraverse();
	void _traverseLists();
	void _traverseSTR();


	//Public interface functions.
	public:
	
	void Load(std::string filename_CommonWords, std::string filename_AllWords);
	void ProcessLists();
	//bool compareFunction(std::string a, std::string b) { return a < b; }

protected:
	


	void DisplayTimeElapsed(std::clock_t clock, std::string message = "Calculated Time: ")
	{
		double duration = (std::clock() - clock) / (double)CLOCKS_PER_SEC;
		std::cout <<  message << " " << duration << "s " << '\n';
	}


	std::string getexepath()
	{
	char result[ PATH_MAX ];
	ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );

	return std::string( result, (count > 0) ? count : 0 );
	}

	void displayPath()
	{
		std::string path = getexepath();
		
		std::cout << path << '\n';
		printf(" ----:: Path \n\n\n");
	}

	void Header(std::string title)
	{
		std::cout << "------ :" << title <<  ":  ------" << "\n\n";
	}



} ;

// TODO: Reference additional headers your program requires here.

