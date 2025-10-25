#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> v;
	unordered_set<int> pairSum;
	
	int count = 1;
	int n;
	while(cin >> n)
	{	
		cout << "Case #" << count;
		int temp;
		bool isFirst = false;
		bool isB2 = true;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			if (temp < 0) 
			{
				isB2 = false;
				continue;
			}
			
			v.push_back(temp);
			isFirst = true;
			if(isFirst)
			{
				if(temp <= v[i -1]) 
				{
					isB2 = false;
					continue;
				}
			}
		}
		
		if (isB2)
		{
		
			for (int i = 0; i + 1 < v.size(); i++)
			{
				for (int j = i + 1; j < v.size(); j++)
				{
				auto check = pairSum.insert(v[i] + v[j]);
				
				if(check.second == false)
				{
					isB2 = false;
					break;
				}
				}
			
			}
		}
		
		if(isB2 == false)
		{
			cout << ": It is not a B2-Sequence.\n\n";
		}
		else
		{
			cout << ": It is a B2-Sequence.\n\n";
		}	
		
		
		
		// reset vector 
		v.clear();
		pairSum.clear();
		isFirst = true;
		
		count++;
	}
	return 0;
}