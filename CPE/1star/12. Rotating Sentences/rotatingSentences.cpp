#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string s[100];
	
	int index = 0;
	int maxlength = 0;
	while(getline(cin, s[index]))
	{
	
		if (s[index].length() > maxlength)
			maxlength = s[index].length();
		
		index++;
	}
	for (int i = 0; i < maxlength; i++)
	{
		for (int j = index - 1; j >= 0; j--)
		{
			try
			{
				cout << s[j].at(i);
			}
			catch ( std::out_of_range)
			{
				if(j != 0)
					cout << " ";
			}
			// klo out of range tinggal print " " kelar
		}
		cout << endl;
		
	}
	
	return 0;
}