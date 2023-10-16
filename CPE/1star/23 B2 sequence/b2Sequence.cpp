#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n;
	int count = 1;
	while(cin >> n)
	{
		long long int array[101] = {};
		
		long long int check[10001] = {};
		bool flag = false;
		vector <int> v;
		for (int i = 0; i < n;  i++)
		{
			cin >> array[i];
			
		}
		cin.ignore();
		string s;
		getline(cin, s);
		
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				long long int sum = array[i] + array[j];
				if (check[sum] == 1)
				{
					cout << "Case #" << count++ << ": It is not a B2-Sequence." << endl;
					flag = true;
					break;
					
				}
				check[sum] = 1;
			}
			
			if(flag)
					break;
		}
		
		if(!flag)
		{
			cout << "Case #" << count++ << ": It is a B2-Sequence." << endl;
		}
		
	
		cout << endl;
		
	}
	
	
	return 0;
}	