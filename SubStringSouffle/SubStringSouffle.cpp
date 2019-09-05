//
//  main.cpp
//  SubStringHomework
//
//  Created by Kevaad Abdool on 8/22/19.
//  Copyright © 2019 Kevaad Abdool. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>    // std::sort
// #include <filesystem>
// #include <Windows.h>
#include <fstream>
#include <ctime>


bool compareFunction(std::string a, std::string b) { return a < b; }

// void displayPath()
// {

// 	//std::cout << "Current path is " << .current_path() << '\n';
//     //char * dir = getcwd(NULL, 0); // Platform-dependent, see reference link below
//     //printf("Current dir: %s \n", dir);
// 	char result[MAX_PATH];
// 	printf(result, GetModuleFileName(NULL, result, MAX_PATH));
// 	printf(" ----:: Path \n\n\n");

// }




int main(int argc, const char* argv[]) {

	//Timer variables at the very top.

	std::clock_t start, cache;
	double duration;
	start = std::clock();

	//Streams for the tewo text files.
	std::ifstream comonwords("../../../../homework_data/commonwords.txt");
	std::ifstream allWords("../../../../homework_data/allwords.txt");
	std::string str;
	std::string test;

	//Vectors to store all the words.
	std::vector<std::string> commonwordsList;
	std::vector<std::string> allwordsList;
	std::vector<std::string> SubStringList;

	// ALways be curtious and say hello.
	std::cout << "Hello, World!\n";
	//displayPath();

	//Just a check to see if the files are open.
	if (comonwords.is_open())
		std::cout << "File Found: commonwords.txt \n";
	else
		std::cout << "File Not Found! : commonwords.txt \n";

	if (allWords.is_open())
		std::cout << "File Found: allwords.txt \n";
	else
		std::cout << "File Not Found! : allwords.txt \n";


	//Counters to keep track of word counts for different lists.
	int commoncount = 0;
	int wordcount = 0;
	int SubStringcout = 0;

	//Set the cache time.
	cache = std::clock();

	//Grabbing the words and throwing them in vectors
	while (std::getline(comonwords, str))
	{
		// Process str
		//std::cout << str << '\n';
		commonwordsList.push_back(str);
		commoncount++;

	//	std::cout << "Comon Word Count: " << commoncount << '\r';
	}

	std::cout << "Comon Word Count: " << commoncount << '\n';
	
	duration = (std::clock() - cache) / (double)CLOCKS_PER_SEC;
	std::cout << "Calcualted Time: " << duration << '\n'; 

	//Set the cache time.
	cache = std::clock();

	//Grabbing the words and throwing them in vectors
	while (std::getline(allWords, str))
	{
		//Add to the vector.
		allwordsList.push_back(str);
		//Increment the word counter.
		wordcount++;

	//	std::cout << "Full Word Count: " << wordcount << '\r';
	}

	

	std::cout << "Full Word Count: " << wordcount << '\n';
	
	duration = (std::clock() - cache) / (double)CLOCKS_PER_SEC;
	std::cout << "Calcualted Time: " << duration << '\n';

	//Go through the list of All the Words....
	for (auto&& word : allwordsList)
	{
	
		//Nested loop to compare all the words from the AllWords.txt, with each word in CommonWords.txt
		for (auto&& cword : commonwordsList)
		{
			////Pasing in the common word, and finding it within the word selected from AllWords.txt.
			//std::size_t pos = word.find(cword);

			////Checking if we found somthing,
			//if (pos != std::string::npos)
			//{

			//	//Grabbing the string we found, adding it to its own vector.
			//	std::string sub = word.substr(pos);
			//	SubStringList.push_back(sub);

			//	// std::strstr(<#const char *__big#>, <#const char *__little#>)

			//	 //Keeping track of the word count.
			//	SubStringcout++;

			//}
		}


	}

	//Perform sorting.
	std::sort(SubStringList.begin(), SubStringList.end(), compareFunction);

	//Write the substrings into an output file.
	std::ofstream myfile;
	myfile.open("substrings.txt");

	//Go through and write every word in the SubStringList.
	for (auto&& word : SubStringList)
	{
		myfile << word << '\n';
	}

	myfile.close();


	//Output the stats. (our word count)
	std::cout << "Common Words Count:     " << commoncount << '\n';
	std::cout << "Total Words Count:      " << wordcount << '\n';
	std::cout << "SubString Count:      " << SubStringcout << '\n';

	//Outputting the vector stats.
	std::cout << "Common Vector ----->      " << commonwordsList.size() << '\n';
	std::cout << "Allwords Vector ----->      " << allwordsList.size() << '\n';
	std::cout << "Sub String Vector ----->      " << SubStringList.size() << '\n';


	//Finishing line.
	std::cout << "Program completed ! : SubString \n";





}





