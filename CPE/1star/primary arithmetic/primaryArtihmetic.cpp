#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
	int left, right;
	
	while(cin >> left >> right)
	{
		if (left == 0 && right == 0)
		{
			break;
		}
		
		int operation = 0;
		
		int bigger = (left > right) ? left : right;
		int smaller = (left > right) ? right: left;
		int biggerSum, smallerSum;
		while(bigger)
		{
			biggerSum = bigger % 10;
			bigger /= 10;
			
			smallerSum = smaller % 10;
			smaller /= 10;
			
			if(biggerSum + smallerSum > 9)
			{
				operation++;
				smaller++; // can also add bigger
			}
			
		}
		
		if(operation != 0)
		{
			cout << operation << " carry operation" ;
			if (operation != 1)
			{
				cout << "s" ;
			}
			cout << "." << endl;
		}
		else
		{
			cout << "No carry operation." << endl;
		}
	}

	return 0;
}