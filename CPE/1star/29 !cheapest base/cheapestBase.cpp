#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; cin >> n;
	int tempn = n;
	
	int cases = 1;
	while(n--)
	{
		int listCheapest[36] = {};
		int costs[36], min;
		for (int i = 0; i < 36; i++)
		{
			cin >> costs[i];
		}
		
		int m; cin >> m;
		
		cout << "Case " << cases++ << ":" << endl;
		while(m--)
		{
			int x; 
			cin >> x;
			
			
			min = 2000;
			
			int count = 0;
			
			int total, temp;
			
			
			for (int base = 2; base <= 36; base++)
			{
				total = 0;
				temp = x;
				
				// find cost for x every base
				while(temp)
				{
					total += costs[temp % base];
					temp /= base;
				}
				
				// make the lowest cost the first one,until it found
				if(total < min)
				{
					min = total;
					listCheapest[0] = base;
					count = 1;
					
				}
				else if (total == min) // other lowest cost
				{
					listCheapest[count++] = base;
				}
				
			}
			
		
			cout << "Cheapest base(s) for number " << x << ":";
			for (int i = 0; i < count; i++)
			{
				cout  <<" " << listCheapest[i];
			}
			cout << endl;
		}
		
		if (cases <= tempn) cout << endl;
		
		
	}
}