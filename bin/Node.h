#include <string>
#include <vector>

using namespace std;

struct Node {
private:
	string xmlnode = "", behavior = "", response = "";
	vector<Node*> children;
public:
	Node(string node = "", string behav = "", string resp = "") {
		xmlnode = node;
		if (behav == "" && resp == "")
			behavior = xmlnode;
		else behavior = behav;
		response = resp;
	}
	bool isLeaf() { return !children.empty(); };
	void addChild(Node* child) { children.push_back(child); };
	Node* getChild(int child) {
		if(child <= children.size())
			return children[child];
		printf("Value is greater than size of vector\n");
		return NULL;
	}
	size_t	getChildrenSize() { return children.size(); }
	string	getXmlNode() { return xmlnode; }
	string	getBehavior() { return behavior; }
	string	getResponse() { return response; }
	void	setXmlNode(string xml) { xmlnode = xml; }
	void	setBehavior(string beh) { behavior = beh; }
	void	setResponse(string res) { response = res; }
	bool	checkChoice(string choice) { return (choice == behavior || choice == response || choice == xmlnode); }
};
