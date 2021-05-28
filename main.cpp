#include <iostream>


using namespace std;

const int s = 8;

int counter(int* par, int i)
{
	int count = 0;
	
	while (par[i] != -1)
	{
		i = par[i];
		count++;
	}

	return count;
}

int main()
{
	int par[s];
	for (int i = 0; i < s; i++)
	{
		cin >> par[i];
	}
	int height[s];
	int max = 0;
	for (int i = 0; i < s; i++)
	{
		height[i] = counter(par, i);
		if (max < height[i])
			max = height[i];
	}
	cout << max;
	return 0;
}