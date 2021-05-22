#pragma once

#include<string>
#include<fstream>
#include<stdexcept>
#include"stack.h"
#include"list.h"

using namespace std;


class Node {
	
	

public:
	Node(string _key, string _val, Node* _next = nullptr, Node* _down = nullptr);
	string val;
	string key;
	bool isDown;
	Node* next;
	Node* down;

	void setValue(string _val);

	string getValue() const;
};

class Text {
	Node* root;
	Node* curr;
	Stack<Node*>* path;

	void print(ostream& ostr, Node* root, Node* curr, int level) const;
	void fileprint(ofstream& ofstr, Node* root, int level) const;
	void fileread(ifstream& ifstr, Node*& root, bool isNextLvl);
	void delBranch(Node* n);
public:
	Text();
	~Text();

	void addNext(string _key, string _val);
	void addDown(string _key, string _val);

	void delCurr();
	void delDown();

	string getKey();
	string getVal();
	
	bool empty() const;

	bool isNext() const;
	bool isDown() const;
	bool isTop() const;

	void next();
	void down();
	void top();

	friend ostream& operator<<(ostream& ostr, const Text& text);

	friend ofstream& operator<<(ofstream& ofstr, const Text& text);
	friend ifstream& operator>>(ifstream& ifstr, Text& text);
};