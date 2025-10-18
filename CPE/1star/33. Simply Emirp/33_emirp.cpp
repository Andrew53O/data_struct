#include <iostream>

using namespace std;

bool isPrime(int n)
{
	if (n < 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0) return false;
	
	int count = 0;

    // check till square root of n 
	for (int i = 3; i * i <= n; i+= 2)
	{
		if (n % i == 0)
		{
			return false;
		}	
	}	
	
	return true;
}

int reverseNum(int n)
{
	int res = 0;
	
	
	while(n > 0)
	{	
		res *= 10;
		res += n % 10;
		n /= 10;
	}
	
	return res;
}

int main(void)
{
	int n; 
	
	while(cin >> n)
	{
		if (!isPrime(n)) cout << n << " is not prime." << endl;
		else if (isPrime(n))
		{
			if(isPrime(reverseNum(n)) && n != reverseNum(n)) cout << n << " is emirp." << endl;
			else cout << n << " is prime." << endl;
		}
	
	
	}
	
	return 0;
}