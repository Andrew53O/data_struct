#include <iostream>
#include <vector>

using namespace std; 

int main(void)
{
	int n;
	cin >> n;
	
	int count = 1;
	bool isSy = true;
	char temp1, temp2;
	int value; 
	while(n--)
	{
		cin >> temp1 >> temp2 >> value; 
		
		isSy = true;
		
		vector<vector<int>> v(value, vector<int>(value));
		if (value > 1)
		{
			for (int i = 0; i < value; i++)
			{
				for (int j = 0; j < value; j++)
				{
					cin >> v[i][j];
					if (v[i][j] < 0) 
					{
						isSy = false; 
					}
				}
			}
			
			for (int i = 0; i < value && isSy; i++) 
			{
            	for (int j = 0; j < value; j++) 
            	{
                	if (v[i][j] != v[value - 1 - i][value - 1 - j]) 
                	{
                   		isSy = false;
                    	break;
                	}
            	}
        	}
		}
		else
		{
			isSy = true;
		}

	
		cout << "Test #" << count << ": ";
		if (isSy) cout << "Symmetric.\n";
		else cout << "Non-symmetric.\n";
		
		count++;
	}
	
	return 0;
}