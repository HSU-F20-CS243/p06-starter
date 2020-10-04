#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <regex> 
#include <sstream>

using namespace std;

class Preprocessor
{
private:
	const string LABEL = "\\(([a-zA-Z.$:_]+[\\da-zA-Z.$:_]*)\\)";
	const string A_CONST = "(@)([\\d]+)";
	const string A_SYMBL = "(@)([a-zA-Z.$:_]+[\\da-zA-Z.$:_]*)";
	const string C_COMP = "([DMA]*)=([!-DMA][-+\\|]*[DMA\\d]*)";
	const string C_JMP = "([DMA\\d]);([J][\\w]+)";
	vector<string> regular_expressions;
	string _file_to_process;

public:

	Preprocessor(string file_name)
		: _file_to_process(file_name)
	{
		regular_expressions = vector<string>{ LABEL, A_CONST, A_SYMBL, C_COMP, C_JMP };
	}

    string removeAllWhiteSpace(const string& text)
    {
        istringstream input{ text };
        ostringstream output{};
        while (input.good() == true)
        {
            string temp;
            input >> temp;
            output << temp;
        }
        return output.str();
    }

    string removeComments(const string& text)
    {
        string result{ text };
        int index = result.find("//");
        return result.substr(0, index);
    }

	vector<vector<string>> processFile()
	{
        vector<vector<string>> result{};
        ifstream to_process{_file_to_process};
        if (to_process.is_open() == true)
        {
            while (to_process.good() == true)
            {
                string line;
                getline(to_process, line);
                line = removeAllWhiteSpace(line);
                line = removeComments(line);
                for (int i = 0; i < regular_expressions.size(); i++)
                {
                    string& expression = regular_expressions[i];
                    smatch match;
                    regex pattern{ expression };
                    auto match_found = regex_match(line, match, pattern);
                    if (match_found == true)
                    {
                        vector<string> pieces{};
                        for (auto piece : match)
                        {
                            pieces.push_back(piece);
                        }
                        result.push_back(pieces);
                        break;
                    }
                }
            }
        }
        
        return result;
	}
};

