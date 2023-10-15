#include <bits/stdc++.h>

using namespace std;


bool compute(int *array, int size)
{
	int key[size] = {0};
	

	for (int i = 1; i < size; i++)
	{
		if ( abs(array[i - 1] - array[i]) < size)
		{
			if(key[abs(array[i - 1] - array[i])] == 1)
			{	
				return false;
			}
			else
			key[abs(array[i - 1] - array[i])] = 1;
		}
		else
			return false;
	}


	for (int i = 1; i < size; i++)
	{
		if(key[i] == 0)
			return false;
	}

	return true;
}

int main(void)
{
	int s;
	while(cin >> s)
	{
		int array[s];
		for (int i = 0; i < s; i++)
		{
			cin >> array[i];
		}


		if (compute(array, s))
		{
			cout << "Jolly" << endl;
		}
		else
			cout << "Not jolly" << endl;
	}
	
	return 0;
}