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
		
		// sort based on alphabetical order
		for (int i = 0; i < output.length() - 1; i++)
		{
			for (int j = i + 1; j < output.length() ;j++)
			{
				if (output[i] > output[j])
				{
					char temp = output[i];
					output[i] = output[j];
					output[j] = temp;
				}
			}
		}	
		

		cout << output << endl;
		
	}

	return 0;	
}