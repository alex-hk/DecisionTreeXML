#include <string>
#include <vector>
#include <iostream>
#include <istream>
#include <fstream>
#include "Token.h"
#include "Node.h"
#include <queue>

using namespace std;

struct XMLParser {
private:
	string filename;
	queue<Token> tokens;
	//vector<Node> nodes;
	//vector<>;
public:
	XMLParser() { filename = "file.xml"; };

	XMLParser(string file) {
		filename = file;
	}

	//~XMLParser();

	/*	XML Parser
	 *	Reads each line of file
	 *	Reads each character in each line
	 *	Determines the token associated with each character/strings
	 *		EG: (	<: 		OARR_TOK
	 *			>: 		CARR_TOK
	 *			/: 		END_TOK
	 *			=: 		EQ_TOK
	 *			":		QT_TOK
	 *			"(after QT_TOK):EQT_TOK
	 *			Text: 		TXT_TOK
	 *			behavior/response(or any variable behind an EQ): ATRB_TOK
	 *	Builds a queue of Tokens to store in memory
	 */
	void parse();
	bool isWhiteSpace(char c) { return c == ' '; }
	Token getNextToken() { Token token = tokens.front(); tokens.pop(); return token; }
	Token peekFront() { return tokens.front(); }
	bool isValidToken(char c) { return c == '<' || c == '>' || c == '/' || c == '=' || c == '"' || isalnum(c); }
	//bool isChar(char c) { return (c - 'a' >= 0 && c - 'a' <= 25) || (c - 'A' >= 0 && c - 'A' <= 25); }
	int getString(string line, int pos) {
		int cursor = pos;
		while (cursor+1 < line.size() && isalnum(line[cursor+1])) {
			cursor++;
		}
		return cursor;
	}
	int skipWhiteSpace(string line, int pos) { while (line[pos] == ' ') pos++; return pos; }
	Token getToken(string lexeme);
	void addToken(Token token) { tokens.push(token); };
	void printTokens();
};
