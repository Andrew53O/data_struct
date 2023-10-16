#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	long long int a, b;
	
	while(cin >> a >> b)
	{
		if (a == 0 && b == 0)	
			break;
			
		int count = 0;
		for (long long int i = 1; i <= b; ++i)
		{
			if ( i*i <= b && i *i >= a)
			{
				count++;
				cout << "i" << i << endl;
			}
		}
		
		cout << count << endl;
	}
	
	
	return 0;
}