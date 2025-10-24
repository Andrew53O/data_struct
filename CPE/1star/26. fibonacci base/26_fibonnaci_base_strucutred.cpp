#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> FIB = {1, 2};

void initFib(int max)
{		
	int f1 = 1;
	int f2 = 2; 
	int temp; 

	while(f1 + f2 <= max)
	{
		temp = f1 + f2;
		FIB.push_back(temp); 
		f1 = f2;
		f2 = temp;
	}
}

string convert2Fib(int n)
{
	string s = "";
	int size = FIB.size();
	bool start = false;
	
	for (int i = size - 1; i >= 0; i--)
	{
		if (FIB[i] <= n)
		{
			n -= FIB[i];
			s+= '1';
			
			// start flag for the first time
			start = true; 
		}
		else if (start)
		{
			s+= '0';
		}
	
	}
	
	return s;
}
	

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	initFib(100000000);
	int n;
	cin >> n;
	
	int num;
	while(n--)
	{
		cin >> num;
		
		cout << num << " = " << convert2Fib(num) << " (fib)" << "\n";
	
	}
	
	return 0;
}