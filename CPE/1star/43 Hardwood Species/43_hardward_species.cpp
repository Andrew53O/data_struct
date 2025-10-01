#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main(void)
{	
	bool firstTime = true;
    int n; cin >> n;
    
    string blank;
	getline(cin, blank);
	getline(cin, blank);    // read first blank 
    while(n--)
    {   
        float count = 0;
        map<string, int> res;
       
    
        while(getline(cin, blank) && !blank.empty())
        {
            res[blank]++;
            count++;
        }
        
        if (!firstTime)
        	cout <<endl;
		
		firstTime = false;
        for (auto i: res)
            cout << i.first << " " << fixed << setprecision(4) << (i.second) / count * 100 << endl; 
            
        
    }

    return 0;
}