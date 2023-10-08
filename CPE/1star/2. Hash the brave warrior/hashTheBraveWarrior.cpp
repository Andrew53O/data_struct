#include <iostream>
#include <ios>
#include <limits>
#include <cstdlib>

using namespace std;
int main(void)
{
	long long int left, right;
	
	while(cin >> left >> right)
	{
		cout << llabs(right - left) << endl;
	}

	return 0;
}