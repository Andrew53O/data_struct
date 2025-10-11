#include <iostream>
#include <vector> 
#include <string>
using namespace std;

const int MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 1st to 7st January
string RESULT[7] = {"Saturday", "Sunday", "Monday", "Tuesday","Wednesday", "Thursday", "Friday"};

int main(void)
{
	int a; 
	cin >> a; 
	
	for (int i = 0; i < a; i++)
	{
		int m, d;
		cin >> m >> d;
		
		int month = 0;
		while(--m) month += MONTH[m-1];
		cout << RESULT[(month + d - 1) % 7] << endl;
	}
	
	return 0;
}