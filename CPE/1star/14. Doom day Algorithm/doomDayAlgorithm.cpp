#include <bits/stdc++.h>

using namespace std;

void compute(int m, int d)
{
	string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	
	int result;
	
	d = d % 7;
	switch(m)
	{
		case 1:
			result = d - 3;
			break;
		case 4:
			result = d - 4;
			break;
		case 5:
			result = d - 2;
			break;
		case 6:
			result = d - 6;
			break;
		case 7:
			result = d - 4;
			break;
		case 8:
			result = d - 1;
			break;
		case 9:
			result = d - 5;
			break;
		case 10:
			result = d - 3;
			break;
		case 11:
			result = d - 7;
			break;
		case 12:
			result = d - 5;
			break;
		default:
			result = d;
			
	}
	
	if (result >= 0)
	{
		cout << days[result] << endl;
	}
	else
	{
		cout << days[result + 7] << endl;
	}

	
}



int main(void)
{
	int n;
	cin >> n;
	
	while(n--)
	{
		int m, d;
		cin >> m >> d;
		compute(m, d);
		
	}
	
	

	return 0;
}