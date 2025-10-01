#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    	int n;
	while(cin >> n)
	{
        int ans = n;
        while(n >= 3)
        {   
            int left = n % 3;
            n /= 3;
            ans += n;
            n = n + left;
            cout << "n + left" << n << endl;
        }
        if ((n+ 1) % 3 == 0)
            ans++;
        cout << ans << endl;

		
	}
	return 0;
}