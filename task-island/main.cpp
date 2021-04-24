#include<iostream>

using namespace std;

const int m = 3, n = 3;

bool checknext(int* a, int k)
{
	bool b;
	if ((a[k] == 1) || ((k % n) == 4))
		return false;
	if (k != m * n - 1)
	{
		b = (a[k + 1] == 0);
		a[k] = k;
		a[k + 1] = k;
		return b;
	}
	else
		return false;
}
bool checkdown(int* a, int k)
{
	bool b;
	if ((a[k] == 1) || (k != m * (n - 1)))
		return false;
	else
	{
		b = (a[k + n] == 0);
		a[k] = k;
		a[k + n] = k;
		return b;
	}
}

int main()
{
	int arr[m][n];
	
	const int t = m * n;
	int a[t];
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 2;
			a[k + j] = arr[i][j];
		}
		k += n;
	}
	int count = 0;
	int i = 0;
	while (i < m*n)
	{
		while (a[i] != 1)
		{
			if (checknext(a, i) || checkdown(a, i))
				i++;
			else
			{
				count++;
				break;
			}
		}
	
		i++;
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	
	cout << count;
	return 0;
}