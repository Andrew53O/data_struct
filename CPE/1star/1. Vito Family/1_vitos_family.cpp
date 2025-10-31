#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    
    cin >> n;
    
    int c;
    while(n--)
    {
        cin >> c;
            
        vector<int> v;
        int temp;
        for(int i = 0; i < c; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        
        sort(v.begin(), v.end()); // Sort the positions
        
        // Find the median position
        int median_pos = v[(c - 1) / 2]; // This works for both even and odd c
        
        int res = 0; 
        // Calculate the sum of distances from the median to all positions
        for (int i = 0; i < c; i++)
        {
            res += abs(v[i] - median_pos); // Sum of distances to the median
        }
        
        cout << res << endl;
    }
    
    return 0;
}