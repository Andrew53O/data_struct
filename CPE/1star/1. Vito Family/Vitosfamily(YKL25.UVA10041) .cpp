#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int row;
	int arow;
	cin >> row;
	
	for (int i = 0; i < row; i++)
	{
		cin >> arow;
		
		
		vector <int> v(arow);
		
		for (int i = 0; i < arow; i++)
		{
			cin >> v[i];
		}
		
		sort(v.begin(), v.end());
		int sum = 0;
		int left = 0;
		int right = arow - 1;
		
		// directly calculating the equivalent sum of pairwise differences from the sorted array.
		while(left <= right)
		{
			sum += v[right] - v[left];
			left++;
			right--;
		}
		
		cout << sum << endl;
	}
	

	
	return 0;
}