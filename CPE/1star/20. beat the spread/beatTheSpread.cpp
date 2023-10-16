#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	while(n--)
	{
		int a ,b; cin >> a >> b;
		bool found = false;
		bool out = false;
		for (int i = a; i >= b; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if((i + j ) == a && (i - j) == b)
				{
					cout << i << " " << j << endl;
					found = true;
					out = true;
					break;
				}
			}
			if(out) break;
			
		}
		if(!found)
			cout << "impossible" << endl;
	}
	
	return 0;
}