//
//  main.cpp
//  SubStringHomework
//
//  Created by Kevaad Abdool on 8/22/19.
//  Copyright © 2019 Kevaad Abdool. All rights reserved.
//


#include "SubStringSouffle.h"

//bool compareFunction(std::string a, std::string b) { return a < b; } 

void SubStringSouffle::ProcessLists()
{

	int input;

	Header("Please Select a Traverse Option");

	//std::cout << "------ :Please Select a Traverse Option:  ------" << "\n\n";
	std::cout << "[1] - Empty Loop Traverse" << '\n';
	std::cout << "[2] - Single Loop Traverse" << '\n';
	std::cout << "[3] - Full [Double] Loop Traverse" << '\n';
	std::cout << "[4] - Traverse via STRSTR" << '\n';
	std::cout << "[5] - Threaded Traverse" << '\n';
	std::cout << "[6] - Blank Traverse" << '\n';
	
	std::cin >> input;

	switch (input)
	{
	case 1:
		_traverseLists(2);
		break;
	case 2:
		_traverseLists(1);
		break;
	case 3:
		_traverseLists();
		break;
	case 4:
		_traverseSTR();
		break;
	case 5:
		//_thSTR(0);
		break;
	case 6: 
		_traverseLists(3);
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

void SubStringSouffle::_traverseLists(int skip)
{
	//Set the cache time.
	cache = std::clock();

	//Note: So we can perform a sort here, in the the case of the all words list not being alphabetically ordered, and the output desire is to be alphabetically ordered.
	//Perform sorting.
	//std::sort(SubStringList.begin(), SubStringList.end(), compareFunction);

	Header("Traverse ||||||--:> " + TraverseType(skip));

	//keeping track of the index anyway. i bet there is a way to grab that within the loop that i am unaware of. 
	int _allwords_loop_counter_ = 0;

	//We do a check, if skip is 2, we break before we hit the fore loop.
	if(skip == 3)
		return;

	//Go through the list of All the Words....
	for (auto&& word : allwordsList)
	{
		//We do a check, if skip is 2, we break before we hit the fore loop.
		if(skip == 2)
			continue;

		//Start the loop with the word we are on, then add the seprator and a space for the substrings to follow.
		std::string entry = word + "; ";
		
		//Clear the local list at the start of every word int he full list.
		local_SubStringPile.clear();

		//Nested loop to compare all the words from the AllWords.txt, with each word in CommonWords.txt
		for (auto&& cword : commonwordsList)
		{
		//We do a check, if skip is 1, we break before we hit the fore loop.
		if(skip == 1)
			continue;

			////Pasing in the common word, and finding it within the word selected from AllWords.txt.
			std::size_t pos = word.find(cword);
	
			//Checking if we found somthing,
			if (pos != std::string::npos)
			{

				//Grabbing the string we found, adding it to its own vector.
				//Store the word we found in a list to sort later.
				local_SubStringPile.push_back(word.substr(pos));

				 //Keeping track of the word count.
				SubStringcout++;

			}

		}

			//Perform the sort, and the concat before we push back.
			std::sort(local_SubStringPile.begin(), local_SubStringPile.end(), compareFunction );

			//Perform the concat here.
			for(size_t i=0; i!=local_SubStringPile.size(); i++)
			{
				//Got to find a way to do this with one line. More research needed to not get errors. (using VS code)
				entry += local_SubStringPile[i];
				entry += ", ";

			}


			//Push back the entry at with the concatnated substrings.
			SubStringList.push_back(entry);

			if(_allwords_loop_counter_ == (int) (allwordsList.size()/ 2) )
			{
				DisplayTimeElapsed(cache, "Half way there... : ");
			}
			
			//Fancy for loop to keep a counter. hm.
			std::cout << "count : " << _allwords_loop_counter_  << '\r';
			_allwords_loop_counter_++;
	}


	//Print one last time as we exit the loop, with out the rollback.
	std::cout << "count : " << _allwords_loop_counter_  << '\n';

	DisplayTimeElapsed(cache, "Full Word Traverse Total Time: ");
}



void SubStringSouffle::_LoopBig(int chunk_start, int chunk_finish)
{
	std::string word; 
	int _allwords_loop_counter_ = 0;
	//int start = chunk_start;

	for(int i = chunk_start; i < chunk_finish; i++ )
	{
		word = allwordsList[i];
		
		SubString result = _ProcessCommon(word);

		SubStringList.push_back(result.entries);
		SubStringcout += result.count;


		//Information to display during operations.
		//Just a half way marker, dont want to go overboard since on UNIX (not windows) Ive manged to erase the line and display sount, so woot.
		if(_allwords_loop_counter_ == (int) (allwordsList.size()/ 2) )
		{
			DisplayTimeElapsed(cache, "Half way there... : ");
		}
		
		//Using a fancy for loop in order to still declear a counter so i can display. hehe.
		std::cout << "count : " << _allwords_loop_counter_  << '\n';
		_allwords_loop_counter_++;


	
	}

}


SubString SubStringSouffle::_ProcessCommon(std::string word)
{

	//Local keeps.
	char* big;
	char* small;
	char* p;

	//Local tools.
	std::vector<std::string> _SubStringCache;
	_SubStringCache.clear();
	SubString subStr;



	//Store our data in this function for faster access.
	//To be deleted and accessed in struct directly.
	int wordCount = 0;
	std::string entry = word + "; ";


	//Set the main word we looking to grab.
	big = (char*)word.data();


	//Nested loop to compare all the words from the AllWords.txt, with each word in CommonWords.txt
	for (auto&& cword : commonwordsList)
		{

	//We will just continue to cache our data even though we access it only once.
				small = (char*)cword.data();
				
				
				//Start with the word.
				p = std::strstr(big,small);

				if(p)
				{
					//Store the word we found in a list to sort later.
					_SubStringCache.push_back(p);
					//Keeping track of the word count.
					subStr.count++;
				}


		}


	//Perform the sort, and the concat before we push back.
	std::sort(_SubStringCache.begin(), _SubStringCache.end(), compareFunction );

		//Perform the concat here.
		for(size_t i=0; i!=_SubStringCache.size(); i++)
		{
			//Got to find a way to do this with one line. More research needed to not get errors. (using VS code)
			entry += _SubStringCache[i];
			entry += ", ";

		}


	//Copy values for now, but eventually remove the middle man values and write to the struct directly.
	subStr.entries = entry;
	subStr._substrCache = _SubStringCache;

	return subStr;


}