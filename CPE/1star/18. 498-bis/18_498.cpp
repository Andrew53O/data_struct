#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main(void)
{
	int n;
	
	while(cin >> n)
	{
		cin.ignore();

		string s;
		getline(cin, s);
	 	
	 	stringstream ss(s);
	 	
	 	deque<int> v; 
	 	int temp; 
	 	while(ss >> temp)
	 	{
	 		v.push_front(temp);
	 	}
	 	v.pop_front(); // doesn't use the last as it will being derivatived
	 	int res = 0;
	 	int power = 0;
	 	int multiply = 1;

        // divide to three parts, multiply, power and original n
	 	for (int i = 0; i < v.size(); i++)
	 	{
	 		res += (pow(n, power) * multiply * v[i]);
	 		power++;
	 		multiply++;
	 	}
	 	
	 	cout << res << endl;
	}

	return 0;
}