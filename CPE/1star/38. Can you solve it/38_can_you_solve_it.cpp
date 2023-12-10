#include <iostream>
using namespace std;

int main(void)
{
	int n; cin >> n;
	int cases = 1;
	while(n--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		int currentA = a + b;
		int countA = 0;
		
		// get the leading steps; 
		for (int i =  1; i <= currentA; i++)
		{
			countA += i;
		}
		
		// calculate the advanced
		countA += (currentA - b);
		
		
		int currentB = c + d;
		int countB = 0;
		
		for (int i = 1; i <= currentB; i++)
		{
			countB += i;
		}
		countB += (currentB - d);
		
		cout << "Case " << cases << ": " << countB - countA << endl;
		cases++;
	}

	return 0;
}