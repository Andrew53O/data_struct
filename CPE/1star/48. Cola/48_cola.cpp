#include <iostream>
#include <cmath>

using namespace std; 

int main()
{
	int in; 
	while(cin >> in)
	{
		cout << floor(in * 1.5) << endl;
	}
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m; 
	float temp;
	vector<int> res; 
	
	while(cin >> n >> m)
	{
		
		while(n > m)
		{
			temp = n / m;
			
			res.push_back(temp);
		}
		
		if (temp == 1)
		{
			for (int i = 0; i < res.size(); i++)
			{
				cout << res[i];
				if (i != res.size() -1) cout << " ";
			}
		}
		else
		{
			cout << "Boring!" << endl;
		}
	
	
	}
	
	return 0;
}