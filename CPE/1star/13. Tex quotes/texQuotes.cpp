#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string s, output;
	int count = 0;
	while(getline(cin, s))
	{
		output.clear();
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '"')
			{
				if (count % 2 == 0)
				{
					output+= "``";
				}	
				else
					output += "''";

				
				count++;	
			}
			else
				output+= s[i];
		}
		
		cout << output << endl;
	}	

}