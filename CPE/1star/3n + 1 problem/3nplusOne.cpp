#include <iostream>

using namespace std;

int maxLength(int n, int length)
{
	//cout << "length paling atas -> " << length << endl;
	if (n == 1)
	{
		return ++length;
	}
	else
	{
		if (n % 2 == 1)
		{
	//	cout << "length -> " << length << endl;
			return maxLength(3 * n + 1, ++length);
		}	
		else
		{
			return maxLength(n/2, ++length);
		}
	}
}


int main(void)
{
	int left, right;
	
	while(cin >> left >> right)
	{
		int bigger = (left > right) ? left : right;
		int smaller = (bigger == left) ? right : left;
		
		int max = 0;
		for (int i = smaller; i <= bigger; i++)
		{
			int length = 0;
			int t = maxLength(i, length);
			if (t > max)
				max = t;
		
		}
		
		cout << left << " " << right << " " << max << endl;

		
	}

	return 0;
}

