#include <iostream>
using namespace std;

int main(void)
{
	long long int a, b; 
	while(cin >> a >> b)
	{
		long long int res = a + 1 ; 
		while(a < b)
		{
			a+= res;
			res++;
		}
		cout << res - 1 << endl;
	}
	return 0;
}