#include"tree.h"
#include <locale.h>

int main()
{
	Text t;
	int op;
	setlocale(LC_ALL, "Russian");
	ifstream inf("JSON.txt");
	inf >> t;
	cout << t << "\n";
	t.delDown();
	t.delCurr();
	t.addNext("aaaaa","wwwwww");
	t.next();
	t.addDown("jhgjh", "fdsfsf");
	
	cout << t;
	return 0;
}