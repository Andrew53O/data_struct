#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 1000001;
int memo[MAX_N] =  {0}; // solution using dynamic programming

long long calculate_length(long long n)
{
	// base case 
	if (n == 1) return 1;
	
	// check for memoization(cache)
	if (n < MAX_N && memo[n] != 0) return memo[n];
	 
	long long length = 0;
	if (n % 2 == 1) {length = 1 + calculate_length((3 * n) + 1);}
	else {length =  1 + calculate_length(n/2);}
	
	if (n < MAX_N) memo[n] = length;
	
	return length;
}


int main()
{
	int a, b; 

	while(cin >> a >> b)
	{
		int start = min(a,b);
		int end = max(a,b);
		long long length = 0;
		for (int i = start; i <= end; i++)
		{
			length = max(length, calculate_length(i));
		}
		
		cout << a << " " << b << " " << length << endl;
	}
	
	
	return 0;
}

