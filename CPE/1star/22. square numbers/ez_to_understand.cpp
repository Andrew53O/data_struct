#include <iostream>
#include <cmath> 

using namespace std;

int findInclusive(int a, int b)
{
	int count = 0; 
	int start = ceil(sqrt(a)); // get the closet starting point
	int n = a; 
	while( n <= b) // check up to range b inclusive
	{	
		start++;
		n = pow(start,2.0); // power of 2
		
		count++;
	}
	return count;
}

int main()
{
	int a, b; 
	while(cin >> a >> b)
	{
		if (a == 0) continue;
		cout << findInclusive(a,b) << endl;
	}

	return 0;
}