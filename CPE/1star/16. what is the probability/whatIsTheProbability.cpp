#include <iostream> 
#include <cmath>
#include <iomanip>
// #include <bits/stdc++.h>

using namespace std;

int main(void)
{	
	double s, n, p, l; 
	
	cin >> s; 
	
	for (int i = 0; i < s; i++)
	{
		cin >> n >> p >> l; 
		
		if (p == 0) 
		{
			cout << "0.0000" << endl;
			continue;
		}
		
		double calc1 = 1.0 / (1.0 - pow((1.0 - p), n));
		double calc2 = pow((1 - p), l - 1) * p; 
		
		cout << fixed << setprecision(4) << calc1 * calc2 << endl;
	
	}
	

	return 0;
}