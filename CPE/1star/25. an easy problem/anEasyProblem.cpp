#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string s;
	while(getline(cin, s))
	{
		int max = 1;
		int cBase = 0;
		long long int sum = 0;
		
		// get the maximum base
		for (int i =  0; i < s.size(); i++)
		{
			
			if(s[i] >= '0' && s[i] <= '9') cBase = s[i] - '0';
			
			if (s[i] >= 'A' && s[i] <= 'Z') cBase = s[i] -'A' + 10;
			
			if (s[i] >= 'a' && s[i] <= 'z') cBase = s[i] - 'a' + 36;
			
			sum+= cBase;
			
			if(cBase > max) max = cBase;
		}
		int i;
		
		// max + 1 becuase, if base 10, the digit is 0~9, so need to plus 1
		for (i = max + 1; i <= 62; i++)
		{
			if(sum % (i -1) == 0)
			{
				break;
			}
		}
		// if cannot divide the i will be 63
		if(i <=62) cout << i << endl;
		else
			cout << "such number is impossible!" << endl;
			
		
	}




}