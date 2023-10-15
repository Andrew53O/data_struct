

//  I don't know why it failed when submit it!


#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	
	cin >> n;
	
	while(n--)
	{
		int m;
		double p;
	
		int k;
		cin >> m >> p >> k;
		
		double q = (1.0 - p);
		
		
		if (p == 0) cout << "0.0000" << endl;
		else 
		{
			double result = (pow(q, (double)k -1) * p) / (1- pow(q,(double) m));
			
			cout << fixed << setprecision(4) <<  result << endl;
		}
			
	}

	return 0;
}
