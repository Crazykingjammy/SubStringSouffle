//
//  main.cpp
//  SubStringHomework
//
//  Created by Kevaad Abdool on 8/22/19.
//  Copyright © 2019 Kevaad Abdool. All rights reserved.
//


#include "SubStringSouffle.h"

//Globals, because we are trying to keep this all in one single file, for now. 
SubStringSouffle program; 


int main(int argc, const char* argv[]) {

	// ALways be curtious and say hello.
	std::cout << "Hello, Sub String Homework!\n";
	std::cout << "Input Data: " << argc << " argv check: " << &argv <<  "\n\n\n";

	//Load the program and pass in the data files.
	program.Load("homework_data/commonwords.txt", "homework_data/allwords.txt");

	//Process the list.
	program.ProcessLists();
	
	
	//Finishing line.
	std::cout << "Program completed ! : SubString \n";

}

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



void SubStringSouffle::_noLoopTraverse()
{
		//Set the cache time.
	cache = std::clock();

	Header("No Loop Traverse");
	int _allwords_loop_counter_ = 0;

	//Go through the list of All the Words....
	for (auto&& word : allwordsList)
	{
			
		// 	std::cout << "count : " << _allwords_loop_counter_  << '\r';
			_allwords_loop_counter_++;
	}


	//Print one last time as we exit the loop, with out the rollback.
	std::cout << "count : " << _allwords_loop_counter_  << '\n';

	DisplayTimeElapsed(cache, "Full Word Traverse Total Time: ");
}

void SubStringSouffle::_emptyTraverse()
{
	//Set the cache time.
	cache = std::clock();

	Header("Begin Empty Traverse");
	int _allwords_loop_counter_ = 0;

	//Go through the list of All the Words....
	for (auto&& word : allwordsList)
	{
		//Nested loop to compare all the words from the AllWords.txt, with each word in CommonWords.txt
		for (auto&& cword : commonwordsList)
		{
		}

			if(_allwords_loop_counter_ == (int) (allwordsList.size()/ 2) )
			{
				DisplayTimeElapsed(cache, "Half way there... : ");
			}
			
			std::cout << "count : " << _allwords_loop_counter_  << '\r';
			_allwords_loop_counter_++;
	}


	//Print one last time as we exit the loop, with out the rollback.
	std::cout << "count : " << _allwords_loop_counter_  << '\n';

	DisplayTimeElapsed(cache, "Full Word Traverse Total Time: ");
}

void SubStringSouffle::_traverseLists()
{
	//Set the cache time.
	cache = std::clock();

	//std::cout << "Begin Full Body Traverse ... " << '\n';
	Header("Begin Full Body Traverse");
	int _allwords_loop_counter_ = 0;

	//Go through the list of All the Words....
	for (auto&& word : allwordsList)
	{
		//Nested loop to compare all the words from the AllWords.txt, with each word in CommonWords.txt
		for (auto&& cword : commonwordsList)
		{
			////Pasing in the common word, and finding it within the word selected from AllWords.txt.
			std::size_t pos = word.find(cword);
	
			//Checking if we found somthing,
			if (pos != std::string::npos)
			{

				//Grabbing the string we found, adding it to its own vector.
				std::string sub = word.substr(pos);
				SubStringList.push_back(sub);

				// std::strstr(<#const char *__big#>, <#const char *__little#>)

				 //Keeping track of the word count.
				SubStringcout++;

			}

		}


			if(_allwords_loop_counter_ == (int) (allwordsList.size()/ 2) )
			{
				DisplayTimeElapsed(cache, "Half way there... : ");
			}
			
			std::cout << "count : " << _allwords_loop_counter_  << '\r';
			_allwords_loop_counter_++;
	}


	//Print one last time as we exit the loop, with out the rollback.
	std::cout << "count : " << _allwords_loop_counter_  << '\n';

	DisplayTimeElapsed(cache, "Full Word Traverse Total Time: ");
}

void SubStringSouffle::ProcessLists()
{

	char input;

	Header("Please Select a Traverse Option");

	//std::cout << "------ :Please Select a Traverse Option:  ------" << "\n\n";
	std::cout << "[T] - Regular Traverse" << '\n';
	std::cout << "[E] - Empty Traverse" << '\n';
	std::cout << "[N] - No Loop Traverse" << '\n';
	std::cin >> input;

	switch (input)
	{
	case 'T':
		_traverseLists();
		break;
	case 'E':
		_emptyTraverse();
		break;
	case 'N':
		_noLoopTraverse();
		break;
	
	default:
		std::cout << "\n\n" << "Invalid Command, continuing without any process functions() ---> " << "\n\n";
		break;
		
	}

	//Perform sorting.
	//std::sort(SubStringList.begin(), SubStringList.end(), compareFunction);

	//Write resutls to file.
	_writeResultsToFile("substrings.txt");

	//Cal results print function.s
	_printResultData();

	//Calculate time since start.
	DisplayTimeElapsed(start, "Total Program Time:");

}





