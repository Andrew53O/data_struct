#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int x;
		
	while(cin >> x)
	{
		cin.ignore();
		
		string s;
		vector<int> v;
		int temp;
		long long int result = 0;
		
		getline(cin, s);
		
		stringstream ss;
		
		ss.clear();
		ss.str(s);
		
		while(ss >> temp)
		{
			v.push_back(temp);
		}
		int length = v.size() - 1; // i don't know why it need to -1
		
		for (int i = 0; i < length; i++)
		{
			result += v[i] * (length - i) * pow(x, length - i - 1);
		}
		
		cout << result << endl;
	}

	return 0;
}	