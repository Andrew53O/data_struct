#include <iostream>

using namespace std;

int main()
{
	int cases, sum, diff; 
	cin >> cases;
	
	while(cases--)
	{
		cin >> sum >> diff;	
		
		if(diff > sum) 
		{
			cout << "impossible" << endl;
			continue;
		}
		
		for (int i = 0; i <= sum; i++)
		{
			if (i == sum) 
			{
				cout << "impossible"<< endl; // out of range 
				break;
			}
			// check if true
			if( i + (i + diff) == sum)
			{
				cout << sum - i << " " << i << endl;
				break;
			}
		}
		
		
	}
	

	return 0;
}
