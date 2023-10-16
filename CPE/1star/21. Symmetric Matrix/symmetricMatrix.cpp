#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; cin >> n;
	
	for (int y = 1; y <= n; y++)
	{
		char a, b; cin >> a >> b;
		int s; cin >> s;
		
		//cout << "size" << s << endl;
	
		int array[s*s];
		
		// the input
		for (int i = 0; i < (s *s); i++)
		{
			cin >> array[i];
		//	cout << array[i];
		}
		bool notsymmetric = false;
		int tail = (s*s) - 1;
		for (int i = 0; i < s; i++)
		{

			if(array[i] != array[tail] || (array[i] < 0 || array[tail] < 0))
			{
				cout << "Test #" << y << ": Non-symmetric." << endl; 
				notsymmetric = true;
				break;
			}
			tail--;
		
		}
		if(notsymmetric == false)
			cout << "Test #" << y << ": Symmetric." << endl; 
	}
		
	
	
	return 0;
}