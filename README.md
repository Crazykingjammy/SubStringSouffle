# SubStringSouffle
 The CMake Version of Sub String Homework task. 
 
 This is the homework assignment.

Given a large text file (allwords.txt) containing a single word on each line,for each value find and output all substrings matching words from a second text file in the same format (commonwords.txt). These files can be found in the attached zip file (homework_data.zip).

Output should be in the same order as the primary input file (allwords.txt), with the substring matches presented in alphabetical order, e.g.:

that: at, hat

Your solution to the assignment should be implemented in C/C++, but beyond this you are free to use whatever supplemental libraries and techniques you feel will best help you solve the problem. We will primarily be looking at how you approach a solution, so there is no definitive right or wrong answer, but you should consider structure, correctness, clarity, readability and performance.




### Project Notes


This program is also an exersise for me using the mac terminal to compile and run the program, while using visual studio Code to edit. (Yeah even though there are extentions to run c++ apps within vs code)

To compile on windows, I would need to make a few modifications. 
On UNIX the '/r' command words so i can display a word count and visualize progress, havent found successfull soulution as such for windows platform yet.

#### gcc compile arguments


g++ -std=c++17 -o prog substringsouffle/substringsouffle.cpp

My compile arguments from the main directly. I use the main.cpp as a test file for now.
main.cpp is kind of setup to run on its own if we wernt fools and just want to try compiling everything down to come terminal command. Otherwise I would have to compile substringsouffle.cpp + main.cp, and then link substringsouffle.o + main.o into prog.


 ./prog   (runs the program)
 
 
Not happy with the class breakdown in teh current submission. Got to break down the internal functions better.
But the program demonstrates a few different performances:

1. No loop 
 - (not performing a double loop, although you still traverse through the full allwords list)
2. Empty Loop 
 - (Performs the nested loop, but performs no operations beyond that)
3. Regular Compare
 - (Just a standard format for comparing the strings)
4. STRSTR compare
 - (Using the strstr function to get double performance form standard)
 
 
 The goal at this point is to clearn up the code better, I think the code is balloned beyond what it shold be for what this program does.
 
