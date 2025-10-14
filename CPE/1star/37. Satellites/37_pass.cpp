#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> // for fixed setprecision

using namespace std;

const double PI = acos(-1.0);


int main(void)
{	
	double r = 6440; // kilometer
	double s, a; 
	string deg; 
	
	double chord, arc; 
	double radian;
	while(cin >> s >> a >> deg)
	{
		if(deg == "deg")
		{
			radian = a * (PI/180);
		}
		else if (deg == "min")
		{
			radian = (a/60) * (PI/180);
		}
		
		double total_radius = r + s; 
		
		// arc
		cout << fixed << setprecision(6) << total_radius * radian <<  " ";
		// chord 
		cout << fixed << 2 * sin(radian/2.0) * total_radius << endl;
		
	}

	return 0;
}