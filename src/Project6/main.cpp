#include <iostream>
#include <string>
#include <vector>
#include "Preprocessor.hpp"
#include "SymbolsTable.hpp"

using namespace std;

//Shows how you can use the symbols table to keep track of
//symbols inside an ASM file;
void symbols_table_example()
{
	SymbolsTable symbols{};

	//R1 already exists so we should get memory location 1...
	cout << "Location of R1: " << symbols["R1"] << endl;

	//To add a new symbol, just access it and the symbols table will
	//associate that symbol with the next avaialble slot in memory
	symbols["MyVariable"];
	
	//should be 16 since it's the first variable that we defined
	cout << "Location of MyVariable: " << symbols["MyVariable"] << endl;

	
	cout << endl;
}

//Shows how you can use the preprocessor to load a file 
//and get it ready for parsing.
void preprocessor_example()
{
	cout << "preprocessing example..." << endl;

	Preprocessor prep{ "Max.asm" };
	vector<vector<string>> lines = prep.processFile();

	//TODO: Run in DEBUG mode and examine the results of lines
	cout << "preprocessing complete" << endl;
}

int main(void)
{
	symbols_table_example();
	preprocessor_example();
}