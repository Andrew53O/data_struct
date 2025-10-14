#include <bits/stdc++.h>

using namespace std;

int main(void)
{

	string one, two;
	
	// sort based on alphabetical order
	while(getline(cin, one))
	{
		getline(cin, two);
		
		string output;
		
	
		for (int i = 0; i < one.length(); i++)
		{
			if (one[i] == ' ')
				continue;
			for (int j = 0; j < two.length(); j++)
			{
				if(one[i] == two[j])
				{
					output += one[i];
					two.erase(j, 1);// erase at j for 1 length
					break;
				}
			}
		}
		
		if (output.length() == 0)
		{
			cout << endl;
			continue;
		}
		
		// sort based on alphabetical order using sort() function
		sort(output.begin(), output.end());
		

		cout << output << endl;
		
	}

	return 0;	
}