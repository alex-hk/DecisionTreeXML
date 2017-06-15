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

	/*	Building Tree
	 *	Reads each token
	 *	Makes sure the structure is consistent
	 *		EG:(all </node> will have the tokens <, /, node, and >)
	 *	Return NULL node if </node> line
	 *	If line contains NODE_TOK, "node":
	 *		Attempts to find children recursively and adds it to
	 *		the parent node's children vector
	 *	Builds all nodes and node's children
	 *		
	 */
	Node* buildTree(Node* root);

	/*	Print Tree
	 *	Prints tree based on level
	 *	Similar to a file directory
	 */
	void printTree(Node* root, int level);
	bool verifyToken(TokenType tok, TokenType token) { return tok == token; }
	/*	Breadth First Search
	 *	Creates a Queue to hold breadth nodes
	 *	Pushes root node
	 *	Loop:
	 *	Makes node in front of queue current node
	 *	Checks if it's a compatible match
	 *		If true: Returns that node's response string
	 *			generated from randResponse
	 *		Else: Pushes current node's children to queue
	 */
	string bfSearch(Node * root, string choice);

	/*	Depth First Search
	 *	Problem: Trying to return from deeper nodes
	 *	Hacky fix:
	 *		If compatible match: return node's string
	 *			generated from randResponse
	 *		Else: response is empty string
	 *	Recursive search based on amount of children
	 *		Should return if response is not empty
	 */
	string dfSearch(Node * root, string choice);

	/*	Random Response
	 *	Generates random response from selected behavior
	 *	Return node's response if is a leaf
	 *	Gets a random number between 0 and (number of children x 100)
	 *		the number is then modded by number of children
	 *		(Although this seems counterintuitive, it seemed to
	 *		 balance each options chance somewhat)
	 *	Recursively calls randResponse with child chosen with rand
	 */
	string randResponse(Node * root);
};
