#include <iostream>

using namespace std;


int oddSum(int a, int b)
{	
	int res = 0;
	
	
	
	int small = a; 
	int big = b; 
	if (a > b)
	{
		big = a; 
		small = b;
	}
	
	if(small %2 == 0) small +=1;
	if(big %2 == 0) big -=1;
	
	for (int j = small; j <= big; j+=2)
	{
		res += j;
	}

	return res;
}

int main()
{
	int in = 0;
	
	cin >> in;
	
	int a, b; 
	
	for (int i = 1; i <= in; i++)
	{
		cin >> a; 
		cin >> b; 
		
		
		cout << "Case " << i << ": " << oddSum(a, b) << endl;
	}
	
	return 0;
}


