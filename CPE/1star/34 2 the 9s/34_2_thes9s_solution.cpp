#include <iostream>
#include <string>

using namespace std;

int calculate(string &s, int& degree)
{

	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		sum += s[i] - '0';
	}
	
	//cout << to_string(sum) << endl;
	
	if (sum < 9) return 0;
	if (sum == 9) return ++degree;
	else 
	{
	
		return calculate (to_string(sum), ++degree);
		
	}
}

int main(void)
{	
	string s;
	
	int res = 0;
	
	while(getline(cin, s))
	{
		string temp_s = s;
		if (s == "0") break;
		
		int d = 0;
		res = calculate(s, d);
		
		if (res == 0)
		{
			cout << temp_s << " is not a multiple of 9.\n";
		}
		else
		{
			cout << temp_s << " is a multiple of 9 and has 9-degree " << res << ".\n";		
		}
	}
	
	

	return 0;
}