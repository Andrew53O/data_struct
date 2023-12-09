#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, m;
	vector <int> v;
	
	while(cin >> n >> m)
	{
		v.push_back(n);
		bool isBoring = false;
		if(n == 1)
			isBoring = true;
		while (n != 1 && n > 1)
		{
			if (n % m != 0 || m == 1)
			{
				isBoring = true;
				break;
			}
			else
			{
				int temp = n / m;
				v.push_back(temp);
				

					
				n = temp;
			}
			
		}
		
		if(isBoring)
			cout << "Boring!";
		else
		{
		
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i];
			    if (i != v.size() - 1)
			        cout << " ";
			}
		}
		
		cout << endl;
		v.clear();
	}
	

	return 0;
}	