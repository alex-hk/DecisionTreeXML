#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "XMLParser.h"
//#include "Token.h"

using namespace std;

/*
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
*/

void XMLParser::parse() {
	char buf;
	string line;
	//char* cline;
	ifstream file;
	file.open(filename);
	int cursor;
	int pos;
	string lexeme;
	while (getline(file, line)) {
		cursor = 0;
		buf = line[cursor];
		printf("%s\n", line.c_str());
		while (cursor < line.size()) {
			buf = line[cursor];
			printf("%c\n", buf);
			if (isWhiteSpace(buf)){
				cursor = skipWhiteSpace(line, cursor);
				buf = line[cursor];
			}
			if (isalnum(buf)) {
				pos = cursor;
				bool isQuote = false;
				if(line[pos-1] == '\"') isQuote = true;
				while (isalnum(buf) || isQuote) {
					pos++;
					buf = line[pos];
					if(line[pos] == '\"') isQuote = false;
				}
				lexeme = line.substr(cursor, pos-cursor);
				printf("Lexeme: %s\n", lexeme.c_str());
				addToken(getToken(lexeme));
				cursor = pos;
			}
			else if (isValidToken(buf)) {
				lexeme = line[cursor];
				addToken(getToken(lexeme));
				cursor++;
			}
			else{
				cursor++;
			}
		}
	}
}

Token XMLParser::getToken(string lexeme) {
	TokenType tok;
	char c = lexeme[0];
	if (isalnum(c)) {
		if (lexeme == "node" || tokens.back().getToken() == OARR_TOK || tokens.back().getToken() == END_TOK) tok = NODE_TOK;
		else if(tokens.back().getToken() == QT_TOK) tok = TXT_TOK;
		else tok = ATRB_TOK;
	}
	switch (c) {
		case '<': tok = OARR_TOK; break;
		case '>': tok = CARR_TOK; break;
		case '=': tok = EQ_TOK; break;
		case '/': tok = END_TOK; break;
		case '"':
			if (tokens.back().getToken() == QT_TOK || tokens.back().getToken() == TXT_TOK)
			{ tok = EQT_TOK; break; }
			else { tok = QT_TOK; break; }
	}
	return Token(tok, lexeme);
}

void XMLParser::printTokens() {
	printf("-----------------------START PRINT -----------------------\n\n");
	queue<Token> tokens2 = tokens;
	while(tokens2.size() > 0){
		Token tok = tokens2.front();
		tokens2.pop();
		printf("( ");
		tok.pToken();
		printf("%s",tok.getLexeme().c_str());
		printf(" )");
		if (tok.getToken() == CARR_TOK) printf("\n");
	}
}

