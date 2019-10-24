#include "Console.h"

using namespace HippoUtility;

//Prints out a header, in format.
void Console::Header(std::string text)
{
    std::cout << "------ :" << text <<  ":  ------" << "\n\n";
}

//Standard log print.
void Console::Log(std::string message)
{
    std::cout << "Log Message: -[ " << message << " ]- " << "\n";
}

void Console::DisplayTimeElapsed(std::clock_t clock, std::string message)
{
    double duration = (std::clock() - clock) / (double)CLOCKS_PER_SEC;
		std::cout <<  message << " " << duration << "s " << '\n';   
}