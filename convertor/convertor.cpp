#include "convertor.h"

roman Convertor::toRoman(arabic t)
{
	if (checkArabic(t) == false)
		throw "number too large or number is negative";
	int countM, countD, countC, countL, countX, countV, countI;
	int tmp = t.value;
	countM = tmp / 1000;
	tmp %= 1000;
	countD = tmp / 500;
	tmp %= 500;
	countC = tmp / 100;
	tmp %= 100;
	countL = tmp / 50;
	tmp %= 50;
	countX = tmp / 10;
	tmp %= 10;
	countV = tmp / 5;
	tmp %= 5;
	countI = tmp;
	for (int i = 0; i < countM; i++)
	{
		value_1.value += "M";
	}
	if (countD == 1)
	{
		if (countC == 4)
		{
			value_1.value += "CM";
			countC = 0;
		}
		else
			value_1.value += "D";
	}
		if ((countC == 4) && (countD == 0))
		value_1.value += "CD";
	else
	{
		for (int i = 0; i < countC; i++)
			value_1.value += "C";
	}
	if (countL == 1)
	{
		if (countX == 4)
		{
			value_1.value += "XC";
			countX = 0;
		}
		else
			value_1.value += "L";
	}
	if ((countX == 4) && (countL == 0))
		value_1.value += "XL";
	else
	{
		for (int i = 0; i < countX; i++)
			value_1.value += "X";
	}
	if (countV == 1)
	{
		if (countI == 4)
		{
			value_1.value += "IX";
			countI = 0;
		}
		else
			value_1.value += "V";
	}
	if ((countI == 4) && (countV == 0))
		value_1.value += "IV";
	else
	{
		for (int i = 0; i < countI; i++)
			value_1.value += "I";
	}
	return value_1;
	}


arabic Convertor::toArabic(roman t)
{
	if (checkRoman(t)==false)
		throw logic_error("incorrect input");
	string tmp = t.value;
	int size = tmp.length();
	value_2.value = 0;
	for (int i = 0; i < size; i++)
	{
		if (tmp[i] == 'M')
			value_2.value += 1000;
		else if (tmp[i] == 'D')
			value_2.value += 500;
		else if (tmp[i] == 'C')
		{
			if ((tmp[i + 1] == 'M') && (i != size - 1))
			{
				value_2.value += 900;
				i++;
			}
			else if ((tmp[i + 1] == 'D') && (i != size - 1))
			{
				value_2.value += 400;
				i++;
			}
			else
				value_2.value += 100;
		}
		else if (tmp[i] == 'L')
			value_2.value += 50;
		else if (tmp[i] == 'X')
		{
			if ((tmp[i + 1] == 'C') && (i != size - 1))
			{
				value_2.value += 90;
				i++;
			}
			else if ((tmp[i + 1] == 'L') && (i != size - 1))
			{
				value_2.value += 40;
				i++;
			}
			else
				value_2.value += 10;
		}
		else if (tmp[i] == 'V')
		{
			value_2.value += 5;
		}
		else
		{
			if ((tmp[i + 1] == 'X') && (i != size - 1))
			{
				value_2.value += 9;
				i++;
			}
			else if ((tmp[i + 1] == 'V') && (i != size - 1))
			{
				value_2.value += 4;
				i++;
			}
			else
				value_2.value += 1;
		}
	}
		return value_2;
	
}

bool Convertor::checkRoman(roman& t)
{
	
	bool flag = true;
	string tmp = t.value;
	int size = tmp.length();
	for (int i = 0; i < size; i++)
	{
		if ((tmp[i] != 'M') && (tmp[i] != 'D') && (tmp[i] != 'C') && (tmp[i] != 'L') && (tmp[i] != 'X') && (tmp[i] != 'V') && (tmp[i] != 'I'))
			return false;
	}
	int countM = 0, countD = 0, countC = 0, countL = 0, countX = 0, countV = 0, countI = 0;
	for (int i = 0; i < size; i++)
	{
		switch(tmp[i])
		{
		case('M'):
			{
			if ((countD > 0) || (countC > 1) || (countL > 0) || (countX > 0) || (countV > 0) || (countI > 0))
			{
				flag = false;
				break;
			}
			else if (countC != 1)
				countM++;
			}
			break;
		case('D'):
			{
			if ((countC > 1) || (countL > 0) || (countX > 0) || (countV > 0) || (countI > 0))
			{
				flag = false;
				break;
			}
			else
				countD++;
			}
			break;
		case('C'):
			{
			if ((countL > 0) || (countX > 1) || (countV > 0) || (countI > 0))
			{
				flag = false;
				break;
			}
			else if (countX != 1)
				countC++;
			}
			break;
		case('L'):
		{
			if ((countX > 1) || (countV > 0) || (countI > 0))
			{
				flag = false;
				break;
			}
			else
				countL++;
		}
		break;
		case('X'):
		{
			if ((countV > 0) || (countI > 1))
			{
				flag = false;
				break;
			}
			else if (countI != 1)
				countX++;
		}
		break;
		case('V'):
		{
			if(countI>1)
			{
				flag = false;
				break;
			}
			else
				countV++;
		}
		break;
		case('I'):
		{
			countI++;
		}
		break;
		}
	}
	if ((countM > 3) || (countD > 1) || (countC > 3) || (countL > 1) || (countX > 3) || (countV > 1) || (countI > 3))
		flag = false;

	return flag;
}
bool Convertor::checkArabic(arabic& t)
{
	bool flag = true;
	if ((t.value >= 4000) || (t.value < 0))
		flag = false;
	return flag;
}