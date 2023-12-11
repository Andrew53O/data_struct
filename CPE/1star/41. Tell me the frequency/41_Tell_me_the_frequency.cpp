
#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(void)
{	
	bool firstTime = true;
    string s;
    while(getline(cin, s))
    {	
    	if(!firstTime)
    		cout << endl;
    	else
    		firstTime = false;
        map<char, int> mapA;
        for (int i = 0; i < s.size(); i++)
        {
           mapA[s.at(i)]++;
           
        }

        vector<pair<char, int>> v(mapA.begin(), mapA.end());

        sort(v.begin(), v.end(), [](pair<char, int>& a, pair<char, int>& b)
        {
           if (a.second == b.second)
                return a.first > b.first; // return bigger ASCII value
            else
                return a.second < b.second;
        });
        
        for(auto i : v)
        {
            cout << (int)i.first << " " << i.second << endl;
		}
    }    
    return 0;
}