#pragma once

#include <string>
#include <vector>

using namespace std;

class XMLParser {
private:
	string filename;
	string token;
	vector<string> tokens;
	vector<>;

	XMLParser(string file) {
		filename = file;
	}

	~XMLParser();

	void parse();
	Token getNextToken();

};