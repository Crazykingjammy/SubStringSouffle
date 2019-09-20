// SubStringSouffle.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>    // std::sort
#include <fstream>
#include <ctime>
#include <limits.h>
#include <unistd.h>

// TODO: Reference additional headers your program requires here.
bool compareFunction(std::string a, std::string b) { return a < b; }

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