#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

#define PI acos(0.0) * 2.0


int main(void)
{
	double a, b;
	string s;
	
	while(cin >> a >> b >> s)
	{	
		
		if (s == "min")b/= 60.0;
		
		cout << fixed << setprecision(6) <<  2 * PI * (6440.0 + a) * (b/360) << " ";
		cout << fixed << setprecision(6) << 2 * (6440.0 + a) * (sin(b * PI / 180 /2)) << endl;
		 
	}
	
	return 0;
}