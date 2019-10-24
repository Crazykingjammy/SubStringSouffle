//
//  SubStringSetup.cpp
//  SubStringHomework
//
//  Created by Kevaad Abdool on 10/15/19.
//  Copyright © 2019 Kevaad Abdool. All rights reserved.
//
# include "SubStringSouffle.h"
#include "../HippoUtility/Console.h"

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

//Display chunk size.
chunksize = (int)(allwordsList.size() / threadcount);

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

std::string SubStringSouffle::TraverseType(int skip)
{
switch(skip)
{
	case 0:
		//Header("Begin Full Body Traverse");
		return "Full Body";
	break;
	case 1:
		//Header("Begin Empty Traverse");
		return "Single Loop";
	break;
	case 2:
		//Header("No Loop Traverse");
		return "No Loop";
	break;

	default:
	//Having some formatting fun.
	//Header("Default traverse.");
	return "N/A";
	break;
}
}

 SubString SubStringSouffle::ProcessWordsWithCommon(std::vector<std::string> AllWords, 
 std::vector<std::string> commonWords, int chunk_start, int chunk_finish)
	{
		//Local varaibles for cache
		std::string word;
		std::clock_t elapse = std::clock();

		//The return object.
		SubString substr;

		//Go through and loop through the full words list (by chunk)
		for(int i = chunk_start; i < chunk_finish; i++)
		{
			//Grab the current word in the iteration from the full list.
			word = AllWords[i];

			//Grab the result after we process all the common for that word.
			SubString result = ProcessCommon(word, commonWords);

			//Push back on our own return object.
			substr._substrCache.push_back(result.entries);
			substr.count += result.count;

			std::cout << "count: " << i << '\r';

			//Some display information?
			if (i == (int) (AllWords.size()/ 2) )
			{
				HippoUtility::Console::Log("Half way there... : ");
				HippoUtility::Console::DisplayTimeElapsed(elapse, "Time: ");
			}


		}


		//Return our data.
		return substr;

	}

 SubString SubStringSouffle::ProcessCommon(std::string word, std::vector<std::string> commonWords)
 {
	 //Local trackers.
	 char* big;
	 char* small;
	 char* p;

	 //Local Tools.
	//  std::vector<std::string> _SubStringCache;
	//  _SubStringCache.clear();
	 SubString substr;

	 //Set up our return data.
	 //substr.count = 0;  //This doenst need to be called but ill leave it here for refernece.

	//Start the entries with the word we are checking, followed by the semi-colon, 
	//and then the list of sub string words should follow
	 substr.entries = word + "; ";

	 //Set the main word we are checking against in all common words.
	 //Not sure why it needs to be grabbed like this.
	 big = (char*)word.data();

	//Loop through the common words list and check if they apply to the word being inputted.
	for(auto && cword : commonWords)
	{
		//Grab the common word and store it in the small char pointer.
		small = (char*)cword.data();

		//We should call a function for different types of compare.
		//will just implement strstr for now.

		p = std::strstr(big,small);
		
		//If we have some resutls
		if(p)
		{
			//Push back to the local list of sub strings.
			substr._substrCache.push_back(p);
			
			//keep track of the count.
			substr.count++;
		}

	} //End common words loop.

	//Perform the sort, and concat before we push back to the return vector.
	std::sort(substr._substrCache.begin(), substr._substrCache.end(), compareFunction );

	//Loop through and add all the sub strings to the entires.
	for(size_t i=0; i!=substr._substrCache.size(); i++)
	{
		//Add all entires to the single line for the right submission format.
		substr.entries += substr._substrCache[i] + ", ";
	}


	//Return our substring structure which should be filled up with its data now.
	return substr;



 }