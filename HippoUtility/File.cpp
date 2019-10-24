#include "File.h"
#include "Console.h"

using namespace HippoUtility; 

void File::WriteToFile(std::string filename, std::vector<std::string> list)
{
    //Start with a tidy header.
   Console::Header("Writing Results to file -" + filename);

   //The output file.
   std::ofstream file;
   file.open(filename);

    //Go through and output every string in the list.
    for(auto&& word: list)
        file << word << '\n';

    //Close the file when we are done.
    file.close();
}
std::vector<std::string>File::LoadWordsFromFile(std::string filename)
{
    Console::Header("Opening files from the disk");

    //Create the vector to return here
    //Do we need to call new? yes right?
    std::vector<std::string> list; 

    //Create some cache values.
    std::string str;

    //Create a file stream
    std::ifstream loadedwords(filename);

    //Do some checks see if the file is opened/and can be found.
    if(loadedwords.is_open())
        Console::Log(filename + ": loaded");
        else
        {
            Console::Log("File not found: " + filename);
        }
        
    //Grab the words and throw them in the vector.
    while(std::getline(loadedwords, str) )
    {
        //add to the vector.
        list.push_back(str);
    }

    //return the vector.
    return list;

}