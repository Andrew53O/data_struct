#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int test;
    while(cin >> test)
    {
        vector<int> v; 
        int num;
        while(test--)
        {
            cin >> num;
            v.push_back(num);
        }
         sort(v.begin(), v.end());

            int mid1 = v[v.size()/2];
            int mid2 = v[(v.size() -1) /2];
            int count = 0;

            for (int i = 0; i < v.size(); i++)
            {
                if(v[i] == mid1 || v[i] == mid2) count++;
            }

            cout << mid2 << " " << count << " " << mid1 - mid2 + 1 << endl;
    }
    return 0;
}