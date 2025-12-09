#include  <iostream> 
// #include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

int main(void)
{	
	string s;
	
	vector<string> v; 
	
	int big = 0;
	
	while(getline(cin,s))
	{
		v.insert(v.begin(), s);
		
		int ne = s.length();
		
		if (ne > big)
		{
			big = ne;
		}
	}
	
	for (int j = 0; j < big; j++)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (j >= v[i].length())
			    cout << ' ';
			else
			    cout << v[i][j];
		}
		cout << endl;
	}


	return 0;
}
