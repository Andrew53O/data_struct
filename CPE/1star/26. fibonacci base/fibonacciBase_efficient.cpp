#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n; cin >> n;
	while(n--)
	{
		int number;
		
		cin >> number;
		
		// get the value of fibo number until number
		int array[10000] = {};
		
		// known value
		array[0] = 1;
		array[1] = 2;
		int count = 2;
		
		// start from 2 because we have know that array[1] = 2
		int currentFib = 2;
		for (int i = 2; currentFib <= number; i++)
		{
			array[i] = array[i - 1] + array[i - 2];
			currentFib = array[i];
			
			count++;
		}
		
		// minus 1 because in above for loop is currentFib <= number
		for (int i = 0; i < count - 1; i++)
		{
		//	cout << array[i] << endl;
		}
		
		// output
		cout << number << " = ";
		for (int i = count -2; i >= 0; i--)
		{
			if(number - array[i] >= 0)
			{
				number = number -array[i];
				cout << "1";
			}
			else
				cout << "0";
		}
		cout << " (fib)" << endl;
		
		
	}
	
	return 0;
}