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

	char input;

	Header("Please Select a Traverse Option");

	//std::cout << "------ :Please Select a Traverse Option:  ------" << "\n\n";
	std::cout << "[N] - Single Loop Traverse" << '\n';
	std::cout << "[E] - No Loop Traverse" << '\n';
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
		//_emptyTraverse();
		_traverseLists(2);
		break;
	case 'N':
	case 'n':
		//_noLoopTraverse();
		_traverseLists(1);
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
			break;

		//Start the loop with the word we are on, then add the seprator and a space for the substrings to follow.
		std::string entry = word + "; ";
		
		//Clear the local list at the start of every word int he full list.
		local_SubStringPile.clear();

		//Nested loop to compare all the words from the AllWords.txt, with each word in CommonWords.txt
		for (auto&& cword : commonwordsList)
		{
		//We do a check, if skip is 1, we break before we hit the fore loop.
		if(skip == 1)
			break;

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



