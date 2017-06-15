// DecisionTree.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
//#include <unistd.h>
//#include "XMLParser.h"
//#include "Node.h"
#include "Tree.h"


int main()
{
	srand(time(NULL));
	string filename = "sample.xml";
	printf("Creating parser\n");
	//sleep(1);
	XMLParser parser(filename);
	printf("Created parser\n");
	printf("Parsing\n");
	//sleep(1);
	parser.parse();
	parser.printTokens();
	Node* root = new Node("", "", "");
	Tree dTree(parser, root);
	root = dTree.buildTree(root);
	printf("\n\n");
	dTree.printTree(root,0);


	string choice = "";
	printf("Event ('quit' to exit) : ");
	getline(cin, choice);
	while (choice != "quit") {
		string response = "";
		int rnum = (rand() % 100);
		if(rnum)
			response = dTree.bfSearch(root, choice);
		else
			response = dTree.dfSearch(root, choice);

		printf("Response = %s\n", response.c_str());

		printf("Event ('quit to exit) : ");
		getline(cin, choice);
	}
}
