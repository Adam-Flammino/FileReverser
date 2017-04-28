// pc1.cpp : Defines the entry point for the console application.
// Adam Flammino 4/23 
// SDEV-340
// Reverses contents of a file using stack

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stack>


int main()
{
	// input/output objects
	std::ifstream inFile;
	std::ofstream outFile;

	std::string inputFileName;
	char ch;
	bool flag = false;
	bool flag2 = false;

	// reverses file contents
	std::stack<char> charStack;

	// Opens input file, warns user if file doesn't exist
	while (!flag) {
		std::cout << "Please enter the name of the input file:\t";
		std::cin >> inputFileName;
		inFile.open(inputFileName.data());
		if (inFile) {
			flag = true;
		}
		else {
			std::cout << std::endl << inputFileName << " not found! Please try again." << std::endl << 
				"(Hint: did you remember to include .txt?)" << std::endl;
		}
	}

	// Opens output file, creates it if it doesn't already exist, warns user if there is an issue
	while (!flag2) {
		outFile.open("reverse.txt");
		if (outFile) {
			flag2 = true;
		}
		else {
			std::cout << std::endl << "ERROR!" << std::endl << "Unable to open/create output file." << std::endl
				<< "Please ensure that you have write access to the program directory and try again!";
		}
	}

	// Reads input file, pushes characters from it onto stack
	ch = inFile.get();
	while (ch != EOF){
		charStack.push(ch);
		ch = inFile.get();
	}
	inFile.close();

	// Writes top char from stack to output file, prints it, pops it.
	while (!charStack.empty()) {
		ch = charStack.top();
		outFile << ch;
		std::cout << ch;
		charStack.pop();
	}
	outFile.close();

	std::cout << std::endl;

    return 0;
}

