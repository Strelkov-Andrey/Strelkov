#include"tree.h"
#include<Windows.h>
#include <conio.h>

int main()
{
	Text t;
	int op;
	while(true)
	{
		system("cls");
		cout << t;
		cout << "0. exit\n";
		cout << "1. left\n";
		cout << "2. right\n";
		cout << "3. top\n";
		cin >> op;
		
		try
		{
			switch (op) 
			{
			case 0: return 0; break;
			case 1: t.left(); break;
			case 2: t.right(); break;
			case 3: t.top(); break;
			}
		}
		catch (const char* err_s)
		{
			cout << err_s << endl;
			_getch();
		}

	}


	return 0;
}