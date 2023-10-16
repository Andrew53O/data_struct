#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; cin >> n;

	
	for (int i = 0; i < n; i++)
	{
		int num;
		
		cin >> num;
		
		int binary[1000] = {};
		
		// for being used in hexadecimal
		int temp = num;
		
		// find the binary 
		int index = 0; 
		while(num)
		{
			binary[index] = num % 2;
			num = num/ 2;
			index++;
		}
		
		// count the 1's
		int b1 = 0;
		for (int k = 0; k < index; k++)
		{
			if (binary[k] == 1) b1++;
		}
		
		int index2 = 0;
		// array of count of 1's
		int hexadecima[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
		
		while(temp)
		{
			index2 += hexadecima[temp%10];
			temp/= 10;
		}
		
		cout << b1 << " " << index2 << endl;
	}
}