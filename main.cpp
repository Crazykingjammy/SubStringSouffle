

//
//  main.cpp
//  SubStringHomework
//
//  Created by Kevaad Abdool on 8/22/19.
//  Copyright © 2019 Kevaad Abdool. All rights reserved.
//


#include "SubStringSouffle/SubStringSouffle.h"
#include "HippoUtility/File.h"
#include "HippoUtility/Console.h"

#include <iostream>

//Globals, because we are trying to keep this all in one single file, for now. 
 SubStringSouffle program; 

#define NUM_THREAD  4
SubString sub[NUM_THREAD];
SubString Fullwords, Commonwords, substrings; 


int main(int argc, const char* argv[]) {

    std::cout << "Have " << argc << " arguments: ";
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << ", ";
    }
	std::cout << '\n';

	// ALways be curtious and say hello.
	std::cout << "Hello, Main!!\n";


	Fullwords._substrCache = HippoUtility::File::LoadWordsFromFile("homework_data/allwords.txt");
	Commonwords._substrCache = HippoUtility::File::LoadWordsFromFile("homework_data/commonwords.txt");

	int listSize = Fullwords._substrCache.size();
	int chunksize = (listSize/ NUM_THREAD);

// substrings = SubStringSouffle::ProcessWordsWithCommon(Fullwords._substrCache, 
// 					Commonwords._substrCache, 0, 30000 );

std::thread th1([]{

sub[0] = SubStringSouffle::ProcessWordsWithCommon(Fullwords._substrCache, 
 					Commonwords._substrCache, 0, 60000 );
});

std::thread th2([]{

sub[1] = SubStringSouffle::ProcessWordsWithCommon(Fullwords._substrCache, 
 					Commonwords._substrCache,60000, 120000 );
});


th1.join();
th2.join();

//compile everything to the substrings.
//Loop through all of the broken apart and link them together.
for(int i = 0; i < NUM_THREAD; i++)
{
	for(int j = 0; j < sub[i]._substrCache.size(); j++)
	{
		substrings._substrCache.push_back(sub[i]._substrCache[j]);
	}
}

HippoUtility::File::WriteToFile("substrings__Test__.txt",substrings._substrCache);

HippoUtility::Console::Header("Program Complete");

std::cout << "number of sub strings: " << substrings._substrCache.size() << '\n';

	// //Load the program and pass in the data files.
	// program.Load("homework_data/commonwords.txt", "homework_data/allwords.txt");

// std::thread th1([]{

// program._LoopBig(0,1000);

// });

// std::thread th2([]{

// program._LoopBig(1000,2000);

// });
//  	 //program.ProcessLists();


// th1.join();
// th2.join();


// while(true)
// {
// 	// //Process the list.
// 	 program.ProcessLists();
	
// 	//After we process we ask the user for input.
// 	//Finishing line.
// 	std::cout << "List Processed, file written to SubStrings.txt \n\n\n\n";

// 	// ALways be curtious and say hello.
// 	std::cout << "Process list again? (y/n) \n\n";
// 	char input; 

// 	std::cin >> input; 
	
// 	if(input == 'n')
// 		break;	



// }
	
	//Finishing line.
	std::cout << "Program completed ! :Test \n";

}


// int main(int argc, char** argv) {
//     std::cout << "Have " << argc << " arguments:" << std::endl;
//     for (int i = 0; i < argc; ++i) {
//         std::cout << argv[i] << ", ";
//     }
// 		std::cout << "  [.]" << std::endl;
// }