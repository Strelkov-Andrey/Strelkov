#include<iostream>

using namespace std;

bool check(int* a, int k)
{
	return (a[k + 1] == 0) || (a[k + 5] == 0);
}

int main()
{
	int arr[5][5];
	int a[25];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = rand() % 2;
			a[i + j] = arr[i][j];
		}
	}
	int count = 0;
	int tmp;
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
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << count;
	return 0;
}