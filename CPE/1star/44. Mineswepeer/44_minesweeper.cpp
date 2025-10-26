#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(void)
{
	int w, h; 
	bool isfirst = false;
	char temp;
	int count = 1; 
	while(cin >> h >> w)
	{	
		
		if (h == 0 & w == 0) 
		{
			break;
		}
		else if(isfirst)
		{
			cout << endl;
		}
		
		isfirst = true;// for printing
	
		vector<vector<char>> arr(h, vector<char>(w, '0'));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0 ; j < w; j++)
			{
				 cin >> temp;
				 
				 if (temp == '*')
				 {
				 	// add count to 8 adjacent 
				 	
				 	for (int ni = i - 1; ni < i - 1 + 3; ni++)
				 	{
				 		for (int nj = j - 1; nj < j - 1 + 3; nj++)
				 		{
				 			if (ni >= 0 && ni < h && nj >= 0 && nj < w&& arr[ni][nj] != '*')
				 			{
				 				// cout << ni << " " << nj << endl;
				 				arr[ni][nj] = arr[ni][nj] - '0' + 1 + '0'; // convert to num then add
				 			}
				 			
				 		}
				 	}
				 	
				 	// overwrite at i j index
				 	arr[i][j] = temp;
				 }
			}
		}
		
		
		cout << "Field #" << count << ":" << endl;
		
		for (int i = 0 ; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cout << arr[i][j];
			}
			cout << endl;
		}
		
		
		count++;
		
	}
	
	return 0;
}