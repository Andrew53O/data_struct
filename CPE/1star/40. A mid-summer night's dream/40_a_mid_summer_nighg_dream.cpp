#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int n;
	
	while(cin >> n)
	{
		vector<int> v(n);
		double temp; 
		
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		
		int low_median;
		int high_median = 0;
		int count_median = 0;
		int C = 0;
		if (n % 2 == 1) // odd
		{
			low_median = v[n/2];
			count_median = count(v.begin(), v.end(), low_median);
			C = 1;
		}
		else
		{
			low_median = v[n/2 - 1];
			high_median = v[n/2];
			
			for (int x : v)
			    if (x >= low_median && x <= high_median)
			        count_median++;
			        
			C = high_median - low_median + 1; 
		}
		
		cout << low_median << " " << count_median << " " << C << endl;
		
		
		}
	
	return 0;
}