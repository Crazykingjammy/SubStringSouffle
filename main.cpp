

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
#include <time.h>

//Globals, because we are trying to keep this all in one single file, for now. 
 SubStringSouffle program; 

#define NUM_THREAD  4
SubString sub[NUM_THREAD];
SubString Fullwords, Commonwords, substrings; 
int listSize, chunksize;

std::vector<std::string> sources; 

int main(int argc, const char* argv[]) {

    std::cout << "Have " << argc << " arguments: ";
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << ", ";

		//Grabbing all but the first param
		if(i > 0)
			sources.push_back(argv[i]);
			
			
    }
	
	if(argc == 1)
	{
		/* code */
		std::cout << "\n\n";
		std::cout << "Enter program parameters: " << "\n\n";
		std::cout << "[body] : Test Argument " << '\n';
		std::cout << "[strstr] : Run the full list via STRSTR() " << '\n';
		std::cout << "[full] : Run the full list via static calls " << '\n';
		std::cout << "[thread] : Run full list in threads via static calls " << '\n';
		std::cout << "\n\n";

		return -1;
	}

	std::cout << '\n';
	
	std::clock_t progtime = std::clock();
	std::time_t timeStart, timeEnd;
	std::time(&timeStart);

	// ALways be curtious and say hello.
	std::cout << "Hello, Main!!\n";



for(auto && arg : sources)
{
	std::cout << "argument value of: " << arg << '\n';

	if(arg == "body")
		std::cout << "You detected an arugment" << "\n\n";

	if(arg == "strstr")
		{
			//Load the program and pass in the data files.
			program.Load("homework_data/commonwords.txt", "homework_data/allwords.txt");
			program.ProcessLists();
			break;
		}

	if(arg == "full")
	{
		Fullwords._substrCache = HippoUtility::File::LoadWordsFromFile("homework_data/allwords.txt");
		Commonwords._substrCache = HippoUtility::File::LoadWordsFromFile("homework_data/commonwords.txt");

		listSize = Fullwords._substrCache.size();
		chunksize = (listSize/ NUM_THREAD);


		substrings = SubStringSouffle::ProcessWordsWithCommon(Fullwords._substrCache, 
					Commonwords._substrCache, 0, listSize );

		HippoUtility::File::WriteToFile("output.txt",substrings._substrCache);

		HippoUtility::Console::Header("Program Complete");

		std::cout << "number of sub strings: " << substrings._substrCache.size() << '\n';
		break;

	}

	if(arg == "thread")
	{
		Fullwords._substrCache = HippoUtility::File::LoadWordsFromFile("homework_data/allwords.txt");
		Commonwords._substrCache = HippoUtility::File::LoadWordsFromFile("homework_data/commonwords.txt");

		listSize = Fullwords._substrCache.size();
		chunksize = (listSize/ NUM_THREAD);

				std::thread th0([]{

		sub[0] = SubStringSouffle::ProcessWordsWithCommon(Fullwords._substrCache, 
							Commonwords._substrCache, 0, chunksize );
		});

		std::thread th1([]{

		sub[1] = SubStringSouffle::ProcessWordsWithCommon(Fullwords._substrCache, 
							Commonwords._substrCache,chunksize, chunksize * 2 );
		});

		std::thread th2([]{

		sub[2] = SubStringSouffle::ProcessWordsWithCommon(Fullwords._substrCache, 
							Commonwords._substrCache,chunksize * 2, chunksize * 3 );
		});

		std::thread th3([]{

		sub[3] = SubStringSouffle::ProcessWordsWithCommon(Fullwords._substrCache, 
							Commonwords._substrCache,chunksize * 3, listSize );
		});

		th0.join();
		th1.join();
		th2.join();
		th3.join();

		//compile everything to the substrings.
		//Loop through all of the broken apart and link them together.
		for(int i = 0; i < NUM_THREAD; i++)
		{
			for(int j = 0; j < sub[i]._substrCache.size(); j++)
			{
				substrings._substrCache.push_back(sub[i]._substrCache[j]);
			}
		}

		HippoUtility::File::WriteToFile("outputx.txt",substrings._substrCache);

		HippoUtility::Console::Header("Program Complete");

		std::cout << "number of sub strings: " << substrings._substrCache.size() << '\n';

		std::time(&timeEnd);
		double diff = timeEnd - timeStart;
		std::cout << "ctime.h clock Seconds Reading: " << diff << '\n';

		double duration = (std::clock() - progtime) / (double)CLOCKS_PER_SEC;
		std::cout <<  "Threads total Time:" << " " << duration << "s " << '\n';   

		HippoUtility::Console::DisplayTimeElapsed(progtime, "Threads total time: ");
		break;

	} //end arg == thread

}









	//Finishing line.
	std::cout << "Program completed ! :Test \n";

}