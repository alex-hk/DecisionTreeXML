#include <stdlib.h>
#include <stdio.h>
//#include "Node.h"
#include "XMLParser.h"

struct Tree {
private:
	Node* root;
	XMLParser parser;
public:
	Tree(XMLParser xmlp, Node* r) { parser = xmlp; root = r; }
	Node* buildTree(Node* root);
	void printTree(Node* root, int level);
	bool verifyToken(TokenType tok, TokenType token) { return tok == token; }
};
