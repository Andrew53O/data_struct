#include <iostream>

using namespace std;

int findCarry(int a, int b)
{
	int count = 0; 
	int carry = 0; 
	int nA = 0; int nB = 0;
	while(a!= 0 || b != 0)
	{
		nA = a % 10 ;
		a /= 10;
		
		nB = b % 10; 
		b /= 10;
		
		if (nA + nB + carry > 9)
		{
			count++; // one carry operation
			carry = 1; // add one to the front 
		}
		else
		{
			carry = 0;	
		}
	}
	
	return count;

}

int main(void)
{
	int a, b; 
	while(cin >> a >> b)
	{
		if (a == 0 && b == 0)break;
		
		int res = findCarry(a,b);
		
		if (res == 0 ) cout << "No carry operation." << endl;
		else if (res == 1) cout << "1 carry operation." << endl;
		else  cout << res << " carry operations." << endl;
		 
	}

	return 0;
}