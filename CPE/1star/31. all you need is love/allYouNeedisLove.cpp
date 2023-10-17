#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b%a, a);

}

int main(void)
{
	int n; cin >> n;
	for (int i = 1; i <=n ;i++)
	{
		cout << "Pair #" << i << ": ";
		string num1; cin >> num1;
		string num2; cin >> num2;
		//cout << "eror" << endl;
		// checking invalid, leading zeros and one digit
		if (num1.size() <= 1 || num2.size() <= 1 || num1[0] == 0 || num2[0] == 0)
		{
			cout << "Love is not all you need!" << endl;
			continue;
		}
	//cout << "berhasil" << endl;
		
		int sum1 = 0;
		int sum2 = 0;
		
		int base = 1;
		// finding sum1 in decimal
		for (int j = num1.size() -1; j >= 0; j--)
		{
			sum1 += (num1[j] - '0') * base;
			base *= 2;
		}

	
		base = 1;
		for (int j = num2.size() -1; j >= 0; j--)
		{
			sum2 += (num2[j] - '0') * base;
			base *= 2;
		}
		
		// need to find gcd
		int ans = gcd(sum1, sum2);
		
		if (ans > 1)
		{
			cout << "All you need is love!" << endl;
		
		}
		else
		{
			cout << "Love is not all you need!" << endl;
		}
		
		
	}
}