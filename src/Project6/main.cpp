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
	Preprocessor prep{ "sample4.asm" };
	ofstream output{ "sample4.hack" };
#else

	if (argc != 4)
	{
		cout << "Usage: <PROGRAM_NAME>.EXE <ASM_FILE> <HACK_FILE>" << endl;
		return -1;
	}

	Preprocessor prep{ argv[2] };

	//TODO: use argv[3] to write to output file
	ofstream output{ argv[3] };

#endif // DEBUG

	//TODO: begin work here.
	vector<vector<string>> lines = prep.processFile();
	SymbolsTable symbols{};
	int program_counter = 0;

	for (auto line : lines)
	{
		//Demo code typed in 3/10/2021 lecture.  May or may not be useful for
		//actual program.
		output << "[";
		for (auto item : line)
		{
			output << item << ",";
		}
		//A instruction with a variable (symbol)
		int instruction_type = stoi(line[0]);
		if (instruction_type == 0)
		{
			symbols[line[2]] = program_counter;
		}
		else if (instruction_type == 2)
		{
			int lookup_value = symbols[line[3]];
			output << lookup_value;
		}
		output << "]" << endl;
		program_counter++;
	}
	output.close();
}