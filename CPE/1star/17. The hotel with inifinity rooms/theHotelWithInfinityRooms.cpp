#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	long long int s;
	long long int d; 
	long long int plus;
	while(cin >> s >> d)
	{
		plus = s;
		while(d > s)
		{
			plus++;
			s += plus;
			//cout << "s->" << s << endl;
		}
		
		cout << plus << endl;
	}
	
	return 0;
}