#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <utility>

using namespace std;

bool compareByFrequency(const pair<int, int>& a, const pair<int, int>& b) 
{
	// ascending
    if (a.first != b.first) {
        return a.first < b.first;
    }
    // decending
    return a.second > b.second; 
}

int main(void)
{
	int ARR[128] = {0}；
	bool isFirst = false;
	string s;
	while(getline(cin,s))
	{
		vector<pair<int, int>> freq;
		
		if (isFirst) cout << endl; // print the gap;
		isFirst = true;
	
		for (int i = 0; i < s.size(); i++)
		{
			int num = s[i];
			
			ARR[num]++;
		}
		
		for (int i = 127; i >= 32; i--)
		{
			if(ARR[i] != 0)
			{
				freq.push_back({ARR[i], i});
			}
		}
		
		sort(freq.begin(), freq.end(),compareByFrequency); 
		
		
		for (const auto& p : freq)
		{
			cout << p.second << " " << p.first << endl; 
		}
		
		fill(ARR, ARR + 128, 0); // reset array 
	}

	return 0;
}