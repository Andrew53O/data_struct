#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	while(n--)
	{
		int num;
		cin >> num;
		
		vector<int> v(num);
		for (int i = 0; i < num; ++i)
		{
			cin >> v[i];
		}
		
		int count = 0;
        // bubble sort 
		for (int i = 0; i < num - 1; ++i)
		{
			for (int j = i + 1; j < num; ++j)
			{
				if (v[i] > v[j])
				{
					int temp = v[i];
					v[i] = v[j];
					v[j] = temp;
					count++;
				}
			}
		}
		
	//	for (auto &a: v)
	//		cout << a << endl;
		
		cout << "Optimal train swapping takes " << count << " swaps." << endl;
	}

	return 0;
}