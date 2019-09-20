//
//  main.cpp
//  SubStringHomework
//
//  Created by Kevaad Abdool on 8/22/19.
//  Copyright © 2019 Kevaad Abdool. All rights reserved.
//


#include "SubStringSouffle.h"

//Globals, because we are trying to keep this all in one single file, for now. 

//Timer variables at the very top.
std::clock_t start, cache;

//Streams for the tewo text files.
std::ifstream comonwords("homework_data/commonwords.txt");
std::ifstream allWords("homework_data/allwords.txt");

//Cache string to hold values.
std::string str;

//Vectors to store all the words.
std::vector<std::string> commonwordsList;
std::vector<std::string> allwordsList;
std::vector<std::string> SubStringList;

//Counters to keep track of word counts for different lists.
int commoncount = 0;
int wordcount = 0;
int SubStringcout = 0;


void _validateStreamFiles()
{
	//Just a check to see if the files are open.
	if (comonwords.is_open())
		std::cout << "File Found: commonwords.txt \n";
	else
		std::cout << "File Not Found! : commonwords.txt \n";

	if (allWords.is_open())
		std::cout << "File Found: allwords.txt \n";
	else
		std::cout << "File Not Found! : allwords.txt \n";

}

void _writeResultsToFile(std::string filename)
{
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

void _printResultData()
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

void _fillVectorsFromFile()
{
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

	DisplayTimeElapsed(cache);
	std::cout << "Comon Word Count: " << commoncount << "\n\n\n";

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
	DisplayTimeElapsed(cache);
	std::cout << "Full Word Count: " << wordcount << "\n\n\n";
}

void _noLoopTraverse()
{
		//Set the cache time.
	cache = std::clock();

	Header("No Loop Traverse");
	int _allwords_loop_counter_ = 0;

	//Go through the list of All the Words....
	for (auto&& word : allwordsList)
	{
		// //Nested loop to compare all the words from the AllWords.txt, with each word in CommonWords.txt
		// for (auto&& cword : commonwordsList)
		// {
		// }

		// 	if(_allwords_loop_counter_ == (int) (allwordsList.size()/ 2) )
		// 	{
		// 		DisplayTimeElapsed(cache, "Half way there... : ");
		// 	}
			
		// 	std::cout << "count : " << _allwords_loop_counter_  << '\r';
			_allwords_loop_counter_++;
	}


	//Print one last time as we exit the loop, with out the rollback.
	std::cout << "count : " << _allwords_loop_counter_  << '\n';

	DisplayTimeElapsed(cache, "Full Word Traverse Total Time: ");
}

void _emptyTraverse()
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

void _traverseLists()
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

void ProcessLists()
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
}

int main(int argc, const char* argv[]) {

	// //Timer variables at the very top.
	start = std::clock();
	Header("Program Start!");
	
	// ALways be curtious and say hello.
	std::cout << "Hello, Sub String Homework!\r";
	displayPath();

	//Validate the files we need to load.
	_validateStreamFiles();

	//After files validated, fill up vector lists.
	_fillVectorsFromFile();


	ProcessLists();
	//Perform sorting.
	//std::sort(SubStringList.begin(), SubStringList.end(), compareFunction);

	//Write resutls to file.
	_writeResultsToFile("substrings.txt");

	//Cal results print function.s
	_printResultData();

	//Calculate time since start.
	DisplayTimeElapsed(start, "Total Program Time:");

	//Finishing line.
	std::cout << "Program completed ! : SubString \n";

}





