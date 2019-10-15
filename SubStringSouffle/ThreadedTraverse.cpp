//
//  TraverseFunctions.cpp
//  SubStringHomework
//
//  Created by Kevaad Abdool on 10/15/19.
//  Copyright © 2019 Kevaad Abdool. All rights reserved.
//

#include "SubStringSouffle.h"



void SubStringSouffle::_threadedSTR(int skip)
{
	//Set the cache time.
	cache = std::clock();

	//Note: So we can perform a sort here, in the the case of the all words list not being alphabetically ordered, and the output desire is to be alphabetically ordered.
	//Perform sorting.
	//std::sort(SubStringList.begin(), SubStringList.end(), compareFunction);

	Header("THREAD Traverse ||||||--:> " + TraverseType(skip));

	int _allwords_loop_counter_ = 0;
	char* big;
	char* small;
	char* p;



	//Go through the list of All the Words....
	#pragma omp parallel for schedule(static);
	for (auto&& word : allwordsList)
	{
		//Store our data in this function for faster access.
		//big = ( char*)word.data();

		//std::string entry = word + "; ";
		//local_SubStringPile.clear();

		//Nested loop to compare all the words from the AllWords.txt, with each word in CommonWords.txt
		//#pragma omp parallel for  num_threads(2)
		for (auto&& cword : commonwordsList)
		//#pragma omp task
		{
			//We will just continue to cache our data even though we access it only once.
			//small = (char*)cword.data();
			
			//call _checkSTR()
			
			//Start with the word.
			//p = std::strstr(big,small);

			// if(p)
			// {
			// 	//Store the word we found in a list to sort later.
			// 	local_SubStringPile.push_back(p);
			// 	 //Keeping track of the word count.
			// 	SubStringcout++;
			// }

		}

			//Perform the sort, and the concat before we push back.
			//std::sort(local_SubStringPile.begin(), local_SubStringPile.end(), compareFunction );

			//Perform the concat here.
			// for(size_t i=0; i!=local_SubStringPile.size(); i++)
			// {
			// 	//Got to find a way to do this with one line. More research needed to not get errors. (using VS code)
			// 	entry += local_SubStringPile[i];
			// 	entry += ", ";

			// }

				

			//Push back an entry of the all words, with all of the sub strings attached to them.
				// SubStringList.push_back(entry);


			//Information to display during operations.
			//Just a half way marker, dont want to go overboard since on UNIX (not windows) Ive manged to erase the line and display sount, so woot.
			if(_allwords_loop_counter_ == (int) (allwordsList.size()/ 2) )
			{
				DisplayTimeElapsed(cache, "Half way there... : ");
			}
			
			//Using a fancy for loop in order to still declear a counter so i can display. hehe.
			std::cout << "count : " << _allwords_loop_counter_  << '\r';
			_allwords_loop_counter_++;
	}


	//Print one last time as we exit the loop, with out the rollback.
	std::cout << "count : " << _allwords_loop_counter_  << '\n';

	DisplayTimeElapsed(cache, "STRSTR Traverse Total Time: ");
}