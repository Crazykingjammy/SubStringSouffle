#pragma once

#include <iostream>
#include <string>
namespace HippoUtility
{

class Console
{

//Functions
public:
static void Header(std::string text);
static void Log(std::string message);
static void DisplayTimeElapsed(std::clock_t clock, std::string message);

private:

//Disallow creating an instance of this object.
Console() {};

};



}