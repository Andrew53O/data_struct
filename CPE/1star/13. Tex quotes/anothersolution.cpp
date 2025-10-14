#include <iostream>
#include <string>

using namespace std;

string REPLACED[2] = {"``", "''"};

int main(void)
{
	string s; 
	int count = 0;
	while(getline(cin, s))
	{
		string res = "";
		for (char c: s)
		{
			if (c == '"')
			{
				res += REPLACED[count % 2];
				count++;
			}
			else 
			{
				res += c;
			}
		}
		cout << res << endl;
	}	
	return 0;
}