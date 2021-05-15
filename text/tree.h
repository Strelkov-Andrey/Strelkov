#pragma once

#include<string>
#include<iostream>
#include<fstream>
#include<stdexcept>
#include"stack.h"
#include"JSON.h"

using namespace std;

bool checkNum(string str);

enum type {
	INT, STR, BOOL
};

class IValue {
public:
	virtual type getType() const = 0;
};

class valString : public IValue {
	string val;
public:
	valString(string _val) : val(_val) {}
	type getType() const { return STR; }
	void setVal(string _val) {
		val = _val;
	}
	string getVal() const {
		return val;
	}
};

class Node {
	IValue* val;

public:
	Node(string _key, string _val, Node* _next = nullptr, Node* _down = nullptr);

	string key;
	bool isDown;
	Node* next;
	Node* down;

	void setValue(string _val);

	IValue* getValue() const;
};

class Text {
	Node* root;
	Node* curr;
	Stack<Node*>* path;

	void printCDN(ostream& ostr, Node* root, Node* curr, int level) const;
	void fprintCDN(ofstream& ofstr, Node* root, int level) const;
	void freadCDN(ifstream& ifstr, Node*& root, bool isNextLvl);
	void delBranch(Node* n);
public:
	Text();
	~Text();

	void addNext(string _key, string _val);
	void addDown(string _key, string _val);

	void delCurr();
	void delDown();

	void changeCurrKey(string str) const;
	void changeCurrValue(string _val) const;
	
	string getCurrKey() const;
	IValue* getCurrValue() const;

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