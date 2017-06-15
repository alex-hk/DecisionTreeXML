#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"
#include <assert.h>
#include <queue>

Node* Tree::buildTree(Node* root) {
	Node* rnode = new Node();
	string xmlnode = "", behavior = "", response = "";
	Token tok = parser.getNextToken();
	assert(verifyToken(tok.getToken(), OARR_TOK));
	tok = parser.getNextToken();

	if (verifyToken(tok.getToken(),END_TOK)) {
		tok = parser.getNextToken();
		assert(verifyToken(tok.getToken(), NODE_TOK));
		tok = parser.getNextToken();
		assert(verifyToken(tok.getToken(), CARR_TOK));
		return NULL;
	} else if(verifyToken(tok.getToken(), NODE_TOK)){
		xmlnode = tok.getLexeme();
		rnode->setXmlNode(xmlnode);
		tok=parser.getNextToken();

		if(verifyToken(tok.getToken(), CARR_TOK))
		{
			behavior = xmlnode;
			rnode->setBehavior(behavior);
			Node* testNode;
			while (true) {
				testNode = buildTree(rnode);
				if (testNode == NULL){
					//return new Node(xmlnode, behavior, response);
					return rnode;
				}
				else
					rnode->addChild(testNode);
			}

		}else if(verifyToken(tok.getToken(), ATRB_TOK)){
			tok = parser.getNextToken();
			assert(verifyToken(tok.getToken(), EQ_TOK));
			tok = parser.getNextToken();
			assert(verifyToken(tok.getToken(), QT_TOK));
			tok = parser.getNextToken();
			if(verifyToken(tok.getToken(), TXT_TOK)){
				behavior = tok.getLexeme();
				rnode->setBehavior(behavior);
				tok = parser.getNextToken();
			}
			assert(verifyToken(tok.getToken(), EQT_TOK));

			tok = parser.getNextToken();
			assert(verifyToken(tok.getToken(), ATRB_TOK));
			tok = parser.getNextToken();
			assert(verifyToken(tok.getToken(), EQ_TOK));
			tok = parser.getNextToken();
			assert(verifyToken(tok.getToken(), QT_TOK));
			tok = parser.getNextToken();
			if(verifyToken(tok.getToken(), TXT_TOK)){
				response = tok.getLexeme();
				rnode->setResponse(response);
				tok = parser.getNextToken();
			}
			assert(verifyToken(tok.getToken(), EQT_TOK));
		}
	}
	
	tok = parser.getNextToken();
	if (tok.getToken() == END_TOK)
	{
		tok = parser.getNextToken();
		assert(verifyToken(tok.getToken(), CARR_TOK));
		return rnode;
		//return new Node(xmlnode, behavior, response);
	}
	else if (tok.getToken() == CARR_TOK) {
		Node* testNode;
		while (true) {
			testNode = buildTree(rnode);
			if (testNode == NULL)
				//return new Node(xmlnode, behavior, response);
				return rnode;
			else
				rnode->addChild(testNode);
		}
	}

	return buildTree(rnode);
}

string Tree::randResponse(Node * root){
	if(!root->isLeaf()){
		return root->getResponse();
	}
	else{
		int rsize = root->getChildrenSize();
		srand(time(NULL));

		int rnum = rand() % rsize;

		return randResponse(root->getChild(rnum));
	}
}

string Tree::bfSearch(Node* root, string choice){
	queue<Node *> nodequeue;
	nodequeue.push(root);

	Node * current;

	while(!nodequeue.empty()){
		current = nodequeue.front();
		nodequeue.pop();
		if(current->checkChoice(choice)){
			return randResponse(root);
		}
		for(int iter = 0; iter < current->getChildrenSize(); iter++){
			nodequeue.push(current->getChild(iter));
		}
	}
}

string Tree::dfSearch(Node* root, string choice){
	if(root->checkChoice(choice)){
		return randResponse(root);	
	}
	
	for(int iter = 0; iter < root->getChildrenSize(); iter++){
		dfSearch(root->getChild(iter), choice);
	}

}

/*
string randResponse(Node * root){
	if(!root->isLeaf()){
		return root->getResponse();
	}
	else{
		int rsize = root->getChildrenSize();
		srand(time(NULL));

		int rnum = rand() % rsize;

		randResponse(root->getChild(rnum));
	}
}
*/

void Tree::printTree(Node* root, int level) {
	if (root->getBehavior() != "") {
		for (int i = 0; i < level; i++)
			printf("\t");
		printf("%s\n", root->getBehavior().c_str());
	}
	if (root->getResponse() != "") {
		for (int i = 0; i < level; i++)
			printf("\t");
		printf("%s\n", root->getResponse().c_str());
	}
	if (root->isLeaf()) {
		Node* child;
		for (int i = 0; i < root->getChildrenSize(); i++) {
			printTree(root->getChild(i), level+1);
		}
	}
}


/*
 * TESTING
bool verifyNode(Token tok){
	assert(verifyToken(tok, OARR_TOK));
	if(verifyToken(tok=parser.getNextToken(), END_TOK)){
		assert(verifyToken(tok=parser.getNextToken(), NODE_TOK) && verify(tok=parser.getNextToken(), CARR_TOK));
	} else if(verifyToken(tok=parser.getNextToken(), ATRB_TOK)){
		return false;		
	} else {
		return false;
	}

}
*/
