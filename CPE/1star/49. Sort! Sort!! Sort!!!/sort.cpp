#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int modulo; 

bool is_odd(int n) {
    return (n % 2) != 0;
}

int get_mod(int a, int mod)
{	
	return a % mod; 
	// return ((a % mod) + mod) % mod;
}

bool moduloSorting(int a, int b)
{
	int mA = get_mod(a, modulo); 
	int mB = get_mod(b, modulo); 
	
	if(mA != mB) return mA < mB;
	else // same modulo
	{
		// a is odd
		if(is_odd(a))
		{
			// b is even 
			if (!is_odd(b)) 
			{
				// return odd first
				return true; // because odd must come first 
			}
			else // b is odd
			{
				return a > b;
			}
		
		}
		else // a is even
		{
			// b is odd
			if (is_odd(b)) 
			{
				// reutrn odd first
				return false;
			}
			else // b is even
			{
				return a < b;
			}
		}
	
	}

}

int main()
{
	int a ,mod; 
	cin >> a >> mod; 
	
	int fixed_a = a; 
	modulo = mod; 
	
	vector<int> nums; 
	
	int c; 
	while(a--)
	{
		cin >> c; 
		nums.push_back(c);
	}
	
	sort(nums.begin(), nums.end(), moduloSorting);
	
	cout << fixed_a << " " << mod << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums.at(i) << endl;
	}
	cout << "0 0" << endl;

	return 0;
}