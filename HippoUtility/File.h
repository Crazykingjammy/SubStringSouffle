#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


namespace HippoUtility
{

class File 
{
    public:

    //Loads a vector of words from a file.
    static std::vector<std::string> LoadWordsFromFile(std::string filename);
    
    //Write to file.
    static void WriteToFile(std::string filename, std::vector<std::string> list);

    private:

};


}