#include<iostream>

using namespace std;

<<<<<<< HEAD
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
=======
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
>>>>>>> 43064e76ff2e8987afe6cbd6461c884e09900e32
}

int main()
{
<<<<<<< HEAD
	
	int a[n][n];
	for (int i = 0; i < n; i++)
=======
	int arr[m][n];
	
	const int t = m * n;
	int a[t];
	int k = 0;
	for (int i = 0; i < m; i++)
>>>>>>> 43064e76ff2e8987afe6cbd6461c884e09900e32
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 2;
<<<<<<< HEAD
			a[i][j] = arr[i][j];
=======
			a[k + j] = arr[i][j];
>>>>>>> 43064e76ff2e8987afe6cbd6461c884e09900e32
		}
		k += n;
	}
	int count = 0;
<<<<<<< HEAD
	/*int tmp;
=======
>>>>>>> 43064e76ff2e8987afe6cbd6461c884e09900e32
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
<<<<<<< HEAD
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
=======
	
		i++;
	}
	
	for (int i = 0; i < m; i++)
>>>>>>> 43064e76ff2e8987afe6cbd6461c884e09900e32
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