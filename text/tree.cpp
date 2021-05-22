#include"tree.h"

enum State { q0, q1, q2, q3, q4 };

Node::Node(string _key, string _val, Node* _next, Node* _down)
	: key(_key), val(_val), next(_next), down(_down), isDown(false) {}

void Node::setValue(string _val)
{
		val = _val;
}

string Node::getValue() const {
	return val;
}

void Text::print(ostream& ostr, Node* root, Node* curr, int level) const {
	if (root == nullptr) return;
	for (int i = 0; i < level; i++) {
		ostr << "   ";
	}
	if (root == curr) ostr << "*";
	ostr << root->key << " : ";
	if (!root->isDown)
	{
		ostr << "\"" << root->getValue() << "\"" << endl;
	}
	else {
		ostr << endl;
		print(ostr, root->down, curr, level + 1);
	}
	print(ostr, root->next, curr, level);
}

void Text::fileprint(ofstream& ofstr, Node* root, int level) const {
	if (root == nullptr) return;
	for (int i = 0; i < level; i++) {
		ofstr << '\t';
	}
	ofstr << "\"" << root->key << "\" : ";
	if (root->isDown) {
		ofstr << "{" << endl;
		fileprint(ofstr, root->down, level + 1);
		for (int i = 0; i < level; i++) {
			ofstr << '\t';
		}
		ofstr << "}";
	}
	else 
	{
			ofstr << "\"" << root->getValue() << "\"";
	}
	if (root->next != nullptr) {
		ofstr << " ," << endl;
	}
	else {
		ofstr << endl;
	}
	fileprint(ofstr, root->next, level);
}

void Text::fileread(ifstream& ifstr, Node*& root, bool isNextLvl) {
	if (ifstr.eof()) return;
	string str;
	State state;
	if (isNextLvl) state = q1;
	else state = q0;
	while (true) {
		ifstr >> str;
		if (state == q0) {
			if (str.length() > 1 && str[0] == '\"' && str[str.length() - 1] == '\"') {
				root = new Node(str.substr(1, str.length() - 2), string(""));
				state = q2;
			}
			else {
				throw logic_error("Invalid file format");
			}
		}
		else if (state == q1) {
			if (str.length() > 1 && str[0] == '\"' && str[str.length() - 1] == '\"') {
				root = new Node(str.substr(1, str.length() - 2), string(""));
				state = q2;
			}
			else if (str == "}") {
				return;
			}
			else {
				throw logic_error("Invalid file format");
			}
		}
		else if (state == q2) {
			if (str == ":") {
				state = q3;
			}
			else {
				throw logic_error("Invalid file format");
			}
		}
		else if (state == q3) {
			if (str.length() > 1 && str[0] == '\"' && str[str.length() - 1] == '\"') {
				root->setValue(str.substr(1, str.length() - 2));
				state = q4;
			}
			else if (str == "{") {
				root->isDown = true;
				fileread(ifstr, root->down, true);
				state = q4;
			}
			else if (str[str.length() - 1] != '\"')
			{
				string tmp;
				getline(ifstr, tmp);
				str += tmp;
				root->setValue(str.substr(1, str.length() - 2));
				if (str[str.size() - 1] == ',')
				{
					fileread(ifstr, root->next, false);
					return;
				}
				else
					state = q4;
			}
			else {
				throw logic_error("Invalid file format");
			}
		}
		else if (state == q4) {
			if (str == ",") {
				fileread(ifstr, root->next, false);
				return;
			}
			else if (str == "}") {
				return;
			}
			else {
				throw logic_error("Invalid file format");
			}
		}
	}
}

void Text::delBranch(Node* n) {
	if (n == nullptr) return;
	delBranch(n->next);
	delBranch(n->down);
	delete n;
}

Text::Text() {
	root = curr = nullptr;
	path = new Stack<Node*>;
};

Text::~Text() {
	while (root != nullptr) {
		delCurr();
	}
	delete path;
}

void Text::addNext(string _key, string _val) {
	if (root == nullptr) {
		root = curr = new Node(_key, _val);
		return;
	}
	Node* tmp = new Node(_key, _val, curr->next);
	curr->next = tmp;
}

void Text::addDown(string _key, string _val) {
	if (root == nullptr) {
		root = curr = new Node(_key, _val);
		return;
	}
	Node* tmp = new Node(_key, _val, curr->down);
	curr->isDown = true;
	curr->down = tmp;
}

void Text::delCurr() {
	if (curr == nullptr) return;
	delDown();
	Node* tmp = curr;
	if (!path->empty()) {
		top();
		if (curr->next == tmp) {
			curr->next = tmp->next;
		}
		else if (curr->down == tmp) {
			curr->down = tmp->next;
		}
	}
	else {
		root = curr = tmp->next;
	}
	delete tmp;
}

void Text::delDown()
{
	curr->isDown = false;
	if (curr == nullptr || curr->down == nullptr) return;
	delBranch(curr->down);
	curr->down = nullptr;
}

string Text::getKey()
{
	if (curr == nullptr) throw logic_error("Curr is null");
	return curr->key;
}

string Text::getVal()
{
	if (curr == nullptr) throw logic_error("Curr is null");
	return curr->val;
}

bool Text::empty() const
{
	return !root;
}

bool Text::isNext() const
{
	if (curr->next != nullptr) return true;
	return false;
}

bool Text::isDown() const
{
	if (curr->down != nullptr) return true;
	return false;
}

bool Text::isTop() const 
{
	if (curr == nullptr) return false;
	if (!path->empty()) return true;
	return false;
}

void Text::next() 
{
	if (!isNext()) throw logic_error("isNext == false");
	path->push(curr);
	curr = curr->next;
}

void Text::down() 
{
	if (!isDown()) throw logic_error("isDown == false");
	path->push(curr);
	curr = curr->down;
}

void Text::top()
{
	if (!isTop()) throw logic_error("isTop == false");
	curr = path->top();
	path->pop();
}

ostream& operator<<(ostream& ostr, const Text& text) 
{
	text.print(ostr, text.root, text.curr, 0);
	return ostr;
}

ofstream& operator<<(ofstream& ofstr, const Text& text)
{
	ofstr << "{" << endl;
	text.fileprint(ofstr, text.root, 1);
	ofstr << "}" << endl;
	return ofstr;
}

ifstream& operator>>(ifstream& ifstr, Text& text)
{
	if (!ifstr.eof())
	{
		while (text.root != nullptr)
		{
			text.delCurr();
		}
		string str;
		ifstr >> str;
		text.fileread(ifstr, text.root, true);
		text.curr = text.root;
	}
	return ifstr;
}