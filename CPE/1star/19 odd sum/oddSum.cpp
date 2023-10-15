
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	int count = 1;
	
	cin >> n;
	while(n--)
	{
		int a, b;
		int result = 0;
		cin >> a >> b;
		
		for (int i = a; i <= b; i++)
		{
			if (i % 2 == 1)
			{
				result += i;
			}
		}
		
		cout << "Case " << count << ": " << result << endl; 
		count++;
	}
	

	return 0;
}