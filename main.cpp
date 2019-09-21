

//
//  main.cpp
//  SubStringHomework
//
//  Created by Kevaad Abdool on 8/22/19.
//  Copyright © 2019 Kevaad Abdool. All rights reserved.
//


#include "SubStringSouffle/SubStringSouffle.h"
#include <iostream>

//Globals, because we are trying to keep this all in one single file, for now. 
SubStringSouffle program; 


int main(int argc, const char* argv[]) {

	// ALways be curtious and say hello.
	std::cout << "Hello, Main!!\n";

	// //Load the program and pass in the data files.
	 program.Load("homework_data/commonwords.txt", "homework_data/allwords.txt");

	// //Process the list.
	 program.ProcessLists();
	
	
	//Finishing line.
	std::cout << "Program completed ! :Test \n";

}