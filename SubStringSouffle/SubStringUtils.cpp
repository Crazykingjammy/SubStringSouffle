//
//  SubStringSetup.cpp
//  SubStringHomework
//
//  Created by Kevaad Abdool on 10/15/19.
//  Copyright © 2019 Kevaad Abdool. All rights reserved.
//
# include "SubStringSouffle.h"

bool SubStringSouffle::compareFunction(std::string a, std::string b) { return a < b; }

void SubStringSouffle::Load(std::string filename_CommonWords, std::string filename_AllWords)
{
	//Timer varable at the very top for the full program.
	start = std::clock();

	//Display header and try to be proper.
	Header("Program Start!");

	//Assign the file names.
	commonWords_filename = filename_CommonWords;
	allWords_filename = filename_AllWords;

	//display path we are in.
	// if it actually works.
	displayPath();

	//Validate the stream files taht we need. 
	_validateStreamFiles();

}

//Functions.

void SubStringSouffle::_validateStreamFiles()
{
	Header("Opening Files from Disk");

	//Streams for the tewo text files.
	// std::ifstream comonwords("homework_data/commonwords.txt");
	// std::ifstream allWords("homework_data/allwords.txt");
	std::ifstream comonwords(commonWords_filename);
	std::ifstream allWords(allWords_filename);

	//Just a check to see if the files are open.
	if (comonwords.is_open())
		std::cout << "File Found: " << commonWords_filename << '\n';
	else
		std::cout << "! File NOT Found: " << commonWords_filename << '\n';

	if (allWords.is_open())
		std::cout << "File Found: " << allWords_filename << '\n';
	else
		std::cout << "! File NOT Found: " << allWords_filename << '\n';

	std::cout << "\n\n";

	Header("Data dump into Vector");

		//Set the cache time.
	cache = std::clock();
	//Grabbing the words and throwing them in vectors
	while (std::getline(comonwords, str))
	{
		// Process str
		//std::cout << str << '\n';
		commonwordsList.push_back(str);
		commoncount++;
	}

	std::cout << "Comon Word Count: " << commoncount << "\n";
	DisplayTimeElapsed(cache);

	//Set the cache time.
	cache = std::clock();

	//Grabbing the words and throwing them in vectors
	while (std::getline(allWords, str))
	{
		//Add to the vector.
		allwordsList.push_back(str);
		//Increment the word counter.
		wordcount++;
	}

	//display function
	std::cout << "Full Word Count: " << wordcount << "\n";
	DisplayTimeElapsed(cache);

}



void SubStringSouffle::_writeResultsToFile(std::string filename)
{
	Header("Writing Results to file - substrings.txt ");

	//Write the substrings into an output file.
	std::ofstream myfile;
	myfile.open("substrings.txt");

	//Go through and write every word in the SubStringList.
	for (auto&& word : SubStringList)
	{
		myfile << word << '\n';
	}

	myfile.close();
}

void SubStringSouffle::_printResultData()
{

	//Clear out some space before we print our data.
	std::cout << "\n\n\n";
	
	//std::cout << "------ :Final Results Data:  ------" << "\n\n";
	Header("Final Results Data");

	//Output the stats. (our word count)
	//Outputting the vector stats.
	std::cout << "Common Words Count:     " << commoncount << '\n';
	std::cout << "Common Vector ----->      " << commonwordsList.size() << "\n\n";


	std::cout << "Total Words Count:      " << wordcount << '\n';
	std::cout << "Allwords Vector ----->      " << allwordsList.size() << "\n\n";



	std::cout << "SubString Count:      " << SubStringcout << '\n';
	std::cout << "Sub String Vector ----->      " << SubStringList.size() << "\n\n\n";

}
