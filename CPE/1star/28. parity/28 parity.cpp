#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	while(cin >> n)
	{
		if(n == 0) break;
		int binary[10000] = {};
		int count = 0;
		int one = 0;
		while(n)
		{
			if (n % 2 == 1) one++; // find how many 1's
			binary[count] = n % 2; // insert it
			n /= 2;
			count++;
		}
		
		cout << "The parity of ";
		for (int i = count - 1; i >= 0; i--) // reverse it
		{
			cout << binary[i];
		}
		
		
		cout << " is " << one << " (mod 2)." << endl;
		
		
		
		
	}

	return 0;
}