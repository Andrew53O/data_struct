#include <iostream>
#include <string>

using namespace std;


int decodeBinary(string s)
{
	int total = 0;
	int power = 1;
	for (int i = s.size() - 1; i >= 0; --i)
	{
		if(s[i] == '1') total += power;
		power*=2;
	}
	
	return total;
}


int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void)
{
    // IMPORTANT 2 LINES TO add, if not your code won't pass 
	ios_base::sync_with_stdio(false); // cut sync with c i/o
	cin.tie(NULL); // unties cin and cout


	int n; 
	cin >> n;
	
	int temp = n;
	string s1, s2;
	int res;
	while(n--)
	{
		cin >> s1;
		cin >> s2;
		
		int num1 = decodeBinary(s1);
		int num2 = decodeBinary(s2);
		
		res = gcd(num1, num2); 
		
		if (res == 1) 
		{
			cout << "Pair #" << temp - n << ": Love is not all you need!" << endl;
		}
		else
		{
			cout << "Pair #" << temp - n<< ": All you need is love!" << endl;
		}
	}
	
	return 0;
}