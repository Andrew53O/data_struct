#include <iostream>
#include <string> 
#include <algorithm>

using namespace std;

int main(void)
{	
	string input;
	
	while(cin >> input)
	{
		if (input =="0") break;
		
		reverse(input.begin(), input.end()); // to make it easier to calculate
		
		int res = 0; 
		for (int i = 0; i < input.size(); i++)
		{
			if(i % 2 == 0) res += input[i] - '0';
			else res -= input[i] - '0';
		
		}
		reverse(input.begin(), input.end());
		cout << input << " is";
		if (res % 11 != 0) 
		{
			cout << " not";
		}
		cout <<  " a multiple of 11." << endl;
	}

	return 0;
}