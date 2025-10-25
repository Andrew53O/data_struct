#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std; 

int main()
{
	int n; 
	while(cin >> n)
	{
		vector<int> v = {};
		vector<bool> isComplete(n - 1,false);
		int num;
		for (int i = 0; i < n; i++)
		{
			cin >> num ; 
			v.push_back(num);
		}
		
		bool notjolly = false;
		int index;
		for (int i = 0; i + 1 < n; i++)
		{
			index = abs(v[i] - v[i + 1]) - 1;
			if (index >= 0 && index < n)
			{
				isComplete[index] = true;
			}
			else
			{
				notjolly = true;
				break;
			}
		}
		
		if (find(isComplete.begin(), isComplete.end(), false) == isComplete.end())
		{
			cout << "Jolly" << "\n";
		}
		else
		{
			cout << "Not jolly" << "\n";
		}
		
	
	}

	return 0;
}