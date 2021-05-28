#include<iostream>

using namespace std;

const int n = 10;
int arr[n][n];

bool checkleft(int a1, int a2)
{
	if (a1 <= 0)
		return false;
	return(arr[a1 - 1][a2] == 1);
}

bool checkright(int a1, int a2)
{
	if (a1 >= 4)
		return false;
	return(arr[a1 + 1][a2] == 1);
}

bool checkdown(int a1, int a2)
{
	if (a2 >= 4)
		return false;
	return(arr[a1][a2 + 1] == 1);
}

bool checkup(int a1, int a2)
{
	if (a2 <= 0)
		return false;
	return(arr[a1][a2 - 1] == 1);
}

void del_island(int a1, int a2)
{
	arr[a1][a2] = 0;
	
	if (checkdown(a1, a2))
		del_island(a1, a2 + 1);
	if (checkup(a1, a2))
		del_island(a1, a2 - 1);
	if (checkleft(a1, a2))
		del_island(a1 - 1, a2);
	if (checkright(a1, a2))
		del_island(a1 + 1, a2);
}

int main()
{
	
	int a[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 2;
			a[i][j] = arr[i][j];
		}
	}
	int count = 0;
	/*int tmp;
	int i = 0;
	while (i < 20)
	{
		while (a[i] != 0)
			i++;
	
		if (check(a, i))
		{
			while (a[i] == 0)
			{
				i++;
				if ((i % 5) != 4)
					break;
			}
		}
		else
		{
			if (a[i + 5] != 0)
				count++;
		}
	count++;
	}*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				del_island(i, j);
				count++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << count;
	return 0;
}