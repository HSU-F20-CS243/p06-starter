#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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

int main(int argc, char* argv[])
{

#ifdef _DEBUG
	//makes debugging easier by allowing you to directly load in files w/o using command line
	Preprocessor prep{ "PongL.asm" };
#else

	if (argc != 4)
	{
		cout << "Usage: PROGRAM.EXE <ASM_FILE> <HACK_FILE>" << endl;
		return -1;
	}

	Preprocessor prep{ argv[2] };

	//TODO: use argv[3] to write to output file
	ofstream output{ argv[3] };

#endif // DEBUG

	//TODO: begin work here.
	vector<vector<string>> lines = prep.processFile();

	ofstream output_debug{ "output_debug.asm" };
	for (auto line : lines)
	{
		output_debug << line[1] << endl;
	}
	output_debug.close();
}