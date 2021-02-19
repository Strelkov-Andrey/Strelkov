#ifndef INCLUDE_ROMAN_H_
#define INCLUDE_ROMAN_H_

#include <iostream>
#include <string>

using namespace std;

class roman
{
public:
	string value;
	roman()
	{
		value = "";
	}
	roman(string s)
	{
		value = s;
	}
	bool operator==(const string& s) const
	{
		return (value == s);
	}
	friend istream& operator >>(istream& in, roman& r)
	{
		in >> r.value;
		return in;
	}
	friend ostream& operator <<(ostream& out, const roman& r)
	{
		out << r.value;
		return out;
	}
};

class arabic
{
public:
	int value;
	arabic() 
	{
		value = 0;
	}
	arabic(int n)
	{
		value = n;
	}
	bool operator==(const int& n) const
	{
		return (value == n);
	}
	friend istream& operator >>(istream& in, arabic& a)
	{
		in >> a.value;
		return in;
	}
	friend ostream& operator <<(ostream& out, const arabic& a)
	{
		out << a.value;
		return out;
	}
};



class Convertor {

	roman value_1;
	arabic value_2;
public:
	arabic toArabic(roman t);
	roman toRoman(arabic t);

	bool checkRoman(roman& t);        
	bool checkArabic(arabic& t);
	

};

#endif  // INCLUDE_ROMAN_H_