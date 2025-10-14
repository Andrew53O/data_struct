#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

const string ALPHABET = "abcdefghijklmnopqrstuvwxyz"; 

string commonPermu(string &a, string &b)
{
	string res = "";
	
	unordered_map<char, int> alphabet1;
	unordered_map<char, int> alphabet2;
	
	// Init
    for (char c = 'a'; c <= 'z'; ++c)
    {
    	alphabet1[c] = 0;
    	alphabet2[c] = 0;
    }
    
    for (char c : a)
    {
    	alphabet1[c]++;
    }
    for (char c : b)
    {
    	alphabet2[c]++;
    }
    
    for (char i = 'a'; i <= 'z'; i++)
    {
    		int small = min(alphabet1[i], alphabet2[i]);
    		for(int j = 0; j < small; j++)
    		{
    			res += i;
    			 
    		}
    	
    }

	return res;
}

int main(void)
{
	string a, b;
	while(getline(cin, a) && getline(cin,b))
	{
		cout << commonPermu(a, b) << endl; 
	}
	
	return 0;
}