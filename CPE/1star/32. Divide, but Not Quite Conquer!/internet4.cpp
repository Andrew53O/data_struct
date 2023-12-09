
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n, m;
    while (cin >> n >> m){
        vector <int> ans;
        bool boring = false;
        if (n == 0 || m == 0 || m == 1) boring = true;
        else {
            ans.push_back(n);
            while (n > 1) {
                if (n%m == 0){
                    n /= m;
                    ans.push_back(n);
                } else {
                    boring = true;
                    break;
                }
            }
        }
        if (boring) cout << "Boring!\n";
        else {
            for (int i = 0; i < ans.size();i++) 
            {
            	cout << ans[i];
            	if (i != ans.size() - 1)
            	{	
            	 cout << " ";
            	}
            
           
            }
             cout << "\n";
        }
    }
    return 0;
}