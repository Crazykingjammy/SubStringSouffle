//
//  main.cpp
//  SubStringHomework
//
//  Created by Kevaad Abdool on 8/22/19.
//  Copyright © 2019 Kevaad Abdool. All rights reserved.
//


#include "SubStringSouffle.h"

//bool compareFunction(std::string a, std::string b) { return a < b; } 



void SubStringSouffle::_checkSTR(char*big, char*small)
{

}
void SubStringSouffle::ProcessLists()
{

	char input;

	Header("Please Select a Traverse Option");

	//std::cout << "------ :Please Select a Traverse Option:  ------" << "\n\n";
	std::cout << "[N] - No Loop Traverse" << '\n';
	std::cout << "[E] - Empty Traverse" << '\n';
	std::cout << "[X] - Traverse via STRSTR" << '\n';
	std::cout << "[C] - Threaded Traverse" << '\n';
	std::cout << "[T] - Regular Traverse" << '\n';
	std::cin >> input;

	switch (input)
	{
	case 'T':
	case 't':
		_traverseLists();
		break;
	case 'E':
	case 'e':
		_emptyTraverse();
		break;
	case 'N':
	case 'n':
		_noLoopTraverse();
		break;
	case 'X':
	case 'x':
		_traverseSTR();
		break;
		case 'C':
	case 'c':
		_threadedSTR();
		break;

	default:
		std::cout << "\n\n" << "Invalid Command, continuing without any process functions() ---> " << "\n\n";
		break;
		
	}

	//Write resutls to file.
	_writeResultsToFile("substrings.txt");

	//Cal results print function.s
	_printResultData();

	//Calculate time since start.
	DisplayTimeElapsed(start, "Total Program Time:");

}





