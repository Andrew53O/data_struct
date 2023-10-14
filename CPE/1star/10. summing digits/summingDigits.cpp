#include <bits/stdc++.h>

using namespace std;

long int compute(long int n)
{
	if (n < 10)
		return n;
	else
	{
		int mod = n % 10;
		n /= 10;
		
		return compute(mod + compute(n));
	}
		


}

int main(void)
{
	long int n;
		
	while(true)
	{
		cin >> n;
		if (n == 0) break;
		
		n = compute(n);
		
		cout << n << endl;
	}
	
	return 0;
}